/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vmod.vcc and run vmod.py instead
 */

struct sess;
struct VCL_conf;
struct vmod_priv;

void vmod_log_beresp(struct sess *);
void vmod_log_obj_body(struct sess *);
void vmod_log_client_req(struct sess *);
int init_function(struct vmod_priv *, const struct VCL_conf *);
extern const void * const Vmod_Id;
