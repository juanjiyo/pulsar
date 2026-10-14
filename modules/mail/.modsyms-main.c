struct {const char *name; void *value; } modsyms_mail_main[] = {
{"_this_module_ptr",&_this_module_ptr_mail_main},
{"module_version",&module_version_mail_main},
{"module_config",module_config_mail_main},
{"init_module",init_module_mail_main},
{"exit_module",exit_module_mail_main},
{"low_send",&low_send},
{"low_abort",&low_abort},
{"sendmail", sendmail},
{"send_finished", send_finished},
{0}};
