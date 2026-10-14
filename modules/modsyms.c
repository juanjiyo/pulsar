struct {const char *name; void *value; } modsyms_adminserv_elines[] = {
{"_this_module_ptr",&_this_module_ptr_adminserv_elines},
{"module_version",&module_version_adminserv_elines},
{"module_config",module_config_adminserv_elines},
{"init_module",init_module_adminserv_elines},
{"exit_module",exit_module_adminserv_elines},
{0}};
struct {const char *name; void *value; } modsyms_adminserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_adminserv_main},
{"module_version",&module_version_adminserv_main},
{"module_config",module_config_adminserv_main},
{"init_module",init_module_adminserv_main},
{"exit_module",exit_module_adminserv_main},
{0}};
struct {const char *name; void *value; } modsyms_adminserv_sessions[] = {
{"_this_module_ptr",&_this_module_ptr_adminserv_sessions},
{"module_version",&module_version_adminserv_sessions},
{"module_config",module_config_adminserv_sessions},
{"init_module",init_module_adminserv_sessions},
{"exit_module",exit_module_adminserv_sessions},
{0}};
struct {const char *name; void *value; } modsyms_chanserv_access_levels[] = {
{"_this_module_ptr",&_this_module_ptr_chanserv_access_levels},
{"module_version",&module_version_chanserv_access_levels},
{"module_config",module_config_chanserv_access_levels},
{"init_module",init_module_chanserv_access_levels},
{"exit_module",exit_module_chanserv_access_levels},
{0}};
struct {const char *name; void *value; } modsyms_chanserv_access_xop[] = {
{"_this_module_ptr",&_this_module_ptr_chanserv_access_xop},
{"module_version",&module_version_chanserv_access_xop},
{"module_config",module_config_chanserv_access_xop},
{"init_module",init_module_chanserv_access_xop},
{"exit_module",exit_module_chanserv_access_xop},
{0}};
struct {const char *name; void *value; } modsyms_chanserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_chanserv_main},
{"module_version",&module_version_chanserv_main},
{"module_config",module_config_chanserv_main},
{"init_module",init_module_chanserv_main},
{"exit_module",exit_module_chanserv_main},
{"s_ChanServ",&s_ChanServ},
{"add_channelinfo", add_channelinfo},
{"del_channelinfo", del_channelinfo},
{"get_channelinfo", get_channelinfo},
{"put_channelinfo", put_channelinfo},
{"first_channelinfo", first_channelinfo},
{"next_channelinfo", next_channelinfo},
{"levelinfo", levelinfo},
{"get_ci_level", get_ci_level},
{"check_access", check_access},
{"check_access_if_idented", check_access_if_idented},
{"check_access_cmd", check_access_cmd},
{"new_channelinfo", new_channelinfo},
{"free_channelinfo", free_channelinfo},
{"reset_levels", reset_levels},
{"check_channel_limit", check_channel_limit},
{0}};
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
struct {const char *name; void *value; } modsyms_database_standard[] = {
{"_this_module_ptr",&_this_module_ptr_database_standard},
{"module_version",&module_version_database_standard},
{"module_config",module_config_database_standard},
{"init_module",init_module_database_standard},
{"exit_module",exit_module_database_standard},
{0}};
struct {const char *name; void *value; } modsyms_database_version4[] = {
{"_this_module_ptr",&_this_module_ptr_database_version4},
{"module_version",&module_version_database_version4},
{"module_config",module_config_database_version4},
{"init_module",init_module_database_version4},
{"exit_module",exit_module_database_version4},
{0}};
struct {const char *name; void *value; } modsyms_ddbserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_ddbserv_main},
{"module_version",&module_version_ddbserv_main},
{"module_config",module_config_ddbserv_main},
{"init_module",init_module_ddbserv_main},
{"exit_module",exit_module_ddbserv_main},
{0}};
struct {const char *name; void *value; } modsyms_encryption_md5[] = {
{"_this_module_ptr",&_this_module_ptr_encryption_md5},
{"module_version",&module_version_encryption_md5},
{"module_config",module_config_encryption_md5},
{"init_module",init_module_encryption_md5},
{"exit_module",exit_module_encryption_md5},
{0}};
struct {const char *name; void *value; } modsyms_encryption_unix_crypt[] = {
{"_this_module_ptr",&_this_module_ptr_encryption_unix_crypt},
{"module_version",&module_version_encryption_unix_crypt},
{"module_config",module_config_encryption_unix_crypt},
{"init_module",init_module_encryption_unix_crypt},
{"exit_module",exit_module_encryption_unix_crypt},
{0}};
struct {const char *name; void *value; } modsyms_globalserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_globalserv_main},
{"module_version",&module_version_globalserv_main},
{"module_config",module_config_globalserv_main},
{"init_module",init_module_globalserv_main},
{"exit_module",exit_module_globalserv_main},
{0}};
struct {const char *name; void *value; } modsyms_hostserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_hostserv_main},
{"module_version",&module_version_hostserv_main},
{"module_config",module_config_hostserv_main},
{"init_module",init_module_hostserv_main},
{"exit_module",exit_module_hostserv_main},
{0}};
struct {const char *name; void *value; } modsyms_httpd_auth_ip[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_auth_ip},
{"module_version",&module_version_httpd_auth_ip},
{"module_config",module_config_httpd_auth_ip},
{"init_module",init_module_httpd_auth_ip},
{"exit_module",exit_module_httpd_auth_ip},
{0}};
struct {const char *name; void *value; } modsyms_httpd_auth_password[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_auth_password},
{"module_version",&module_version_httpd_auth_password},
{"module_config",module_config_httpd_auth_password},
{"init_module",init_module_httpd_auth_password},
{"exit_module",exit_module_httpd_auth_password},
{0}};
struct {const char *name; void *value; } modsyms_httpd_dbaccess[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_dbaccess},
{"module_version",&module_version_httpd_dbaccess},
{"module_config",module_config_httpd_dbaccess},
{"init_module",init_module_httpd_dbaccess},
{"exit_module",exit_module_httpd_dbaccess},
{0}};
struct {const char *name; void *value; } modsyms_httpd_debug[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_debug},
{"module_version",&module_version_httpd_debug},
{"module_config",module_config_httpd_debug},
{"init_module",init_module_httpd_debug},
{"exit_module",exit_module_httpd_debug},
{0}};
struct {const char *name; void *value; } modsyms_httpd_main[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_main},
{"module_version",&module_version_httpd_main},
{"module_config",module_config_httpd_main},
{"init_module",init_module_httpd_main},
{"exit_module",exit_module_httpd_main},
{0}};
struct {const char *name; void *value; } modsyms_httpd_redirect[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_redirect},
{"module_version",&module_version_httpd_redirect},
{"module_config",module_config_httpd_redirect},
{"init_module",init_module_httpd_redirect},
{"exit_module",exit_module_httpd_redirect},
{0}};
struct {const char *name; void *value; } modsyms_httpd_top_page[] = {
{"_this_module_ptr",&_this_module_ptr_httpd_top_page},
{"module_version",&module_version_httpd_top_page},
{"module_config",module_config_httpd_top_page},
{"init_module",init_module_httpd_top_page},
{"exit_module",exit_module_httpd_top_page},
{0}};
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
struct {const char *name; void *value; } modsyms_mail_sendmail[] = {
{"_this_module_ptr",&_this_module_ptr_mail_sendmail},
{"module_version",&module_version_mail_sendmail},
{"module_config",module_config_mail_sendmail},
{"init_module",init_module_mail_sendmail},
{"exit_module",exit_module_mail_sendmail},
{0}};
struct {const char *name; void *value; } modsyms_mail_smtp[] = {
{"_this_module_ptr",&_this_module_ptr_mail_smtp},
{"module_version",&module_version_mail_smtp},
{"module_config",module_config_mail_smtp},
{"init_module",init_module_mail_smtp},
{"exit_module",exit_module_mail_smtp},
{0}};
struct {const char *name; void *value; } modsyms_memoserv_forward[] = {
{"_this_module_ptr",&_this_module_ptr_memoserv_forward},
{"module_version",&module_version_memoserv_forward},
{"module_config",module_config_memoserv_forward},
{"init_module",init_module_memoserv_forward},
{"exit_module",exit_module_memoserv_forward},
{0}};
struct {const char *name; void *value; } modsyms_memoserv_ignore[] = {
{"_this_module_ptr",&_this_module_ptr_memoserv_ignore},
{"module_version",&module_version_memoserv_ignore},
{"module_config",module_config_memoserv_ignore},
{"init_module",init_module_memoserv_ignore},
{"exit_module",exit_module_memoserv_ignore},
{0}};
struct {const char *name; void *value; } modsyms_memoserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_memoserv_main},
{"module_version",&module_version_memoserv_main},
{"module_config",module_config_memoserv_main},
{"init_module",init_module_memoserv_main},
{"exit_module",exit_module_memoserv_main},
{0}};
struct {const char *name; void *value; } modsyms_misc_devnull[] = {
{"_this_module_ptr",&_this_module_ptr_misc_devnull},
{"module_version",&module_version_misc_devnull},
{"module_config",module_config_misc_devnull},
{"init_module",init_module_misc_devnull},
{"exit_module",exit_module_misc_devnull},
{0}};
struct {const char *name; void *value; } modsyms_misc_helpserv[] = {
{"_this_module_ptr",&_this_module_ptr_misc_helpserv},
{"module_version",&module_version_misc_helpserv},
{"module_config",module_config_misc_helpserv},
{"init_module",init_module_misc_helpserv},
{"exit_module",exit_module_misc_helpserv},
{0}};
struct {const char *name; void *value; } modsyms_misc_xml_export[] = {
{"_this_module_ptr",&_this_module_ptr_misc_xml_export},
{"module_version",&module_version_misc_xml_export},
{"module_config",module_config_misc_xml_export},
{"init_module",init_module_misc_xml_export},
{"exit_module",exit_module_misc_xml_export},
{"xml_export", xml_export},
{0}};
struct {const char *name; void *value; } modsyms_misc_xml_import[] = {
{"_this_module_ptr",&_this_module_ptr_misc_xml_import},
{"module_version",&module_version_misc_xml_import},
{"module_config",module_config_misc_xml_import},
{"init_module",init_module_misc_xml_import},
{"exit_module",exit_module_misc_xml_import},
{0}};
struct {const char *name; void *value; } modsyms_nickserv_access[] = {
{"_this_module_ptr",&_this_module_ptr_nickserv_access},
{"module_version",&module_version_nickserv_access},
{"module_config",module_config_nickserv_access},
{"init_module",init_module_nickserv_access},
{"exit_module",exit_module_nickserv_access},
{0}};
struct {const char *name; void *value; } modsyms_nickserv_autojoin[] = {
{"_this_module_ptr",&_this_module_ptr_nickserv_autojoin},
{"module_version",&module_version_nickserv_autojoin},
{"module_config",module_config_nickserv_autojoin},
{"init_module",init_module_nickserv_autojoin},
{"exit_module",exit_module_nickserv_autojoin},
{0}};
struct {const char *name; void *value; } modsyms_nickserv_link[] = {
{"_this_module_ptr",&_this_module_ptr_nickserv_link},
{"module_version",&module_version_nickserv_link},
{"module_config",module_config_nickserv_link},
{"init_module",init_module_nickserv_link},
{"exit_module",exit_module_nickserv_link},
{0}};
struct {const char *name; void *value; } modsyms_nickserv_mail_auth[] = {
{"_this_module_ptr",&_this_module_ptr_nickserv_mail_auth},
{"module_version",&module_version_nickserv_mail_auth},
{"module_config",module_config_nickserv_mail_auth},
{"init_module",init_module_nickserv_mail_auth},
{"exit_module",exit_module_nickserv_mail_auth},
{0}};
struct {const char *name; void *value; } modsyms_nickserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_nickserv_main},
{"module_version",&module_version_nickserv_main},
{"module_config",module_config_nickserv_main},
{"init_module",init_module_nickserv_main},
{"exit_module",exit_module_nickserv_main},
{"s_NickServ",&s_NickServ},
{"add_nickinfo", add_nickinfo},
{"del_nickinfo", del_nickinfo},
{"get_nickinfo", get_nickinfo},
{"put_nickinfo", put_nickinfo},
{"first_nickinfo", first_nickinfo},
{"next_nickinfo", next_nickinfo},
{"add_nickgroupinfo", add_nickgroupinfo},
{"del_nickgroupinfo", del_nickgroupinfo},
{"get_nickgroupinfo", get_nickgroupinfo},
{"put_nickgroupinfo", put_nickgroupinfo},
{"first_nickgroupinfo", first_nickgroupinfo},
{"next_nickgroupinfo", next_nickgroupinfo},
{"new_nickinfo", new_nickinfo},
{"free_nickinfo", free_nickinfo},
{"new_nickgroupinfo", new_nickgroupinfo},
{"free_nickgroupinfo", free_nickgroupinfo},
{"_get_ngi", _get_ngi},
{"_get_ngi_id", _get_ngi_id},
{"has_identified_nick", has_identified_nick},
{0}};
struct {const char *name; void *value; } modsyms_operserv_akill[] = {
{"_this_module_ptr",&_this_module_ptr_operserv_akill},
{"module_version",&module_version_operserv_akill},
{"module_config",module_config_operserv_akill},
{"init_module",init_module_operserv_akill},
{"exit_module",exit_module_operserv_akill},
{"EnableExclude",&EnableExclude},
{"create_akill", create_akill},
{0}};
struct {const char *name; void *value; } modsyms_operserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_operserv_main},
{"module_version",&module_version_operserv_main},
{"module_config",module_config_operserv_main},
{"init_module",init_module_operserv_main},
{"exit_module",exit_module_operserv_main},
{"s_OperServ",&s_OperServ},
{"ServicesRoot",&ServicesRoot},
{"get_operserv_data", get_operserv_data},
{"put_operserv_data", put_operserv_data},
{"is_services_root", is_services_root},
{"is_services_admin", is_services_admin},
{"is_services_oper", is_services_oper},
{"nick_is_services_admin", nick_is_services_admin},
{"nick_is_services_oper", nick_is_services_oper},
{"add_maskdata", add_maskdata},
{"del_maskdata", del_maskdata},
{"get_maskdata", get_maskdata},
{"get_matching_maskdata", get_matching_maskdata},
{"put_maskdata", put_maskdata},
{"first_maskdata", first_maskdata},
{"next_maskdata", next_maskdata},
{"maskdata_count", maskdata_count},
{"get_exception_by_num", get_exception_by_num},
{"get_eline_by_num", get_eline_by_num},
{"move_exception", move_exception},
{0}};
struct {const char *name; void *value; } modsyms_operserv_sline[] = {
{"_this_module_ptr",&_this_module_ptr_operserv_sline},
{"module_version",&module_version_operserv_sline},
{"module_config",module_config_operserv_sline},
{"init_module",init_module_operserv_sline},
{"exit_module",exit_module_operserv_sline},
{"create_sline", create_sline},
{0}};
struct {const char *name; void *value; } modsyms_preopserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_preopserv_main},
{"module_version",&module_version_preopserv_main},
{"module_config",module_config_preopserv_main},
{"init_module",init_module_preopserv_main},
{"exit_module",exit_module_preopserv_main},
{0}};
struct {const char *name; void *value; } modsyms_protocol_hispano_p9[] = {
{"_this_module_ptr",&_this_module_ptr_protocol_hispano_p9},
{"module_version",&module_version_protocol_hispano_p9},
{"module_config",module_config_protocol_hispano_p9},
{"init_module",init_module_protocol_hispano_p9},
{"exit_module",exit_module_protocol_hispano_p9},
{0}};
struct {const char *name; void *value; } modsyms_statserv_main[] = {
{"_this_module_ptr",&_this_module_ptr_statserv_main},
{"module_version",&module_version_statserv_main},
{"module_config",module_config_statserv_main},
{"init_module",init_module_statserv_main},
{"exit_module",exit_module_statserv_main},
{"add_serverstats", add_serverstats},
{"del_serverstats", del_serverstats},
{"get_serverstats", get_serverstats},
{"put_serverstats", put_serverstats},
{"first_serverstats", first_serverstats},
{"next_serverstats", next_serverstats},
{"new_serverstats", new_serverstats},
{"free_serverstats", free_serverstats},
{0}};
