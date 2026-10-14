struct {const char *name; void *value; } modsyms_preopserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_preopserv_main},
{"module_version",&module_version_preopserv_main},
{"module_config",module_config_preopserv_main},
{"init_module",init_module_preopserv_main},
{"exit_module",exit_module_preopserv_main},
{0}};
