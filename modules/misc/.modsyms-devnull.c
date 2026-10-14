struct {const char *name; void *value; } modsyms_misc_devnull[] = {
{"_this_module_ptr",&_this_module_ptr_misc_devnull},
{"module_version",&module_version_misc_devnull},
{"module_config",module_config_misc_devnull},
{"init_module",init_module_misc_devnull},
{"exit_module",exit_module_misc_devnull},
{0}};
