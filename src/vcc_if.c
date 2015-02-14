/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vmod.vcc and run vmod.py instead
 */

#include "vrt.h"
#include "vcc_if.h"
#include "vmod_abi.h"


typedef void td_logging_log_beresp(struct sess *);
typedef void td_logging_log_obj_body(struct sess *);
typedef void td_logging_log_client_req(struct sess *);

const char Vmod_Name[] = "logging";
const struct Vmod_Func_logging {
	td_logging_log_beresp	*log_beresp;
	td_logging_log_obj_body	*log_obj_body;
	td_logging_log_client_req	*log_client_req;
	vmod_init_f	*_init;
} Vmod_Func = {
	vmod_log_beresp,
	vmod_log_obj_body,
	vmod_log_client_req,
	init_function,
};

const int Vmod_Len = sizeof(Vmod_Func);

const char Vmod_Proto[] =
	"typedef void td_logging_log_beresp(struct sess *);\n"
	"typedef void td_logging_log_obj_body(struct sess *);\n"
	"typedef void td_logging_log_client_req(struct sess *);\n"
	"\n"
	"struct Vmod_Func_logging {\n"
	"	td_logging_log_beresp	*log_beresp;\n"
	"	td_logging_log_obj_body	*log_obj_body;\n"
	"	td_logging_log_client_req	*log_client_req;\n"
	"	vmod_init_f	*_init;\n"
	"} Vmod_Func_logging;\n"
	;

const char * const Vmod_Spec[] = {
	"logging.log_beresp\0Vmod_Func_logging.log_beresp\0VOID\0",
	"logging.log_obj_body\0Vmod_Func_logging.log_obj_body\0VOID\0",
	"logging.log_client_req\0Vmod_Func_logging.log_client_req\0VOID\0",
	"INIT\0Vmod_Func_logging._init",
	0
};
const char Vmod_Varnish_ABI[] = VMOD_ABI_Version;
const void * const Vmod_Id = &Vmod_Id;

