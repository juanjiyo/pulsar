struct {const char *name; void *value; } modsyms_httpd_main[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_main},
{"module_version",&module_version_httpd_main},
{"module_config",module_config_httpd_main},
{"init_module",init_module_httpd_main},
{"exit_module",exit_module_httpd_main},
{0}};
