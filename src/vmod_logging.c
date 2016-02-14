#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

#include "vqueue.h"
#include "vrt.h"
#include "vsha256.h"
#include "bin/varnishd/cache.h"
#include "bin/varnishd/stevedore.h"

#include "vcc_if.h"

struct buf_t {
    char *ptr;
    size_t len;
    size_t size;
};

#define BUF_GROW(buf) do { \
    (buf)->size *= 2; \
    (buf)->ptr = realloc((buf)->ptr, (buf)->size); \
    AN((buf)->ptr); \
} while (0)

#define BUF_RESERVE(buf, n) do { \
    while ((buf)->size <= (buf)->len + (n)) { \
    BUF_GROW(buf); \
    } \
} while (0)

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
        openlog(NULL, (LOG_CONS|LOG_NDELAY|LOG_PID), LOG_LOCAL4); 
	return (0);
}


const char *
_obj_body(struct sess *sp){
    struct storage *st;
    struct buf_t buf = {NULL, 0, 4 * 1024};
    BUF_GROW(&buf);
    CHECK_OBJ_NOTNULL(sp, SESS_MAGIC);

    /* Place beresp body in buf */
    if (!sp->obj->gziped) {
        //printf("obj is not gziped\n");
        VTAILQ_FOREACH(st, &sp->obj->store, list) {
            CHECK_OBJ_NOTNULL(sp, SESS_MAGIC);
            CHECK_OBJ_NOTNULL(st, STORAGE_MAGIC);
            BUF_RESERVE(&buf, st->len);
            memcpy(buf.ptr + buf.len, st->ptr, st->len);
            buf.len += st->len;
        }
    } else {
        //printf("obj is gzipped\n");
        struct vgz *vg;
        char obuf[params->gzip_stack_buffer];
        ssize_t obufl = 0;
        const void *dp;
        size_t dl;
        vg = VGZ_NewUngzip(sp, "U D -");
        VTAILQ_FOREACH(st, &sp->obj->store, list) {
            CHECK_OBJ_NOTNULL(sp, SESS_MAGIC);
            CHECK_OBJ_NOTNULL(st, STORAGE_MAGIC);
            BUF_RESERVE(&buf, st->len * 2);
            VGZ_Ibuf(vg, st->ptr, st->len);          
            do {
                VGZ_Obuf(vg, buf.ptr + buf.len, buf.size - buf.len);
                if (buf.len < buf.size) {
                    VGZ_Gunzip(vg, &dp, &dl);
                    buf.len += dl;
                } else {
                    BUF_RESERVE(&buf, st->len);
                }
            } while (!VGZ_IbufEmpty(vg));
        }
        VGZ_Destroy(&vg);
    }
    BUF_RESERVE(&buf, 1);
    buf.ptr[buf.len] = '\0';
    //printf("Printing obj:\n%s",buf.ptr);
    return buf.ptr;
    //syslog((LOG_LOCAL0|LOG_INFO), "ResponseBody: %s\n", buf.ptr);
    //free(buf.ptr);
}


void vmod_log_obj_body(struct sess *sp, const char *str){
    const char *obj_body_str = _obj_body(sp);
    syslog((LOG_LOCAL4|LOG_INFO), "%s %s", str, obj_body_str);
    free((void *)obj_body_str);
}


