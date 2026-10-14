struct {const char *name; void *value; } modsyms_misc_xml_export[] = {
{"_this_module_ptr",&_this_module_ptr_misc_xml_export},
{"module_version",&module_version_misc_xml_export},
{"module_config",module_config_misc_xml_export},
{"init_module",init_module_misc_xml_export},
{"exit_module",exit_module_misc_xml_export},
{"xml_export", xml_export},
{0}};
