struct {const char *name; void *value; } modsyms_httpd_redirect[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_redirect},
{"module_version",&module_version_httpd_redirect},
{"module_config",module_config_httpd_redirect},
{"init_module",init_module_httpd_redirect},
{"exit_module",exit_module_httpd_redirect},
{0}};
