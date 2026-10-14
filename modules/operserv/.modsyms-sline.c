struct {const char *name; void *value; } modsyms_operserv_sline[] = {
{"_this_module_ptr",&_this_module_ptr_operserv_sline},
{"module_version",&module_version_operserv_sline},
{"module_config",module_config_operserv_sline},
{"init_module",init_module_operserv_sline},
{"exit_module",exit_module_operserv_sline},
{"create_sline", create_sline},
{0}};
