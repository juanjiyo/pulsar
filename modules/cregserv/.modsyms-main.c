struct {const char *name; void *value; } modsyms_cregserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_cregserv_main},
{"module_version",&module_version_cregserv_main},
{"module_config",module_config_cregserv_main},
{"init_module",init_module_cregserv_main},
{"exit_module",exit_module_cregserv_main},
{"add_creginfo", add_creginfo},
{"del_creginfo", del_creginfo},
{"get_creginfo", get_creginfo},
{"put_creginfo", put_creginfo},
{"first_creginfo", first_creginfo},
{"next_creginfo", next_creginfo},
{0}};
