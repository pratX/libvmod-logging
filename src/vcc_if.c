/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vmod.vcc and run vmod.py instead
 */

#include "vrt.h"
#include "vcc_if.h"
#include "vmod_abi.h"


typedef void td_example_log_all(struct sess *);

const char Vmod_Name[] = "example";
const struct Vmod_Func_example {
	td_example_log_all	*log_all;
	vmod_init_f	*_init;
} Vmod_Func = {
	vmod_log_all,
	init_function,
};

const int Vmod_Len = sizeof(Vmod_Func);

const char Vmod_Proto[] =
	"typedef void td_example_log_all(struct sess *);\n"
	"\n"
	"struct Vmod_Func_example {\n"
	"	td_example_log_all	*log_all;\n"
	"	vmod_init_f	*_init;\n"
	"} Vmod_Func_example;\n"
	;

const char * const Vmod_Spec[] = {
	"example.log_all\0Vmod_Func_example.log_all\0VOID\0",
	"INIT\0Vmod_Func_example._init",
	0
};
const char Vmod_Varnish_ABI[] = VMOD_ABI_Version;
const void * const Vmod_Id = &Vmod_Id;

