#define LANG_NAME                        0
#define LANG_CHARSET                     1
#define STRFTIME_DATE_TIME_FORMAT        2
#define STRFTIME_LONG_DATE_FORMAT        3
#define STRFTIME_SHORT_DATE_FORMAT       4
#define STRFTIME_DAYS_SHORT              5
#define STRFTIME_DAYS_LONG               6
#define STRFTIME_MONTHS_SHORT            7
#define STRFTIME_MONTHS_LONG             8
#define STR_DAY                          9
#define STR_DAYS                         10
#define STR_HOUR                         11
#define STR_HOURS                        12
#define STR_MINUTE                       13
#define STR_MINUTES                      14
#define STR_SECOND                       15
#define STR_SECONDS                      16
#define STR_TIMESEP                      17
#define COMMA_SPACE                      18
#define INTERNAL_ERROR                   19
#define SERVICES_IS_BUSY                 20
#define UNKNOWN_COMMAND                  21
#define UNKNOWN_COMMAND_HELP             22
#define SYNTAX_ERROR                     23
#define MORE_INFO                        24
#define NO_HELP_AVAILABLE                25
#define MISSING_QUOTE                    26
#define BAD_EMAIL                        27
#define REJECTED_EMAIL                   28
#define BAD_URL                          29
#define BAD_USERHOST_MASK                30
#define BAD_NICKUSERHOST_MASK            31
#define BAD_EXPIRY_TIME                  32
#define SENDMAIL_NO_RESOURCES            33
#define READ_ONLY_MODE                   34
#define PASSWORD_INCORRECT               35
#define PASSWORD_WARNING                 36
#define ACCESS_DENIED                    37
#define PERMISSION_DENIED                38
#define MORE_OBSCURE_PASSWORD            39
#define NICK_NOT_REGISTERED              40
#define NICK_NOT_REGISTERED_HELP         41
#define NICK_TOO_LONG                    42
#define NICK_INVALID                     43
#define NICK_X_NOT_REGISTERED            44
#define NICK_X_ALREADY_REGISTERED        45
#define NICK_X_NOT_IN_USE                46
#define NICK_X_FORBIDDEN                 47
#define NICK_X_SUSPENDED                 48
#define NICK_X_SUSPENDED_MEMOS           49
#define NICK_IDENTIFY_REQUIRED           50
#define NICK_PLEASE_AUTH                 51
#define NICK_X_NOT_ON_CHAN_X             52
#define CHAN_INVALID                     53
#define CHAN_X_NOT_REGISTERED            54
#define CHAN_X_NOT_IN_USE                55
#define CHAN_X_FORBIDDEN                 56
#define CHAN_X_SUSPENDED                 57
#define CHAN_X_SUSPENDED_MEMOS           58
#define CHAN_IDENTIFY_REQUIRED           59
#define SERV_X_NOT_FOUND                 60
#define EXPIRES_NONE                     61
#define EXPIRES_NOW                      62
#define EXPIRES_IN                       63
#define LIST_RESULTS                     64
#define NICK_IS_REGISTERED               65
#define NICK_IS_SECURE                   66
#define NICK_MAY_NOT_BE_USED             67
#define DISCONNECT_IN_1_MINUTE           68
#define DISCONNECT_IN_20_SECONDS         69
#define DISCONNECT_NOW                   70
#define FORCENICKCHANGE_IN_1_MINUTE      71
#define FORCENICKCHANGE_IN_20_SECONDS    72
#define FORCENICKCHANGE_NOW              73
#define NICK_EXPIRES_SOON                74
#define NICK_EXPIRED                     75
#define NICK_REGISTER_SYNTAX             76
#define NICK_REGISTER_REQ_EMAIL_SYNTAX   77
#define NICK_REGISTRATION_DISABLED       78
#define NICK_REGISTRATION_FAILED         79
#define NICK_REG_PLEASE_WAIT             80
#define NICK_REG_PLEASE_WAIT_FIRST       81
#define NICK_CANNOT_BE_REGISTERED        82
#define NICK_REGISTER_EMAIL_UNAUTHED     83
#define NICK_REGISTER_TOO_MANY_NICKS     84
#define NICK_REGISTERED                  85
#define NICK_PASSWORD_IS                 86
#define NICK_IDENTIFY_SYNTAX             87
#define NICK_IDENTIFY_FAILED             88
#define NICK_IDENTIFY_EMAIL_MISSING      89
#define NICK_IDENTIFY_SUCCEEDED          90
#define NICK_DROP_SYNTAX                 91
#define NICK_DROP_WARNING                92
#define NICK_DROP_DISABLED               93
#define NICK_DROP_FAILED                 94
#define NICK_DROPPED                     95
#define NICK_DROPPED_LINKS               96
#define NICK_DROPNICK_SYNTAX             97
#define NICK_X_DROPPED                   98
#define NICK_X_DROPPED_LINKS             99
#define NICK_DROPEMAIL_SYNTAX            100
#define NICK_DROPEMAIL_PATTERN_TOO_LONG  101
#define NICK_DROPEMAIL_NONE              102
#define NICK_DROPEMAIL_COUNT             103
#define NICK_DROPEMAIL_CONFIRM_SYNTAX    104
#define NICK_DROPEMAIL_CONFIRM_UNKNOWN   105
#define NICK_DROPEMAIL_CONFIRM_DROPPING  106
#define NICK_DROPEMAIL_CONFIRM_DROPPED   107
#define NICK_SET_SYNTAX                  108
#define NICK_SET_OPER_SYNTAX             109
#define NICK_SET_DISABLED                110
#define NICK_SET_UNKNOWN_OPTION          111
#define NICK_SET_PASSWORD_FAILED         112
#define NICK_SET_PASSWORD_CHANGED        113
#define NICK_SET_PASSWORD_CHANGED_TO     114
#define NICK_SET_LANGUAGE_SYNTAX         115
#define NICK_SET_LANGUAGE_UNKNOWN        116
#define NICK_SET_LANGUAGE_CHANGED        117
#define NICK_SET_URL_CHANGED             118
#define NICK_SET_EMAIL_PLEASE_WAIT       119
#define NICK_SET_EMAIL_UNAUTHED          120
#define NICK_SET_EMAIL_TOO_MANY_NICKS    121
#define NICK_SET_EMAIL_CHANGED           122
#define NICK_SET_INFO_CHANGED            123
#define NICK_SET_KILL_SYNTAX             124
#define NICK_SET_KILL_IMMED_SYNTAX       125
#define NICK_SET_KILL_ON                 126
#define NICK_SET_KILL_QUICK              127
#define NICK_SET_KILL_IMMED              128
#define NICK_SET_KILL_IMMED_DISABLED     129
#define NICK_SET_KILL_OFF                130
#define NICK_SET_SECURE_SYNTAX           131
#define NICK_SET_SECURE_ON               132
#define NICK_SET_SECURE_OFF              133
#define NICK_SET_PRIVATE_SYNTAX          134
#define NICK_SET_PRIVATE_ON              135
#define NICK_SET_PRIVATE_OFF             136
#define NICK_SET_NOOP_SYNTAX             137
#define NICK_SET_NOOP_ON                 138
#define NICK_SET_NOOP_OFF                139
#define NICK_SET_HIDE_SYNTAX             140
#define NICK_SET_HIDE_EMAIL_ON           141
#define NICK_SET_HIDE_EMAIL_OFF          142
#define NICK_SET_HIDE_MASK_ON            143
#define NICK_SET_HIDE_MASK_OFF           144
#define NICK_SET_HIDE_QUIT_ON            145
#define NICK_SET_HIDE_QUIT_OFF           146
#define NICK_SET_TIMEZONE_SYNTAX         147
#define NICK_SET_TIMEZONE_TO             148
#define NICK_SET_TIMEZONE_DEFAULT        149
#define NICK_SET_MAINNICK_NOT_FOUND      150
#define NICK_SET_MAINNICK_CHANGED        151
#define NICK_SET_NOEXPIRE_SYNTAX         152
#define NICK_SET_NOEXPIRE_ON             153
#define NICK_SET_NOEXPIRE_OFF            154
#define NICK_UNSET_SYNTAX                155
#define NICK_UNSET_SYNTAX_REQ_EMAIL      156
#define NICK_UNSET_OPER_SYNTAX           157
#define NICK_UNSET_OPER_SYNTAX_REQ_EMAIL 158
#define NICK_UNSET_URL                   159
#define NICK_UNSET_EMAIL                 160
#define NICK_UNSET_INFO                  161
#define NICK_UNSET_EMAIL_BAD             162
#define NICK_UNSET_EMAIL_OTHER_BAD       163
#define NICK_SET_OPCION_YA_ACTIVADA      164
#define NICK_SET_OPCION_ACTIVADA         165
#define NICK_SET_OPCION_NO_ACTIVADA      166
#define NICK_SET_OPCION_DESACTIVADA      167
#define NICK_SET_PARAMETRO_INVALIDO      168
#define NICK_ACCESS_SYNTAX               169
#define NICK_ACCESS_DISABLED             170
#define NICK_ACCESS_ALREADY_PRESENT      171
#define NICK_ACCESS_REACHED_LIMIT        172
#define NICK_ACCESS_NO_NICKS             173
#define NICK_ACCESS_ADDED                174
#define NICK_ACCESS_NOT_FOUND            175
#define NICK_ACCESS_DELETED              176
#define NICK_ACCESS_LIST_EMPTY           177
#define NICK_ACCESS_LIST                 178
#define NICK_ACCESS_LIST_X_EMPTY         179
#define NICK_ACCESS_LIST_X               180
#define NICK_OLD_LINK_SYNTAX             181
#define NICK_LINK_SYNTAX                 182
#define NICK_LINK_DISABLED               183
#define NICK_LINK_FAILED                 184
#define NICK_CANNOT_BE_LINKED            185
#define NICK_OLD_LINK_SAME               186
#define NICK_LINK_SAME                   187
#define NICK_LINK_ALREADY_LINKED         188
#define NICK_LINK_IN_USE                 189
#define NICK_LINK_TOO_MANY               190
#define NICK_LINK_TOO_MANY_NICKS         191
#define NICK_OLD_LINK_TOO_MANY_CHANNELS  192
#define NICK_OLD_LINKED                  193
#define NICK_LINKED                      194
#define NICK_OLD_UNLINK_SYNTAX           195
#define NICK_UNLINK_SYNTAX               196
#define NICK_UNLINK_OPER_SYNTAX          197
#define NICK_UNLINK_DISABLED             198
#define NICK_UNLINK_FAILED               199
#define NICK_UNLINK_SAME                 200
#define NICK_OLD_UNLINK_NOT_LINKED       201
#define NICK_UNLINK_NOT_LINKED_YOURS     202
#define NICK_UNLINK_NOT_LINKED           203
#define NICK_OLD_UNLINKED                204
#define NICK_UNLINKED                    205
#define NICK_X_UNLINKED                  206
#define NICK_OLD_LISTLINKS_SYNTAX        207
#define NICK_LISTLINKS_SYNTAX            208
#define NICK_LISTLINKS_HEADER            209
#define NICK_LISTLINKS_FOOTER            210
#define NICK_INFO_SYNTAX                 211
#define NICK_INFO_REALNAME               212
#define NICK_INFO_ADDRESS                213
#define NICK_INFO_ADDRESS_ONLINE         214
#define NICK_INFO_ADDRESS_ONLINE_NOHOST  215
#define NICK_INFO_ADDRESS_OTHER_NICK     216
#define NICK_INFO_TIME_REGGED            217
#define NICK_INFO_LAST_SEEN              218
#define NICK_INFO_LAST_QUIT              219
#define NICK_INFO_URL                    220
#define NICK_INFO_EMAIL                  221
#define NICK_INFO_EMAIL_UNAUTHED         222
#define NICK_INFO_INFO                   223
#define NICK_INFO_OPTIONS                224
#define NICK_INFO_OPT_KILL               225
#define NICK_INFO_OPT_SECURE             226
#define NICK_INFO_OPT_PRIVATE            227
#define NICK_INFO_OPT_NOOP               228
#define NICK_INFO_OPT_NONE               229
#define NICK_INFO_NO_EXPIRE              230
#define NICK_INFO_SUSPEND_DETAILS        231
#define NICK_INFO_SUSPEND_REASON         232
#define NICK_INFO_SHOW_ALL               233
#define NICK_LISTCHANS_SYNTAX            234
#define NICK_LISTCHANS_NONE              235
#define NICK_LISTCHANS_HEADER            236
#define NICK_LISTCHANS_END               237
#define NICK_LIST_SYNTAX                 238
#define NICK_LIST_OPER_SYNTAX            239
#define NICK_LIST_OPER_SYNTAX_AUTH       240
#define NICK_LIST_HEADER                 241
#define NICK_LIST_NO_MATCH               242
#define NICK_LISTEMAIL_NONE              243
#define NICK_RECOVER_SYNTAX              244
#define NICK_NO_RECOVER_SELF             245
#define NICK_RECOVERED                   246
#define NICK_RELEASE_SYNTAX              247
#define NICK_RELEASE_NOT_HELD            248
#define NICK_RELEASED                    249
#define NICK_GHOST_SYNTAX                250
#define NICK_NO_GHOST_SELF               251
#define NICK_GHOST_KILLED                252
#define NICK_GETPASS_SYNTAX              253
#define NICK_GETPASS_UNAVAILABLE         254
#define NICK_GETPASS_PASSWORD_IS         255
#define NICK_FORBID_SYNTAX               256
#define NICK_FORBID_SUCCEEDED            257
#define NICK_FORBID_FAILED               258
#define NICK_UNFORBID_SYNTAX             259
#define NICK_UNFORBID_SUCCEEDED          260
#define NICK_SUSPEND_SYNTAX              261
#define NICK_SUSPEND_SUCCEEDED           262
#define NICK_SUSPEND_ALREADY_SUSPENDED   263
#define NICK_UNSUSPEND_SYNTAX            264
#define NICK_UNSUSPEND_SUCCEEDED         265
#define NICK_UNSUSPEND_NOT_SUSPENDED     266
#define NICK_AJOIN_SYNTAX                267
#define NICK_AJOIN_ADD_SYNTAX            268
#define NICK_AJOIN_DEL_SYNTAX            269
#define NICK_AJOIN_DISABLED              270
#define NICK_AJOIN_ALREADY_PRESENT       271
#define NICK_AJOIN_LIST_FULL             272
#define NICK_AJOIN_ADDED                 273
#define NICK_AJOIN_NOT_FOUND             274
#define NICK_AJOIN_DELETED               275
#define NICK_AJOIN_LIST_EMPTY            276
#define NICK_AJOIN_LIST                  277
#define NICK_AJOIN_LIST_X_EMPTY          278
#define NICK_AJOIN_LIST_X                279
#define NICK_AJOIN_AUTO_REMOVE           280
#define NICK_AUTH_SENDING                281
#define NICK_AUTH_FOR_REGISTER           282
#define NICK_AUTH_FOR_SET_EMAIL          283
#define NICK_AUTH_NOT_NEEDED             284
#define NICK_AUTH_NO_AUTHCODE            285
#define NICK_AUTH_HAS_AUTHCODE           286
#define PASSWORD_WARNING_FOR_AUTH        287
#define NICK_AUTH_MAIL_SUBJECT           288
#define NICK_AUTH_MAIL_BODY              289
#define NICK_AUTH_MAIL_TEXT_REG          290
#define NICK_AUTH_MAIL_TEXT_EMAIL        291
#define NICK_AUTH_MAIL_TEXT_SENDAUTH     292
#define NICK_AUTH_MAIL_TEXT_REAUTH       293
#define NICK_AUTH_MAIL_BODY_SETAUTH      294
#define NICK_AUTH_SYNTAX                 295
#define NICK_AUTH_DISABLED               296
#define NICK_AUTH_FAILED                 297
#define NICK_AUTH_SUCCEEDED_REGISTER     298
#define NICK_AUTH_SUCCEEDED_SET_EMAIL    299
#define NICK_AUTH_SUCCEEDED_REAUTH       300
#define NICK_AUTH_SUCCEEDED_SETAUTH      301
#define NICK_SENDAUTH_SYNTAX             302
#define NICK_SENDAUTH_TOO_SOON           303
#define NICK_SENDAUTH_NORESOURCES        304
#define NICK_SENDAUTH_ERROR              305
#define NICK_REAUTH_SYNTAX               306
#define NICK_REAUTH_HAVE_AUTHCODE        307
#define NICK_REAUTH_NO_EMAIL             308
#define NICK_REAUTH_AUTHCODE_SET         309
#define NICK_RESTOREMAIL_SYNTAX          310
#define NICK_RESTOREMAIL_NOT_NOW         311
#define NICK_RESTOREMAIL_DONE            312
#define NICK_SETAUTH_SYNTAX              313
#define NICK_SETAUTH_NO_EMAIL            314
#define NICK_SETAUTH_AUTHCODE_SET        315
#define NICK_SETAUTH_SEND_REFUSED        316
#define NICK_SETAUTH_SEND_TIMEOUT        317
#define NICK_SETAUTH_SEND_NORESOURCES    318
#define NICK_SETAUTH_SEND_ERROR          319
#define NICK_SETAUTH_USER_NOTICE         320
#define NICK_GETAUTH_SYNTAX              321
#define NICK_GETAUTH_AUTHCODE_IS         322
#define NICK_CLEARAUTH_SYNTAX            323
#define NICK_CLEARAUTH_CLEARED           324
#define NICK_EMAIL_REGISTER              325
#define NICK_EMAIL_REQPASSWORD           326
#define NICK_EMAIL_GETNEWPASS            327
#define CHAN_LEVEL_AUTOOP                328
#define CHAN_LEVEL_AUTOVOICE             329
#define CHAN_LEVEL_INVITE                330
#define CHAN_LEVEL_AKICK                 331
#define CHAN_LEVEL_SET                   332
#define CHAN_LEVEL_CLEAR                 333
#define CHAN_LEVEL_UNBAN                 334
#define CHAN_LEVEL_OPDEOP                335
#define CHAN_LEVEL_ACCESS_LIST           336
#define CHAN_LEVEL_ACCESS_CHANGE         337
#define CHAN_LEVEL_MEMO                  338
#define CHAN_LEVEL_VOICE                 339
#define CHAN_LEVEL_AUTOHALFOP            340
#define CHAN_LEVEL_HALFOP                341
#define CHAN_LEVEL_AUTOPROTECT           342
#define CHAN_LEVEL_PROTECT               343
#define CHAN_LEVEL_KICK                  344
#define CHAN_LEVEL_STATUS                345
#define CHAN_LEVEL_TOPIC                 346
#define CHAN_IS_REGISTERED               347
#define CHAN_MAY_NOT_BE_USED             348
#define CHAN_NOT_ALLOWED_TO_JOIN         349
#define CHAN_MUST_IDENTIFY_NICK          350
#define CHAN_BOUNCY_MODES                351
#define CHAN_REGISTER_SYNTAX             352
#define CHAN_REGISTER_DISABLED           353
#define CHAN_REGISTER_SHORT_CHANNEL      354
#define CHAN_REGISTER_NOT_LOCAL          355
#define CHAN_REGISTER_INVALID_NAME       356
#define CHAN_MUST_REGISTER_NICK          357
#define CHAN_MAY_NOT_BE_REGISTERED       358
#define CHAN_ALREADY_REGISTERED          359
#define CHAN_MUST_BE_CHANOP              360
#define CHAN_REACHED_CHANNEL_LIMIT       361
#define CHAN_EXCEEDED_CHANNEL_LIMIT      362
#define CHAN_REGISTRATION_FAILED         363
#define CHAN_REGISTERED                  364
#define CHAN_PASSWORD_IS                 365
#define CHAN_IDENTIFY_SYNTAX             366
#define CHAN_IDENTIFY_FAILED             367
#define CHAN_IDENTIFY_SUCCEEDED          368
#define CHAN_DROP_SYNTAX                 369
#define CHAN_DROP_DISABLED               370
#define CHAN_DROPPED                     371
#define CHAN_DROPCHAN_SYNTAX             372
#define CHAN_SET_SYNTAX                  373
#define CHAN_SET_DISABLED                374
#define CHAN_SET_UNKNOWN_OPTION          375
#define CHAN_SET_FOUNDER_TOO_MANY_CHANS  376
#define CHAN_FOUNDER_CHANGED             377
#define CHAN_SUCCESSOR_CHANGED           378
#define CHAN_SUCCESSOR_IS_FOUNDER        379
#define CHAN_SET_PASSWORD_FAILED         380
#define CHAN_PASSWORD_CHANGED            381
#define CHAN_PASSWORD_CHANGED_TO         382
#define CHAN_DESC_CHANGED                383
#define CHAN_URL_CHANGED                 384
#define CHAN_EMAIL_CHANGED               385
#define CHAN_ENTRY_MSG_CHANGED           386
#define CHAN_SET_MLOCK_NEED_PLUS_MINUS   387
#define CHAN_SET_MLOCK_NEED_PARAM        388
#define CHAN_SET_MLOCK_NEED_POSITIVE     389
#define CHAN_SET_MLOCK_MODE_REG_BAD      390
#define CHAN_SET_MLOCK_LINK_BAD          391
#define CHAN_SET_MLOCK_LINK_SAME         392
#define CHAN_SET_MLOCK_REQUIRES          393
#define CHAN_SET_MLOCK_BAD_PARAM         394
#define CHAN_SET_MLOCK_UNKNOWN_CHAR      395
#define CHAN_SET_MLOCK_CANNOT_LOCK       396
#define CHAN_MLOCK_CHANGED               397
#define CHAN_MLOCK_REMOVED               398
#define CHAN_SET_HIDE_SYNTAX             399
#define CHAN_SET_HIDE_EMAIL_ON           400
#define CHAN_SET_HIDE_EMAIL_OFF          401
#define CHAN_SET_HIDE_TOPIC_ON           402
#define CHAN_SET_HIDE_TOPIC_OFF          403
#define CHAN_SET_HIDE_MLOCK_ON           404
#define CHAN_SET_HIDE_MLOCK_OFF          405
#define CHAN_SET_KEEPTOPIC_SYNTAX        406
#define CHAN_SET_KEEPTOPIC_ON            407
#define CHAN_SET_KEEPTOPIC_OFF           408
#define CHAN_SET_TOPICLOCK_SYNTAX        409
#define CHAN_SET_TOPICLOCK_ON            410
#define CHAN_SET_TOPICLOCK_OFF           411
#define CHAN_SET_PRIVATE_SYNTAX          412
#define CHAN_SET_PRIVATE_ON              413
#define CHAN_SET_PRIVATE_OFF             414
#define CHAN_SET_SECUREOPS_SYNTAX        415
#define CHAN_SET_SECUREOPS_ON            416
#define CHAN_SET_SECUREOPS_OFF           417
#define CHAN_SET_LEAVEOPS_SYNTAX         418
#define CHAN_SET_LEAVEOPS_ON             419
#define CHAN_SET_LEAVEOPS_OFF            420
#define CHAN_SET_RESTRICTED_SYNTAX       421
#define CHAN_SET_RESTRICTED_ON           422
#define CHAN_SET_RESTRICTED_OFF          423
#define CHAN_SET_SECURE_SYNTAX           424
#define CHAN_SET_SECURE_ON               425
#define CHAN_SET_SECURE_OFF              426
#define CHAN_SET_DEBUG_SYNTAX            427
#define CHAN_SET_DEBUG_ON                428
#define CHAN_SET_DEBUG_OFF               429
#define CHAN_SET_ENFORCE_SYNTAX          430
#define CHAN_SET_ENFORCE_ON              431
#define CHAN_SET_ENFORCE_OFF             432
#define CHAN_SET_MEMO_RESTRICTED_SYNTAX  433
#define CHAN_SET_MEMO_RESTRICTED_ON      434
#define CHAN_SET_MEMO_RESTRICTED_OFF     435
#define CHAN_SET_NOEXPIRE_SYNTAX         436
#define CHAN_SET_NOEXPIRE_ON             437
#define CHAN_SET_NOEXPIRE_OFF            438
#define CHAN_UNSET_SYNTAX                439
#define CHAN_SUCCESSOR_UNSET             440
#define CHAN_URL_UNSET                   441
#define CHAN_EMAIL_UNSET                 442
#define CHAN_ENTRY_MSG_UNSET             443
#define CHAN_ACCESS_SYNTAX               444
#define CHAN_ACCESS_ADD_SYNTAX           445
#define CHAN_ACCESS_DEL_SYNTAX           446
#define CHAN_ACCESS_LIST_SYNTAX          447
#define CHAN_ACCESS_LISTLEVEL_SYNTAX     448
#define CHAN_ACCESS_COUNT_SYNTAX         449
#define CHAN_ACCESS_DISABLED             450
#define CHAN_ACCESS_LEVEL_NONZERO        451
#define CHAN_ACCESS_LEVEL_RANGE          452
#define CHAN_ACCESS_NICKS_ONLY           453
#define CHAN_ACCESS_NOOP                 454
#define CHAN_ACCESS_REACHED_LIMIT        455
#define CHAN_ACCESS_LEVEL_UNCHANGED      456
#define CHAN_ACCESS_LEVEL_CHANGED        457
#define CHAN_ACCESS_ADDED                458
#define CHAN_ACCESS_NOT_FOUND            459
#define CHAN_ACCESS_DELETED              460
#define CHAN_ACCESS_LIST_EMPTY           461
#define CHAN_ACCESS_NO_MATCH             462
#define CHAN_ACCESS_LIST_HEADER          463
#define CHAN_ACCESS_LIST_FORMAT          464
#define CHAN_ACCESS_COUNT                465
#define CHAN_SOP_SYNTAX                  466
#define CHAN_AOP_SYNTAX                  467
#define CHAN_HOP_SYNTAX                  468
#define CHAN_VOP_SYNTAX                  469
#define CHAN_NOP_SYNTAX                  470
#define CHAN_SOP_LIST_SYNTAX             471
#define CHAN_AOP_LIST_SYNTAX             472
#define CHAN_HOP_LIST_SYNTAX             473
#define CHAN_VOP_LIST_SYNTAX             474
#define CHAN_NOP_LIST_SYNTAX             475
#define CHAN_XOP_ADDED                   476
#define CHAN_XOP_LEVEL_CHANGED           477
#define CHAN_XOP_LEVEL_UNCHANGED         478
#define CHAN_XOP_NICKS_ONLY              479
#define CHAN_XOP_NOOP                    480
#define CHAN_XOP_NICKS_ONLY_HOP          481
#define CHAN_XOP_REACHED_LIMIT           482
#define CHAN_XOP_REACHED_LIMIT_HOP       483
#define CHAN_XOP_NOT_FOUND               484
#define CHAN_XOP_DELETED                 485
#define CHAN_XOP_LIST_EMPTY              486
#define CHAN_XOP_NO_MATCH                487
#define CHAN_XOP_LIST_HEADER             488
#define CHAN_XOP_COUNT                   489
#define CHAN_AKICK_SYNTAX                490
#define CHAN_AKICK_LIST_SYNTAX           491
#define CHAN_AKICK_VIEW_SYNTAX           492
#define CHAN_AKICK_DISABLED              493
#define CHAN_AKICK_ALREADY_EXISTS        494
#define CHAN_AKICK_REACHED_LIMIT         495
#define CHAN_AKICK_ADDED                 496
#define CHAN_AKICK_NOT_FOUND             497
#define CHAN_AKICK_DELETED               498
#define CHAN_AKICK_LIST_EMPTY            499
#define CHAN_AKICK_NO_MATCH              500
#define CHAN_AKICK_LIST_HEADER           501
#define CHAN_AKICK_VIEW_FORMAT           502
#define CHAN_AKICK_VIEW_UNUSED_FORMAT    503
#define CHAN_AKICK_COUNT                 504
#define CHAN_AKICK_ENFORCE_DONE          505
#define CHAN_LEVELS_SYNTAX               506
#define CHAN_LEVELS_READONLY             507
#define CHAN_LEVELS_RANGE                508
#define CHAN_LEVELS_CHANGED              509
#define CHAN_LEVELS_UNKNOWN              510
#define CHAN_LEVELS_DISABLED             511
#define CHAN_LEVELS_LIST_HEADER          512
#define CHAN_LEVELS_LIST_DISABLED        513
#define CHAN_LEVELS_LIST_FOUNDER         514
#define CHAN_LEVELS_LIST_NORMAL          515
#define CHAN_LEVELS_RESET                516
#define CHAN_INFO_SYNTAX                 517
#define CHAN_INFO_HEADER                 518
#define CHAN_INFO_FOUNDER                519
#define CHAN_INFO_SUCCESSOR              520
#define CHAN_INFO_DESCRIPTION            521
#define CHAN_INFO_ENTRYMSG               522
#define CHAN_INFO_TIME_REGGED            523
#define CHAN_INFO_LAST_USED              524
#define CHAN_INFO_LAST_TOPIC             525
#define CHAN_INFO_TOPIC_SET_BY           526
#define CHAN_INFO_URL                    527
#define CHAN_INFO_EMAIL                  528
#define CHAN_INFO_OPTIONS                529
#define CHAN_INFO_OPT_PRIVATE            530
#define CHAN_INFO_OPT_KEEPTOPIC          531
#define CHAN_INFO_OPT_TOPICLOCK          532
#define CHAN_INFO_OPT_SECUREOPS          533
#define CHAN_INFO_OPT_LEAVEOPS           534
#define CHAN_INFO_OPT_RESTRICTED         535
#define CHAN_INFO_OPT_SECURE             536
#define CHAN_INFO_OPT_DEBUG              537
#define CHAN_INFO_OPT_ENFORCE            538
#define CHAN_INFO_OPT_MEMO_RESTRICTED    539
#define CHAN_INFO_OPT_NONE               540
#define CHAN_INFO_MODE_LOCK              541
#define CHAN_INFO_NO_EXPIRE              542
#define CHAN_INFO_SUSPEND_DETAILS        543
#define CHAN_INFO_SUSPEND_REASON         544
#define CHAN_INFO_SHOW_ALL               545
#define CHAN_LIST_SYNTAX                 546
#define CHAN_LIST_OPER_SYNTAX            547
#define CHAN_LIST_HEADER                 548
#define CHAN_LIST_NO_MATCH               549
#define CHAN_INVITE_SYNTAX               550
#define CHAN_INVITE_OK                   551
#define CHAN_OPVOICE_SYNTAX              552
#define CHAN_OP_SUCCEEDED                553
#define CHAN_OP_ALREADY                  554
#define CHAN_OP_FAILED                   555
#define CHAN_DEOP_SUCCEEDED              556
#define CHAN_DEOP_ALREADY                557
#define CHAN_DEOP_FAILED                 558
#define CHAN_VOICE_SUCCEEDED             559
#define CHAN_VOICE_ALREADY               560
#define CHAN_VOICE_FAILED                561
#define CHAN_DEVOICE_SUCCEEDED           562
#define CHAN_DEVOICE_ALREADY             563
#define CHAN_DEVOICE_FAILED              564
#define CHAN_HALFOP_SUCCEEDED            565
#define CHAN_HALFOP_ALREADY              566
#define CHAN_HALFOP_FAILED               567
#define CHAN_DEHALFOP_SUCCEEDED          568
#define CHAN_DEHALFOP_ALREADY            569
#define CHAN_DEHALFOP_FAILED             570
#define CHAN_PROTECT_SUCCEEDED           571
#define CHAN_PROTECT_ALREADY             572
#define CHAN_PROTECT_FAILED              573
#define CHAN_DEPROTECT_SUCCEEDED         574
#define CHAN_DEPROTECT_ALREADY           575
#define CHAN_DEPROTECT_FAILED            576
#define CHAN_UNBAN_SYNTAX                577
#define CHAN_UNBANNED                    578
#define CHAN_KICK_SYNTAX                 579
#define CHAN_KICK_PROTECTED              580
#define CHAN_KICKED                      581
#define CHAN_TOPIC_SYNTAX                582
#define CHAN_CLEAR_SYNTAX                583
#define CHAN_CLEARED_BANS                584
#define CHAN_CLEARED_EXCEPTIONS          585
#define CHAN_CLEARED_INVITES             586
#define CHAN_CLEARED_MODES               587
#define CHAN_CLEARED_OPS                 588
#define CHAN_CLEARED_HALFOPS             589
#define CHAN_CLEARED_VOICES              590
#define CHAN_CLEARED_USERS               591
#define CHAN_GETPASS_SYNTAX              592
#define CHAN_GETPASS_UNAVAILABLE         593
#define CHAN_GETPASS_PASSWORD_IS         594
#define CHAN_FORBID_SYNTAX               595
#define CHAN_FORBID_SHORT_CHANNEL        596
#define CHAN_FORBID_SUCCEEDED            597
#define CHAN_FORBID_FAILED               598
#define CHAN_SUSPEND_SYNTAX              599
#define CHAN_SUSPEND_SUCCEEDED           600
#define CHAN_SUSPEND_ALREADY_SUSPENDED   601
#define CHAN_UNSUSPEND_SYNTAX            602
#define CHAN_UNSUSPEND_SUCCEEDED         603
#define CHAN_UNSUSPEND_NOT_SUSPENDED     604
#define MEMO_HAVE_NEW_MEMO               605
#define MEMO_HAVE_NEW_MEMOS              606
#define MEMO_TYPE_READ_LAST              607
#define MEMO_TYPE_READ_NUM               608
#define MEMO_TYPE_LIST_NEW               609
#define MEMO_AT_LIMIT                    610
#define MEMO_OVER_LIMIT                  611
#define MEMO_NEW_MEMO_ARRIVED            612
#define MEMO_NEW_CHAN_MEMO_ARRIVED       613
#define MEMO_HAVE_NO_MEMOS               614
#define MEMO_HAVE_NO_NEW_MEMOS           615
#define MEMO_DOES_NOT_EXIST              616
#define MEMO_LIST_NOT_FOUND              617
#define MEMO_SEND_SYNTAX                 618
#define MEMO_SEND_DISABLED               619
#define MEMO_SEND_PLEASE_WAIT            620
#define MEMO_SEND_CHAN_NOT_AVAIL         621
#define MEMO_X_GETS_NO_MEMOS             622
#define MEMO_X_HAS_TOO_MANY_MEMOS        623
#define MEMO_SENT                        624
#define MEMO_SEND_FAILED                 625
#define MEMO_LIST_SYNTAX                 626
#define MEMO_LIST_MEMOS                  627
#define MEMO_LIST_NEW_MEMOS              628
#define MEMO_LIST_HEADER                 629
#define MEMO_LIST_FORMAT                 630
#define MEMO_READ_SYNTAX                 631
#define MEMO_HEADER                      632
#define MEMO_CHAN_HEADER                 633
#define MEMO_SAVE_SYNTAX                 634
#define MEMO_SAVED_ONE                   635
#define MEMO_SAVED_SEVERAL               636
#define MEMO_DEL_SYNTAX                  637
#define MEMO_DELETED_NONE                638
#define MEMO_DELETED_ONE                 639
#define MEMO_DELETED_SEVERAL             640
#define MEMO_DELETED_ALL                 641
#define MEMO_RENUMBER_ONLY_YOU           642
#define MEMO_RENUMBER_DONE               643
#define MEMO_SET_SYNTAX                  644
#define MEMO_SET_DISABLED                645
#define MEMO_SET_UNKNOWN_OPTION          646
#define MEMO_SET_NOTIFY_SYNTAX           647
#define MEMO_SET_NOTIFY_ON               648
#define MEMO_SET_NOTIFY_LOGON            649
#define MEMO_SET_NOTIFY_NEW              650
#define MEMO_SET_NOTIFY_OFF              651
#define MEMO_SET_LIMIT_SYNTAX            652
#define MEMO_SET_LIMIT_OPER_SYNTAX       653
#define MEMO_SET_YOUR_LIMIT_FORBIDDEN    654
#define MEMO_SET_LIMIT_FORBIDDEN         655
#define MEMO_SET_YOUR_LIMIT_TOO_HIGH     656
#define MEMO_SET_LIMIT_TOO_HIGH          657
#define MEMO_SET_LIMIT_OVERFLOW          658
#define MEMO_SET_YOUR_LIMIT              659
#define MEMO_SET_YOUR_LIMIT_ZERO         660
#define MEMO_SET_YOUR_LIMIT_DEFAULT      661
#define MEMO_UNSET_YOUR_LIMIT            662
#define MEMO_SET_LIMIT                   663
#define MEMO_SET_LIMIT_ZERO              664
#define MEMO_SET_LIMIT_DEFAULT           665
#define MEMO_UNSET_LIMIT                 666
#define MEMO_INFO_NO_MEMOS               667
#define MEMO_INFO_MEMO                   668
#define MEMO_INFO_MEMO_UNREAD            669
#define MEMO_INFO_MEMOS                  670
#define MEMO_INFO_MEMOS_ONE_UNREAD       671
#define MEMO_INFO_MEMOS_SOME_UNREAD      672
#define MEMO_INFO_MEMOS_ALL_UNREAD       673
#define MEMO_INFO_LIMIT                  674
#define MEMO_INFO_HARD_LIMIT             675
#define MEMO_INFO_LIMIT_ZERO             676
#define MEMO_INFO_HARD_LIMIT_ZERO        677
#define MEMO_INFO_NO_LIMIT               678
#define MEMO_INFO_NOTIFY_OFF             679
#define MEMO_INFO_NOTIFY_ON              680
#define MEMO_INFO_NOTIFY_RECEIVE         681
#define MEMO_INFO_NOTIFY_SIGNON          682
#define MEMO_INFO_X_NO_MEMOS             683
#define MEMO_INFO_X_MEMO                 684
#define MEMO_INFO_X_MEMO_UNREAD          685
#define MEMO_INFO_X_MEMOS                686
#define MEMO_INFO_X_MEMOS_ONE_UNREAD     687
#define MEMO_INFO_X_MEMOS_SOME_UNREAD    688
#define MEMO_INFO_X_MEMOS_ALL_UNREAD     689
#define MEMO_INFO_X_LIMIT                690
#define MEMO_INFO_X_HARD_LIMIT           691
#define MEMO_INFO_X_NO_LIMIT             692
#define MEMO_INFO_X_NOTIFY_OFF           693
#define MEMO_INFO_X_NOTIFY_ON            694
#define MEMO_INFO_X_NOTIFY_RECEIVE       695
#define MEMO_INFO_X_NOTIFY_SIGNON        696
#define MEMO_FORWARD_MAIL_SUBJECT        697
#define MEMO_FORWARD_MULTIPLE_MAIL_SUBJECT 698
#define MEMO_FORWARD_MAIL_BODY           699
#define MEMO_FORWARD_CHANMEMO_MAIL_BODY  700
#define MEMO_FORWARD_SYNTAX              701
#define MEMO_FORWARD_NEED_EMAIL          702
#define MEMO_FORWARD_PLEASE_WAIT         703
#define MEMO_FORWARD_FAILED              704
#define MEMO_FORWARDED_NONE              705
#define MEMO_FORWARDED_ONE               706
#define MEMO_FORWARDED_SEVERAL           707
#define MEMO_FORWARDED_ALL               708
#define MEMO_SET_FORWARD_SYNTAX          709
#define MEMO_SET_FORWARD_ON              710
#define MEMO_SET_FORWARD_COPY            711
#define MEMO_SET_FORWARD_OFF             712
#define MEMO_IGNORE_SYNTAX               713
#define MEMO_IGNORE_ADD_SYNTAX           714
#define MEMO_IGNORE_DEL_SYNTAX           715
#define MEMO_IGNORE_LIST_FULL            716
#define MEMO_IGNORE_ALREADY_PRESENT      717
#define MEMO_IGNORE_ADDED                718
#define MEMO_IGNORE_NOT_FOUND            719
#define MEMO_IGNORE_DELETED              720
#define MEMO_IGNORE_LIST_EMPTY           721
#define MEMO_IGNORE_LIST                 722
#define MEMO_IGNORE_LIST_X_EMPTY         723
#define MEMO_IGNORE_LIST_X               724
#define OPER_BOUNCY_MODES                725
#define OPER_BOUNCY_MODES_U_LINE         726
#define OPER_GLOBAL_SYNTAX               727
#define OPER_STATS_UNKNOWN_OPTION        728
#define OPER_STATS_RESET_USER_COUNT      729
#define OPER_STATS_CURRENT_USERS         730
#define OPER_STATS_MAX_USERS             731
#define OPER_STATS_UPTIME_DHM            732
#define OPER_STATS_UPTIME_HM_MS          733
#define OPER_STATS_KBYTES_READ           734
#define OPER_STATS_KBYTES_WRITTEN        735
#define OPER_STATS_NETBUF_SOCK           736
#define OPER_STATS_NETBUF_SOCK_PERCENT   737
#define OPER_STATS_NETBUF_TOTAL          738
#define OPER_STATS_NETBUF_TOTAL_PERCENT  739
#define OPER_STATS_ALL_USER_MEM          740
#define OPER_STATS_ALL_CHANNEL_MEM       741
#define OPER_STATS_ALL_SERVER_MEM        742
#define OPER_STATS_ALL_NICKGROUPINFO_MEM 743
#define OPER_STATS_ALL_NICKINFO_MEM      744
#define OPER_STATS_ALL_CHANSERV_MEM      745
#define OPER_STATS_ALL_STATSERV_MEM      746
#define OPER_STATS_ALL_NEWS_MEM          747
#define OPER_STATS_ALL_AKILL_MEM         748
#define OPER_STATS_ALL_EXCEPTION_MEM     749
#define OPER_STATS_ALL_SGLINE_MEM        750
#define OPER_STATS_ALL_SQLINE_MEM        751
#define OPER_STATS_ALL_SZLINE_MEM        752
#define OPER_STATS_ALL_SESSION_MEM       753
#define OPER_STATS_ALL_ELINE_MEM         754
#define OPER_GETKEY_SYNTAX               755
#define OPER_GETKEY_KEY_IS               756
#define OPER_GETKEY_NO_KEY               757
#define OPER_MODE_SYNTAX                 758
#define OPER_CLEARMODES_SYNTAX           759
#define OPER_CLEARMODES_DONE             760
#define OPER_CLEARMODES_ALL_DONE         761
#define OPER_CLEARCHAN_SYNTAX            762
#define OPER_CLEARCHAN_DONE              763
#define OPER_KICK_SYNTAX                 764
#define OPER_ADMIN_SYNTAX                765
#define OPER_ADMIN_ADD_SYNTAX            766
#define OPER_ADMIN_DEL_SYNTAX            767
#define OPER_ADMIN_NO_NICKSERV           768
#define OPER_ADMIN_EXISTS                769
#define OPER_ADMIN_ADDED                 770
#define OPER_ADMIN_TOO_MANY              771
#define OPER_ADMIN_REMOVED               772
#define OPER_ADMIN_NOT_FOUND             773
#define OPER_ADMIN_LIST_HEADER           774
#define OPER_OPER_SYNTAX                 775
#define OPER_OPER_ADD_SYNTAX             776
#define OPER_OPER_DEL_SYNTAX             777
#define OPER_OPER_NO_NICKSERV            778
#define OPER_OPER_EXISTS                 779
#define OPER_OPER_ADDED                  780
#define OPER_OPER_TOO_MANY               781
#define OPER_OPER_REMOVED                782
#define OPER_OPER_NOT_FOUND              783
#define OPER_OPER_LIST_HEADER            784
#define OPER_MASKDATA_SYNTAX             785
#define OPER_MASKDATA_ADD_SYNTAX         786
#define OPER_MASKDATA_DEL_SYNTAX         787
#define OPER_MASKDATA_CLEAR_SYNTAX       788
#define OPER_MASKDATA_LIST_SYNTAX        789
#define OPER_MASKDATA_CHECK_SYNTAX       790
#define OPER_MASKDATA_LIST_FORMAT        791
#define OPER_MASKDATA_VIEW_FORMAT        792
#define OPER_MASKDATA_VIEW_UNUSED_FORMAT 793
#define OPER_TOO_MANY_AKILLS             794
#define OPER_AKILL_EXISTS                795
#define OPER_AKILL_NO_NICK               796
#define OPER_AKILL_MASK_TOO_GENERAL      797
#define OPER_AKILL_EXPIRY_LIMITED        798
#define OPER_AKILL_ADDED                 799
#define OPER_AKILL_REMOVED               800
#define OPER_AKILL_CLEARED               801
#define OPER_AKILL_NOT_FOUND             802
#define OPER_AKILL_LIST_HEADER           803
#define OPER_AKILL_LIST_EMPTY            804
#define OPER_AKILL_LIST_NO_MATCH         805
#define OPER_AKILL_CHECK_NO_MATCH        806
#define OPER_AKILL_CHECK_HEADER          807
#define OPER_AKILL_CHECK_TRAILER         808
#define OPER_AKILL_COUNT                 809
#define OPER_AKILLCHAN_SYNTAX            810
#define OPER_AKILLCHAN_AKILLED           811
#define OPER_AKILLCHAN_KILLED            812
#define OPER_AKILLCHAN_AKILLED_ONE       813
#define OPER_AKILLCHAN_KILLED_ONE        814
#define OPER_TOO_MANY_EXCLUDES           815
#define OPER_EXCLUDE_EXISTS              816
#define OPER_EXCLUDE_ADDED               817
#define OPER_EXCLUDE_REMOVED             818
#define OPER_EXCLUDE_CLEARED             819
#define OPER_EXCLUDE_NOT_FOUND           820
#define OPER_EXCLUDE_LIST_HEADER         821
#define OPER_EXCLUDE_LIST_EMPTY          822
#define OPER_EXCLUDE_LIST_NO_MATCH       823
#define OPER_EXCLUDE_CHECK_NO_MATCH      824
#define OPER_EXCLUDE_CHECK_HEADER        825
#define OPER_EXCLUDE_CHECK_TRAILER       826
#define OPER_EXCLUDE_COUNT               827
#define OPER_TOO_MANY_SLINES             828
#define OPER_SLINE_EXISTS                829
#define OPER_SLINE_MASK_TOO_GENERAL      830
#define OPER_SLINE_ADDED                 831
#define OPER_SLINE_REMOVED               832
#define OPER_SLINE_CLEARED               833
#define OPER_SLINE_NOT_FOUND             834
#define OPER_SLINE_LIST_HEADER           835
#define OPER_SLINE_LIST_EMPTY            836
#define OPER_SLINE_LIST_NO_MATCH         837
#define OPER_SLINE_CHECK_NO_MATCH        838
#define OPER_SLINE_CHECK_HEADER          839
#define OPER_SLINE_CHECK_TRAILER         840
#define OPER_SLINE_COUNT                 841
#define OPER_SZLINE_NOT_AVAIL            842
#define OPER_SU_SYNTAX                   843
#define OPER_SU_NO_PASSWORD              844
#define OPER_SU_SUCCEEDED                845
#define OPER_SU_FAILED                   846
#define OPER_SET_SYNTAX                  847
#define OPER_SET_IGNORE_ON               848
#define OPER_SET_IGNORE_OFF              849
#define OPER_SET_IGNORE_ERROR            850
#define OPER_SET_READONLY_ON             851
#define OPER_SET_READONLY_OFF            852
#define OPER_SET_READONLY_ERROR          853
#define OPER_SET_DEBUG_ON                854
#define OPER_SET_DEBUG_OFF               855
#define OPER_SET_DEBUG_LEVEL             856
#define OPER_SET_DEBUG_ERROR             857
#define OPER_SET_SUPASS_FAILED           858
#define OPER_SET_SUPASS_OK               859
#define OPER_SET_SUPASS_NONE             860
#define OPER_SET_UNKNOWN_OPTION          861
#define OPER_JUPE_SYNTAX                 862
#define OPER_JUPE_INVALID_NAME           863
#define OPER_JUPE_ALREADY_JUPED          864
#define OPER_RAW_SYNTAX                  865
#define OPER_UPDATE_SYNTAX               866
#define OPER_UPDATE_FORCE_FAILED         867
#define OPER_UPDATING                    868
#define OPER_UPDATE_COMPLETE             869
#define OPER_UPDATE_FAILED               870
#define OPER_REHASHING                   871
#define OPER_REHASHED                    872
#define OPER_REHASH_ERROR                873
#define OPER_KILLCLONES_SYNTAX           874
#define OPER_KILLCLONES_UNKNOWN_NICK     875
#define OPER_KILLCLONES_KILLED           876
#define OPER_KILLCLONES_KILLED_AKILL     877
#define OPER_EXCEPTION_SYNTAX            878
#define OPER_EXCEPTION_ADD_SYNTAX        879
#define OPER_EXCEPTION_DEL_SYNTAX        880
#define OPER_EXCEPTION_CLEAR_SYNTAX      881
#define OPER_EXCEPTION_MOVE_SYNTAX       882
#define OPER_EXCEPTION_LIST_SYNTAX       883
#define OPER_EXCEPTION_ALREADY_PRESENT   884
#define OPER_EXCEPTION_TOO_MANY          885
#define OPER_EXCEPTION_ADDED             886
#define OPER_EXCEPTION_MOVED             887
#define OPER_EXCEPTION_NO_SUCH_ENTRY     888
#define OPER_EXCEPTION_NOT_FOUND         889
#define OPER_EXCEPTION_NO_MATCH          890
#define OPER_EXCEPTION_EMPTY             891
#define OPER_EXCEPTION_DELETED           892
#define OPER_EXCEPTION_DELETED_ONE       893
#define OPER_EXCEPTION_DELETED_SEVERAL   894
#define OPER_EXCEPTION_CLEARED           895
#define OPER_EXCEPTION_LIST_HEADER       896
#define OPER_EXCEPTION_LIST_COLHEAD      897
#define OPER_EXCEPTION_LIST_FORMAT       898
#define OPER_EXCEPTION_VIEW_FORMAT       899
#define OPER_EXCEPTION_CHECK_SYNTAX      900
#define OPER_EXCEPTION_CHECK_NO_MATCH    901
#define OPER_EXCEPTION_CHECK_HEADER      902
#define OPER_EXCEPTION_CHECK_TRAILER     903
#define OPER_EXCEPTION_COUNT             904
#define OPER_EXCEPTION_INVALID_LIMIT     905
#define OPER_EXCEPTION_INVALID_HOSTMASK  906
#define OPER_SESSION_SYNTAX              907
#define OPER_SESSION_LIST_SYNTAX         908
#define OPER_SESSION_VIEW_SYNTAX         909
#define OPER_SESSION_INVALID_THRESHOLD   910
#define OPER_SESSION_NOT_FOUND           911
#define OPER_SESSION_LIST_HEADER         912
#define OPER_SESSION_LIST_COLHEAD        913
#define OPER_SESSION_LIST_FORMAT         914
#define OPER_SESSION_VIEW_FORMAT         915
#define NEWS_LOGON_TEXT                  916
#define NEWS_OPER_TEXT                   917
#define NEWS_LOGON_SYNTAX                918
#define NEWS_LOGON_LIST_HEADER           919
#define NEWS_LOGON_LIST_ENTRY            920
#define NEWS_LOGON_LIST_NONE             921
#define NEWS_LOGON_ADD_SYNTAX            922
#define NEWS_LOGON_ADD_FULL              923
#define NEWS_LOGON_ADDED                 924
#define NEWS_LOGON_DEL_SYNTAX            925
#define NEWS_LOGON_DEL_NOT_FOUND         926
#define NEWS_LOGON_DELETED               927
#define NEWS_LOGON_DEL_NONE              928
#define NEWS_LOGON_DELETED_ALL           929
#define NEWS_OPER_SYNTAX                 930
#define NEWS_OPER_LIST_HEADER            931
#define NEWS_OPER_LIST_ENTRY             932
#define NEWS_OPER_LIST_NONE              933
#define NEWS_OPER_ADD_SYNTAX             934
#define NEWS_OPER_ADD_FULL               935
#define NEWS_OPER_ADDED                  936
#define NEWS_OPER_DEL_SYNTAX             937
#define NEWS_OPER_DEL_NOT_FOUND          938
#define NEWS_OPER_DELETED                939
#define NEWS_OPER_DEL_NONE               940
#define NEWS_OPER_DELETED_ALL            941
#define NEWS_HELP_LOGON                  942
#define NEWS_HELP_OPER                   943
#define STAT_SERVERS_REMOVE_SERV_FIRST   944
#define STAT_SERVERS_SERVER_EXISTS       945
#define STAT_SERVERS_SYNTAX              946
#define STAT_SERVERS_STATS_TOTAL         947
#define STAT_SERVERS_STATS_ON_OFFLINE    948
#define STAT_SERVERS_LASTQUIT_WAS        949
#define STAT_SERVERS_LIST_HEADER         950
#define STAT_SERVERS_LIST_FORMAT         951
#define STAT_SERVERS_LIST_RESULTS        952
#define STAT_SERVERS_VIEW_HEADER_ONLINE  953
#define STAT_SERVERS_VIEW_HEADER_OFFLINE 954
#define STAT_SERVERS_VIEW_LASTJOIN       955
#define STAT_SERVERS_VIEW_LASTQUIT       956
#define STAT_SERVERS_VIEW_QUITMSG        957
#define STAT_SERVERS_VIEW_USERS_OPERS    958
#define STAT_SERVERS_VIEW_RESULTS        959
#define STAT_SERVERS_DELETE_SYNTAX       960
#define STAT_SERVERS_DELETE_DONE         961
#define STAT_SERVERS_COPY_SYNTAX         962
#define STAT_SERVERS_COPY_DONE           963
#define STAT_SERVERS_RENAME_SYNTAX       964
#define STAT_SERVERS_RENAME_DONE         965
#define STAT_USERS_SYNTAX                966
#define STAT_USERS_TOTUSERS              967
#define STAT_USERS_TOTOPERS              968
#define STAT_USERS_SERVUSERS             969
#define STAT_USERS_SERVOPERS             970
#define CREG_ESTADO_REGISTRADO           971
#define CREG_ESTADO_ENPROCESO_REG        972
#define CREG_ESTADO_DENEGADO             973
#define ADMIN_ELINE_VIEW_FORMAT          974
#define ADMIN_ELINE_LIST_FORMAT          975
#define ADMIN_ELINE_LIST_HEADER          976
#define ADMIN_ELINE_LIST_COLHEAD         977
#define ADMIN_ELINE_DELETED_ONE          978
#define ADMIN_ELINE_DELETED_SEVERAL      979
#define ADMIN_ELINE_DELETED              980
#define ADMIN_ELINE_NO_MATCH             981
#define ADMIN_ELINE_EMPTY                982
#define NICK_HELP                        983
#define NICK_HELP_EXPIRES                984
#define NICK_HELP_WARNING                985
#define NICK_HELP_COMMANDS               986
#define NICK_HELP_COMMANDS_AUTH          987
#define NICK_HELP_COMMANDS_LINK          988
#define NICK_HELP_COMMANDS_ACCESS        989
#define NICK_HELP_COMMANDS_AJOIN         990
#define NICK_HELP_COMMANDS_SET           991
#define NICK_HELP_COMMANDS_LIST          992
#define NICK_HELP_COMMANDS_LISTCHANS     993
#define NICK_HELP_REGISTER               994
#define NICK_HELP_REGISTER_EMAIL         995
#define NICK_HELP_REGISTER_EMAIL_REQ     996
#define NICK_HELP_REGISTER_EMAIL_AUTH    997
#define NICK_HELP_REGISTER_END           998
#define NICK_HELP_IDENTIFY               999
#define NICK_HELP_DROP                   1000
#define NICK_HELP_DROP_LINK              1001
#define NICK_HELP_DROP_END               1002
#define NICK_HELP_AUTH                   1003
#define NICK_HELP_SENDAUTH               1004
#define NICK_HELP_REAUTH                 1005
#define NICK_HELP_RESTOREMAIL            1006
#define NICK_HELP_LINK                   1007
#define NICK_HELP_UNLINK                 1008
#define NICK_HELP_LISTLINKS              1009
#define NICK_HELP_ACCESS                 1010
#define NICK_HELP_REQUESTPASSWORD        1011
#define NICK_HELP_SET                    1012
#define NICK_HELP_SET_OPTION_MAINNICK    1013
#define NICK_HELP_SET_END                1014
#define NICK_HELP_SET_PASSWORD           1015
#define NICK_HELP_SET_LANGUAGE           1016
#define NICK_HELP_SET_URL                1017
#define NICK_HELP_SET_EMAIL              1018
#define NICK_HELP_SET_HIDEMAIL           1019
#define NICK_HELP_SET_INFO               1020
#define NICK_HELP_SET_KILL               1021
#define NICK_HELP_SET_NEVEROP            1022
#define NICK_HELP_SET_SECURE             1023
#define NICK_HELP_SET_PRIVATE            1024
#define NICK_HELP_SET_NOOP               1025
#define NICK_HELP_SET_HIDE               1026
#define NICK_HELP_SET_TIMEZONE           1027
#define NICK_HELP_SET_MAINNICK           1028
#define NICK_HELP_UNSET                  1029
#define NICK_HELP_UNSET_REQ_EMAIL        1030
#define NICK_HELP_RECOVER                1031
#define NICK_HELP_RELEASE                1032
#define NICK_HELP_GHOST                  1033
#define NICK_HELP_INFO                   1034
#define NICK_HELP_INFO_AUTH              1035
#define NICK_HELP_LISTCHANS              1036
#define NICK_HELP_LIST                   1037
#define NICK_HELP_LIST_OPERSONLY         1038
#define NICK_HELP_LISTEMAIL              1039
#define NICK_HELP_STATUS                 1040
#define NICK_HELP_AJOIN                  1041
#define NICK_HELP_AJOIN_END              1042
#define NICK_HELP_AJOIN_END_CHANSERV     1043
#define NICK_OPER_HELP_COMMANDS          1044
#define NICK_OPER_HELP_COMMANDS_DROPEMAIL 1045
#define NICK_OPER_HELP_COMMANDS_GETPASS  1046
#define NICK_OPER_HELP_COMMANDS_FORBID   1047
#define NICK_OPER_HELP_COMMANDS_SETAUTH  1048
#define NICK_OPER_HELP_COMMANDS_END      1049
#define NICK_OPER_HELP_DROPNICK          1050
#define NICK_OPER_HELP_DROPEMAIL         1051
#define NICK_OPER_HELP_SET               1052
#define NICK_OPER_HELP_SET_NOEXPIRE      1053
#define NICK_OPER_HELP_UNSET             1054
#define NICK_OPER_HELP_OLD_UNLINK        1055
#define NICK_OPER_HELP_UNLINK            1056
#define NICK_OPER_HELP_OLD_LISTLINKS     1057
#define NICK_OPER_HELP_LISTLINKS         1058
#define NICK_OPER_HELP_ACCESS            1059
#define NICK_OPER_HELP_INFO              1060
#define NICK_OPER_HELP_LISTCHANS         1061
#define NICK_OPER_HELP_LIST              1062
#define NICK_OPER_HELP_LIST_AUTH         1063
#define NICK_OPER_HELP_LIST_END          1064
#define NICK_OPER_HELP_GETPASS           1065
#define NICK_OPER_HELP_UNFORBID          1066
#define NICK_OPER_HELP_FORBID            1067
#define NICK_OPER_HELP_SUSPEND           1068
#define NICK_OPER_HELP_UNSUSPEND         1069
#define NICK_OPER_HELP_AJOIN             1070
#define NICK_OPER_HELP_SETAUTH           1071
#define NICK_OPER_HELP_GETAUTH           1072
#define NICK_OPER_HELP_CLEARAUTH         1073
#define NICK_ADMIN_HELP_COMMANDS         1074
#define HOST_HELP                        1075
#define HOST_HELP_ACTIVAR                1076
#define HOST_HELP_ANULAR                 1077
#define HOST_OPER_HELP                   1078
#define HOST_OPER_HELP_VHOST             1079
#define CHAN_HELP_REQSOP_LEVXOP          1080
#define CHAN_HELP_REQSOP_LEV             1081
#define CHAN_HELP_REQSOP_XOP             1082
#define CHAN_HELP_REQAOP_LEVXOP          1083
#define CHAN_HELP_REQAOP_LEV             1084
#define CHAN_HELP_REQAOP_XOP             1085
#define CHAN_HELP_REQHOP_LEVXOP          1086
#define CHAN_HELP_REQHOP_LEV             1087
#define CHAN_HELP_REQHOP_XOP             1088
#define CHAN_HELP_REQVOP_LEVXOP          1089
#define CHAN_HELP_REQVOP_LEV             1090
#define CHAN_HELP_REQVOP_XOP             1091
#define CHAN_HELP                        1092
#define CHAN_HELP_EXPIRES                1093
#define CHAN_HELP_COMMANDS               1094
#define CHAN_HELP_COMMANDS_LIST          1095
#define CHAN_HELP_COMMANDS_AKICK         1096
#define CHAN_HELP_COMMANDS_LEVELS        1097
#define CHAN_HELP_COMMANDS_XOP           1098
#define CHAN_HELP_COMMANDS_HOP           1099
#define CHAN_HELP_COMMANDS_XOP_2         1100
#define CHAN_HELP_COMMANDS_OPVOICE       1101
#define CHAN_HELP_COMMANDS_HALFOP        1102
#define CHAN_HELP_COMMANDS_PROTECT       1103
#define CHAN_HELP_COMMANDS_INVITE        1104
#define CHAN_HELP_REGISTER               1105
#define CHAN_HELP_REGISTER_ADMINONLY     1106
#define CHAN_HELP_IDENTIFY               1107
#define CHAN_HELP_DROP                   1108
#define CHAN_HELP_SET                    1109
#define CHAN_HELP_SET_FOUNDER            1110
#define CHAN_HELP_SET_SUCCESSOR          1111
#define CHAN_HELP_SET_PASSWORD           1112
#define CHAN_HELP_SET_DESC               1113
#define CHAN_HELP_SET_URL                1114
#define CHAN_HELP_SET_EMAIL              1115
#define CHAN_HELP_SET_ENTRYMSG           1116
#define CHAN_HELP_SET_KEEPTOPIC          1117
#define CHAN_HELP_SET_TOPICLOCK          1118
#define CHAN_HELP_SET_MLOCK              1119
#define CHAN_HELP_SET_HIDE               1120
#define CHAN_HELP_SET_PRIVATE            1121
#define CHAN_HELP_SET_RESTRICTED         1122
#define CHAN_HELP_SET_SECURE             1123
#define CHAN_HELP_SET_SECUREOPS          1124
#define CHAN_HELP_SET_LEAVEOPS           1125
#define CHAN_HELP_SET_DEBUG              1126
#define CHAN_HELP_SET_ENFORCE            1127
#define CHAN_HELP_SET_MEMO_RESTRICTED    1128
#define CHAN_HELP_SET_NAME               1129
#define CHAN_HELP_SET_TOPIC              1130
#define CHAN_HELP_UNSET                  1131
#define CHAN_HELP_SOP                    1132
#define CHAN_HELP_SOP_MID1               1133
#define CHAN_HELP_SOP_MID1_CHANPROT      1134
#define CHAN_HELP_SOP_MID2               1135
#define CHAN_HELP_SOP_MID2_HALFOP        1136
#define CHAN_HELP_SOP_END                1137
#define CHAN_HELP_AOP                    1138
#define CHAN_HELP_AOP_MID                1139
#define CHAN_HELP_AOP_MID_HALFOP         1140
#define CHAN_HELP_AOP_END                1141
#define CHAN_HELP_HOP                    1142
#define CHAN_HELP_VOP                    1143
#define CHAN_HELP_NOP                    1144
#define CHAN_HELP_ACCESS                 1145
#define CHAN_HELP_ACCESS_XOP             1146
#define CHAN_HELP_ACCESS_XOP_HALFOP      1147
#define CHAN_HELP_ACCESS_LEVELS          1148
#define CHAN_HELP_ACCESS_LEVELS_HALFOP   1149
#define CHAN_HELP_ACCESS_LEVELS_END      1150
#define CHAN_HELP_LEVELS                 1151
#define CHAN_HELP_LEVELS_XOP             1152
#define CHAN_HELP_LEVELS_XOP_HOP         1153
#define CHAN_HELP_LEVELS_END             1154
#define CHAN_HELP_LEVELS_DESC            1155
#define CHAN_HELP_AKICK                  1156
#define CHAN_HELP_INFO                   1157
#define CHAN_HELP_LIST                   1158
#define CHAN_HELP_LIST_OPERSONLY         1159
#define CHAN_HELP_OP                     1160
#define CHAN_HELP_DEOP                   1161
#define CHAN_HELP_VOICE                  1162
#define CHAN_HELP_DEVOICE                1163
#define CHAN_HELP_HALFOP                 1164
#define CHAN_HELP_DEHALFOP               1165
#define CHAN_HELP_PROTECT                1166
#define CHAN_HELP_DEPROTECT              1167
#define CHAN_HELP_INVITE                 1168
#define CHAN_HELP_UNBAN                  1169
#define CHAN_HELP_KICK                   1170
#define CHAN_HELP_KICK_PROTECTED         1171
#define CHAN_HELP_TOPIC                  1172
#define CHAN_HELP_CLEAR                  1173
#define CHAN_HELP_CLEAR_EXCEPTIONS       1174
#define CHAN_HELP_CLEAR_INVITES          1175
#define CHAN_HELP_CLEAR_MID              1176
#define CHAN_HELP_CLEAR_HALFOPS          1177
#define CHAN_HELP_CLEAR_END              1178
#define CHAN_HELP_STATUS                 1179
#define CHAN_HELP_DELSUCCESSOR           1180
#define CHAN_OPER_HELP_COMMANDS          1181
#define CHAN_OPER_HELP_COMMANDS_GETPASS  1182
#define CHAN_OPER_HELP_COMMANDS_FORBID   1183
#define CHAN_OPER_HELP_COMMANDS_END      1184
#define CHAN_OPER_HELP_DROPCHAN          1185
#define CHAN_OPER_HELP_SET               1186
#define CHAN_OPER_HELP_SET_NOEXPIRE      1187
#define CHAN_OPER_HELP_UNSET             1188
#define CHAN_OPER_HELP_INFO              1189
#define CHAN_OPER_HELP_LIST              1190
#define CHAN_OPER_HELP_GETPASS           1191
#define CHAN_OPER_HELP_FORBID            1192
#define CHAN_OPER_HELP_SUSPEND           1193
#define CHAN_OPER_HELP_UNSUSPEND         1194
#define CREG_HELP                        1195
#define CREG_HELP_REGISTER               1196
#define CREG_HELP_ESTADO                 1197
#define CREG_HELP_FOOTER                 1198
#define CREG_OPER_HELP                   1199
#define CREG_ADMIN_HELP                  1200
#define CREG_OPER_HELP_APROBAR           1201
#define CREG_OPER_HELP_DENEGAR           1202
#define MEMO_HELP                        1203
#define MEMO_HELP_EXPIRES                1204
#define MEMO_HELP_END_LEVELS             1205
#define MEMO_HELP_END_XOP                1206
#define MEMO_HELP_COMMANDS               1207
#define MEMO_HELP_COMMANDS_FORWARD       1208
#define MEMO_HELP_COMMANDS_SAVE          1209
#define MEMO_HELP_COMMANDS_DEL           1210
#define MEMO_HELP_COMMANDS_IGNORE        1211
#define MEMO_HELP_SEND                   1212
#define MEMO_HELP_LIST                   1213
#define MEMO_HELP_LIST_EXPIRE            1214
#define MEMO_HELP_READ                   1215
#define MEMO_HELP_SAVE                   1216
#define MEMO_HELP_DEL                    1217
#define MEMO_HELP_RENUMBER               1218
#define MEMO_HELP_SET                    1219
#define MEMO_HELP_SET_OPTION_FORWARD     1220
#define MEMO_HELP_SET_END                1221
#define MEMO_HELP_SET_NOTIFY             1222
#define MEMO_HELP_SET_LIMIT              1223
#define MEMO_HELP_INFO                   1224
#define MEMO_OPER_HELP_COMMANDS          1225
#define MEMO_OPER_HELP_SET_LIMIT         1226
#define MEMO_OPER_HELP_INFO              1227
#define MEMO_HELP_FORWARD                1228
#define MEMO_HELP_SET_FORWARD            1229
#define MEMO_HELP_IGNORE                 1230
#define OPER_HELP                        1231
#define OPER_HELP_COMMANDS               1232
#define OPER_HELP_COMMANDS_SERVOPER      1233
#define OPER_HELP_COMMANDS_AKILL         1234
#define OPER_HELP_COMMANDS_EXCLUDE       1235
#define OPER_HELP_COMMANDS_SLINE         1236
#define OPER_HELP_COMMANDS_SESSION       1237
#define OPER_HELP_COMMANDS_NEWS          1238
#define OPER_HELP_COMMANDS_SERVADMIN     1239
#define OPER_HELP_COMMANDS_SERVROOT      1240
#define OPER_HELP_COMMANDS_RAW           1241
#define OPER_HELP_GLOBAL                 1242
#define OPER_HELP_STATS                  1243
#define OPER_HELP_SERVERMAP              1244
#define OPER_HELP_OPER                   1245
#define OPER_HELP_ADMIN                  1246
#define OPER_HELP_GETKEY                 1247
#define OPER_HELP_MODE                   1248
#define OPER_HELP_CLEARMODES             1249
#define OPER_HELP_CLEARCHAN              1250
#define OPER_HELP_KICK                   1251
#define OPER_HELP_AKILL                  1252
#define OPER_HELP_AKILL_OPERMAXEXPIRY    1253
#define OPER_HELP_AKILL_END              1254
#define OPER_HELP_AKILLCHAN              1255
#define OPER_HELP_EXCLUDE                1256
#define OPER_HELP_SGLINE                 1257
#define OPER_HELP_SQLINE                 1258
#define OPER_HELP_SQLINE_KILL            1259
#define OPER_HELP_SQLINE_NOKILL          1260
#define OPER_HELP_SQLINE_IGNOREOPERS     1261
#define OPER_HELP_SQLINE_END             1262
#define OPER_HELP_SZLINE                 1263
#define OPER_HELP_EXCEPTION              1264
#define OPER_HELP_SESSION                1265
#define OPER_HELP_SU                     1266
#define OPER_HELP_SET                    1267
#define OPER_HELP_SET_READONLY           1268
#define OPER_HELP_SET_DEBUG              1269
#define OPER_HELP_SET_SUPASS             1270
#define OPER_HELP_JUPE                   1271
#define OPER_HELP_RAW                    1272
#define OPER_HELP_UPDATE                 1273
#define OPER_HELP_QUIT                   1274
#define OPER_HELP_SHUTDOWN               1275
#define OPER_HELP_RESTART                1276
#define OPER_HELP_REHASH                 1277
#define OPER_HELP_KILLCLONES             1278
#define ADMIN_HELP                       1279
#define ADMIN_ROOT_HELP                  1280
#define DDB_HELP                         1281
#define DDB_ROOT_HELP                    1282
#define DDB_FOOTER_HELP                  1283
#define STAT_HELP                        1284
#define STAT_HELP_COMMANDS               1285
#define STAT_HELP_SERVERS                1286
#define STAT_HELP_USERS                  1287
#define STAT_OPER_HELP_SERVERS           1288
#define OPER_HELP_KILL                   1289
#define OPER_HELP_FJOIN                  1290
#define OPER_HELP_FPART                  1291
#define OPER_HELP_TGLINE                 1292
#define OPER_HELP_HACK                   1293
#define HELP_CABECERA                    1294
#define HELP_FOOTER                      1295
#define HELP_COMMAND_FOOTER              1296
#define GLOBAL_HELP                      1297
#define GLOBAL_HELP_NICK                 1298
#define GLOBAL_NICK_SYNTAX               1299
#define CHAN_INFORMA_UNSET               1300
#define CHAN_INFO_INFORMA                1301
#define CHAN_HELP_SET_INFORMA            1302
#define CHAN_INFORMA_CHANGED             1303
#define PREOP_HELP                       1304
#define PREOP_FOOTER_HELP                1305

#define NUM_BASE_STRINGS 1306

#ifdef LANGSTR_ARRAY
static const char * const base_langstrs[] = {
    "LANG_NAME",
    "LANG_CHARSET",
    "STRFTIME_DATE_TIME_FORMAT",
    "STRFTIME_LONG_DATE_FORMAT",
    "STRFTIME_SHORT_DATE_FORMAT",
    "STRFTIME_DAYS_SHORT",
    "STRFTIME_DAYS_LONG",
    "STRFTIME_MONTHS_SHORT",
    "STRFTIME_MONTHS_LONG",
    "STR_DAY",
    "STR_DAYS",
    "STR_HOUR",
    "STR_HOURS",
    "STR_MINUTE",
    "STR_MINUTES",
    "STR_SECOND",
    "STR_SECONDS",
    "STR_TIMESEP",
    "COMMA_SPACE",
    "INTERNAL_ERROR",
    "SERVICES_IS_BUSY",
    "UNKNOWN_COMMAND",
    "UNKNOWN_COMMAND_HELP",
    "SYNTAX_ERROR",
    "MORE_INFO",
    "NO_HELP_AVAILABLE",
    "MISSING_QUOTE",
    "BAD_EMAIL",
    "REJECTED_EMAIL",
    "BAD_URL",
    "BAD_USERHOST_MASK",
    "BAD_NICKUSERHOST_MASK",
    "BAD_EXPIRY_TIME",
    "SENDMAIL_NO_RESOURCES",
    "READ_ONLY_MODE",
    "PASSWORD_INCORRECT",
    "PASSWORD_WARNING",
    "ACCESS_DENIED",
    "PERMISSION_DENIED",
    "MORE_OBSCURE_PASSWORD",
    "NICK_NOT_REGISTERED",
    "NICK_NOT_REGISTERED_HELP",
    "NICK_TOO_LONG",
    "NICK_INVALID",
    "NICK_X_NOT_REGISTERED",
    "NICK_X_ALREADY_REGISTERED",
    "NICK_X_NOT_IN_USE",
    "NICK_X_FORBIDDEN",
    "NICK_X_SUSPENDED",
    "NICK_X_SUSPENDED_MEMOS",
    "NICK_IDENTIFY_REQUIRED",
    "NICK_PLEASE_AUTH",
    "NICK_X_NOT_ON_CHAN_X",
    "CHAN_INVALID",
    "CHAN_X_NOT_REGISTERED",
    "CHAN_X_NOT_IN_USE",
    "CHAN_X_FORBIDDEN",
    "CHAN_X_SUSPENDED",
    "CHAN_X_SUSPENDED_MEMOS",
    "CHAN_IDENTIFY_REQUIRED",
    "SERV_X_NOT_FOUND",
    "EXPIRES_NONE",
    "EXPIRES_NOW",
    "EXPIRES_IN",
    "LIST_RESULTS",
    "NICK_IS_REGISTERED",
    "NICK_IS_SECURE",
    "NICK_MAY_NOT_BE_USED",
    "DISCONNECT_IN_1_MINUTE",
    "DISCONNECT_IN_20_SECONDS",
    "DISCONNECT_NOW",
    "FORCENICKCHANGE_IN_1_MINUTE",
    "FORCENICKCHANGE_IN_20_SECONDS",
    "FORCENICKCHANGE_NOW",
    "NICK_EXPIRES_SOON",
    "NICK_EXPIRED",
    "NICK_REGISTER_SYNTAX",
    "NICK_REGISTER_REQ_EMAIL_SYNTAX",
    "NICK_REGISTRATION_DISABLED",
    "NICK_REGISTRATION_FAILED",
    "NICK_REG_PLEASE_WAIT",
    "NICK_REG_PLEASE_WAIT_FIRST",
    "NICK_CANNOT_BE_REGISTERED",
    "NICK_REGISTER_EMAIL_UNAUTHED",
    "NICK_REGISTER_TOO_MANY_NICKS",
    "NICK_REGISTERED",
    "NICK_PASSWORD_IS",
    "NICK_IDENTIFY_SYNTAX",
    "NICK_IDENTIFY_FAILED",
    "NICK_IDENTIFY_EMAIL_MISSING",
    "NICK_IDENTIFY_SUCCEEDED",
    "NICK_DROP_SYNTAX",
    "NICK_DROP_WARNING",
    "NICK_DROP_DISABLED",
    "NICK_DROP_FAILED",
    "NICK_DROPPED",
    "NICK_DROPPED_LINKS",
    "NICK_DROPNICK_SYNTAX",
    "NICK_X_DROPPED",
    "NICK_X_DROPPED_LINKS",
    "NICK_DROPEMAIL_SYNTAX",
    "NICK_DROPEMAIL_PATTERN_TOO_LONG",
    "NICK_DROPEMAIL_NONE",
    "NICK_DROPEMAIL_COUNT",
    "NICK_DROPEMAIL_CONFIRM_SYNTAX",
    "NICK_DROPEMAIL_CONFIRM_UNKNOWN",
    "NICK_DROPEMAIL_CONFIRM_DROPPING",
    "NICK_DROPEMAIL_CONFIRM_DROPPED",
    "NICK_SET_SYNTAX",
    "NICK_SET_OPER_SYNTAX",
    "NICK_SET_DISABLED",
    "NICK_SET_UNKNOWN_OPTION",
    "NICK_SET_PASSWORD_FAILED",
    "NICK_SET_PASSWORD_CHANGED",
    "NICK_SET_PASSWORD_CHANGED_TO",
    "NICK_SET_LANGUAGE_SYNTAX",
    "NICK_SET_LANGUAGE_UNKNOWN",
    "NICK_SET_LANGUAGE_CHANGED",
    "NICK_SET_URL_CHANGED",
    "NICK_SET_EMAIL_PLEASE_WAIT",
    "NICK_SET_EMAIL_UNAUTHED",
    "NICK_SET_EMAIL_TOO_MANY_NICKS",
    "NICK_SET_EMAIL_CHANGED",
    "NICK_SET_INFO_CHANGED",
    "NICK_SET_KILL_SYNTAX",
    "NICK_SET_KILL_IMMED_SYNTAX",
    "NICK_SET_KILL_ON",
    "NICK_SET_KILL_QUICK",
    "NICK_SET_KILL_IMMED",
    "NICK_SET_KILL_IMMED_DISABLED",
    "NICK_SET_KILL_OFF",
    "NICK_SET_SECURE_SYNTAX",
    "NICK_SET_SECURE_ON",
    "NICK_SET_SECURE_OFF",
    "NICK_SET_PRIVATE_SYNTAX",
    "NICK_SET_PRIVATE_ON",
    "NICK_SET_PRIVATE_OFF",
    "NICK_SET_NOOP_SYNTAX",
    "NICK_SET_NOOP_ON",
    "NICK_SET_NOOP_OFF",
    "NICK_SET_HIDE_SYNTAX",
    "NICK_SET_HIDE_EMAIL_ON",
    "NICK_SET_HIDE_EMAIL_OFF",
    "NICK_SET_HIDE_MASK_ON",
    "NICK_SET_HIDE_MASK_OFF",
    "NICK_SET_HIDE_QUIT_ON",
    "NICK_SET_HIDE_QUIT_OFF",
    "NICK_SET_TIMEZONE_SYNTAX",
    "NICK_SET_TIMEZONE_TO",
    "NICK_SET_TIMEZONE_DEFAULT",
    "NICK_SET_MAINNICK_NOT_FOUND",
    "NICK_SET_MAINNICK_CHANGED",
    "NICK_SET_NOEXPIRE_SYNTAX",
    "NICK_SET_NOEXPIRE_ON",
    "NICK_SET_NOEXPIRE_OFF",
    "NICK_UNSET_SYNTAX",
    "NICK_UNSET_SYNTAX_REQ_EMAIL",
    "NICK_UNSET_OPER_SYNTAX",
    "NICK_UNSET_OPER_SYNTAX_REQ_EMAIL",
    "NICK_UNSET_URL",
    "NICK_UNSET_EMAIL",
    "NICK_UNSET_INFO",
    "NICK_UNSET_EMAIL_BAD",
    "NICK_UNSET_EMAIL_OTHER_BAD",
    "NICK_SET_OPCION_YA_ACTIVADA",
    "NICK_SET_OPCION_ACTIVADA",
    "NICK_SET_OPCION_NO_ACTIVADA",
    "NICK_SET_OPCION_DESACTIVADA",
    "NICK_SET_PARAMETRO_INVALIDO",
    "NICK_ACCESS_SYNTAX",
    "NICK_ACCESS_DISABLED",
    "NICK_ACCESS_ALREADY_PRESENT",
    "NICK_ACCESS_REACHED_LIMIT",
    "NICK_ACCESS_NO_NICKS",
    "NICK_ACCESS_ADDED",
    "NICK_ACCESS_NOT_FOUND",
    "NICK_ACCESS_DELETED",
    "NICK_ACCESS_LIST_EMPTY",
    "NICK_ACCESS_LIST",
    "NICK_ACCESS_LIST_X_EMPTY",
    "NICK_ACCESS_LIST_X",
    "NICK_OLD_LINK_SYNTAX",
    "NICK_LINK_SYNTAX",
    "NICK_LINK_DISABLED",
    "NICK_LINK_FAILED",
    "NICK_CANNOT_BE_LINKED",
    "NICK_OLD_LINK_SAME",
    "NICK_LINK_SAME",
    "NICK_LINK_ALREADY_LINKED",
    "NICK_LINK_IN_USE",
    "NICK_LINK_TOO_MANY",
    "NICK_LINK_TOO_MANY_NICKS",
    "NICK_OLD_LINK_TOO_MANY_CHANNELS",
    "NICK_OLD_LINKED",
    "NICK_LINKED",
    "NICK_OLD_UNLINK_SYNTAX",
    "NICK_UNLINK_SYNTAX",
    "NICK_UNLINK_OPER_SYNTAX",
    "NICK_UNLINK_DISABLED",
    "NICK_UNLINK_FAILED",
    "NICK_UNLINK_SAME",
    "NICK_OLD_UNLINK_NOT_LINKED",
    "NICK_UNLINK_NOT_LINKED_YOURS",
    "NICK_UNLINK_NOT_LINKED",
    "NICK_OLD_UNLINKED",
    "NICK_UNLINKED",
    "NICK_X_UNLINKED",
    "NICK_OLD_LISTLINKS_SYNTAX",
    "NICK_LISTLINKS_SYNTAX",
    "NICK_LISTLINKS_HEADER",
    "NICK_LISTLINKS_FOOTER",
    "NICK_INFO_SYNTAX",
    "NICK_INFO_REALNAME",
    "NICK_INFO_ADDRESS",
    "NICK_INFO_ADDRESS_ONLINE",
    "NICK_INFO_ADDRESS_ONLINE_NOHOST",
    "NICK_INFO_ADDRESS_OTHER_NICK",
    "NICK_INFO_TIME_REGGED",
    "NICK_INFO_LAST_SEEN",
    "NICK_INFO_LAST_QUIT",
    "NICK_INFO_URL",
    "NICK_INFO_EMAIL",
    "NICK_INFO_EMAIL_UNAUTHED",
    "NICK_INFO_INFO",
    "NICK_INFO_OPTIONS",
    "NICK_INFO_OPT_KILL",
    "NICK_INFO_OPT_SECURE",
    "NICK_INFO_OPT_PRIVATE",
    "NICK_INFO_OPT_NOOP",
    "NICK_INFO_OPT_NONE",
    "NICK_INFO_NO_EXPIRE",
    "NICK_INFO_SUSPEND_DETAILS",
    "NICK_INFO_SUSPEND_REASON",
    "NICK_INFO_SHOW_ALL",
    "NICK_LISTCHANS_SYNTAX",
    "NICK_LISTCHANS_NONE",
    "NICK_LISTCHANS_HEADER",
    "NICK_LISTCHANS_END",
    "NICK_LIST_SYNTAX",
    "NICK_LIST_OPER_SYNTAX",
    "NICK_LIST_OPER_SYNTAX_AUTH",
    "NICK_LIST_HEADER",
    "NICK_LIST_NO_MATCH",
    "NICK_LISTEMAIL_NONE",
    "NICK_RECOVER_SYNTAX",
    "NICK_NO_RECOVER_SELF",
    "NICK_RECOVERED",
    "NICK_RELEASE_SYNTAX",
    "NICK_RELEASE_NOT_HELD",
    "NICK_RELEASED",
    "NICK_GHOST_SYNTAX",
    "NICK_NO_GHOST_SELF",
    "NICK_GHOST_KILLED",
    "NICK_GETPASS_SYNTAX",
    "NICK_GETPASS_UNAVAILABLE",
    "NICK_GETPASS_PASSWORD_IS",
    "NICK_FORBID_SYNTAX",
    "NICK_FORBID_SUCCEEDED",
    "NICK_FORBID_FAILED",
    "NICK_UNFORBID_SYNTAX",
    "NICK_UNFORBID_SUCCEEDED",
    "NICK_SUSPEND_SYNTAX",
    "NICK_SUSPEND_SUCCEEDED",
    "NICK_SUSPEND_ALREADY_SUSPENDED",
    "NICK_UNSUSPEND_SYNTAX",
    "NICK_UNSUSPEND_SUCCEEDED",
    "NICK_UNSUSPEND_NOT_SUSPENDED",
    "NICK_AJOIN_SYNTAX",
    "NICK_AJOIN_ADD_SYNTAX",
    "NICK_AJOIN_DEL_SYNTAX",
    "NICK_AJOIN_DISABLED",
    "NICK_AJOIN_ALREADY_PRESENT",
    "NICK_AJOIN_LIST_FULL",
    "NICK_AJOIN_ADDED",
    "NICK_AJOIN_NOT_FOUND",
    "NICK_AJOIN_DELETED",
    "NICK_AJOIN_LIST_EMPTY",
    "NICK_AJOIN_LIST",
    "NICK_AJOIN_LIST_X_EMPTY",
    "NICK_AJOIN_LIST_X",
    "NICK_AJOIN_AUTO_REMOVE",
    "NICK_AUTH_SENDING",
    "NICK_AUTH_FOR_REGISTER",
    "NICK_AUTH_FOR_SET_EMAIL",
    "NICK_AUTH_NOT_NEEDED",
    "NICK_AUTH_NO_AUTHCODE",
    "NICK_AUTH_HAS_AUTHCODE",
    "PASSWORD_WARNING_FOR_AUTH",
    "NICK_AUTH_MAIL_SUBJECT",
    "NICK_AUTH_MAIL_BODY",
    "NICK_AUTH_MAIL_TEXT_REG",
    "NICK_AUTH_MAIL_TEXT_EMAIL",
    "NICK_AUTH_MAIL_TEXT_SENDAUTH",
    "NICK_AUTH_MAIL_TEXT_REAUTH",
    "NICK_AUTH_MAIL_BODY_SETAUTH",
    "NICK_AUTH_SYNTAX",
    "NICK_AUTH_DISABLED",
    "NICK_AUTH_FAILED",
    "NICK_AUTH_SUCCEEDED_REGISTER",
    "NICK_AUTH_SUCCEEDED_SET_EMAIL",
    "NICK_AUTH_SUCCEEDED_REAUTH",
    "NICK_AUTH_SUCCEEDED_SETAUTH",
    "NICK_SENDAUTH_SYNTAX",
    "NICK_SENDAUTH_TOO_SOON",
    "NICK_SENDAUTH_NORESOURCES",
    "NICK_SENDAUTH_ERROR",
    "NICK_REAUTH_SYNTAX",
    "NICK_REAUTH_HAVE_AUTHCODE",
    "NICK_REAUTH_NO_EMAIL",
    "NICK_REAUTH_AUTHCODE_SET",
    "NICK_RESTOREMAIL_SYNTAX",
    "NICK_RESTOREMAIL_NOT_NOW",
    "NICK_RESTOREMAIL_DONE",
    "NICK_SETAUTH_SYNTAX",
    "NICK_SETAUTH_NO_EMAIL",
    "NICK_SETAUTH_AUTHCODE_SET",
    "NICK_SETAUTH_SEND_REFUSED",
    "NICK_SETAUTH_SEND_TIMEOUT",
    "NICK_SETAUTH_SEND_NORESOURCES",
    "NICK_SETAUTH_SEND_ERROR",
    "NICK_SETAUTH_USER_NOTICE",
    "NICK_GETAUTH_SYNTAX",
    "NICK_GETAUTH_AUTHCODE_IS",
    "NICK_CLEARAUTH_SYNTAX",
    "NICK_CLEARAUTH_CLEARED",
    "NICK_EMAIL_REGISTER",
    "NICK_EMAIL_REQPASSWORD",
    "NICK_EMAIL_GETNEWPASS",
    "CHAN_LEVEL_AUTOOP",
    "CHAN_LEVEL_AUTOVOICE",
    "CHAN_LEVEL_INVITE",
    "CHAN_LEVEL_AKICK",
    "CHAN_LEVEL_SET",
    "CHAN_LEVEL_CLEAR",
    "CHAN_LEVEL_UNBAN",
    "CHAN_LEVEL_OPDEOP",
    "CHAN_LEVEL_ACCESS_LIST",
    "CHAN_LEVEL_ACCESS_CHANGE",
    "CHAN_LEVEL_MEMO",
    "CHAN_LEVEL_VOICE",
    "CHAN_LEVEL_AUTOHALFOP",
    "CHAN_LEVEL_HALFOP",
    "CHAN_LEVEL_AUTOPROTECT",
    "CHAN_LEVEL_PROTECT",
    "CHAN_LEVEL_KICK",
    "CHAN_LEVEL_STATUS",
    "CHAN_LEVEL_TOPIC",
    "CHAN_IS_REGISTERED",
    "CHAN_MAY_NOT_BE_USED",
    "CHAN_NOT_ALLOWED_TO_JOIN",
    "CHAN_MUST_IDENTIFY_NICK",
    "CHAN_BOUNCY_MODES",
    "CHAN_REGISTER_SYNTAX",
    "CHAN_REGISTER_DISABLED",
    "CHAN_REGISTER_SHORT_CHANNEL",
    "CHAN_REGISTER_NOT_LOCAL",
    "CHAN_REGISTER_INVALID_NAME",
    "CHAN_MUST_REGISTER_NICK",
    "CHAN_MAY_NOT_BE_REGISTERED",
    "CHAN_ALREADY_REGISTERED",
    "CHAN_MUST_BE_CHANOP",
    "CHAN_REACHED_CHANNEL_LIMIT",
    "CHAN_EXCEEDED_CHANNEL_LIMIT",
    "CHAN_REGISTRATION_FAILED",
    "CHAN_REGISTERED",
    "CHAN_PASSWORD_IS",
    "CHAN_IDENTIFY_SYNTAX",
    "CHAN_IDENTIFY_FAILED",
    "CHAN_IDENTIFY_SUCCEEDED",
    "CHAN_DROP_SYNTAX",
    "CHAN_DROP_DISABLED",
    "CHAN_DROPPED",
    "CHAN_DROPCHAN_SYNTAX",
    "CHAN_SET_SYNTAX",
    "CHAN_SET_DISABLED",
    "CHAN_SET_UNKNOWN_OPTION",
    "CHAN_SET_FOUNDER_TOO_MANY_CHANS",
    "CHAN_FOUNDER_CHANGED",
    "CHAN_SUCCESSOR_CHANGED",
    "CHAN_SUCCESSOR_IS_FOUNDER",
    "CHAN_SET_PASSWORD_FAILED",
    "CHAN_PASSWORD_CHANGED",
    "CHAN_PASSWORD_CHANGED_TO",
    "CHAN_DESC_CHANGED",
    "CHAN_URL_CHANGED",
    "CHAN_EMAIL_CHANGED",
    "CHAN_ENTRY_MSG_CHANGED",
    "CHAN_SET_MLOCK_NEED_PLUS_MINUS",
    "CHAN_SET_MLOCK_NEED_PARAM",
    "CHAN_SET_MLOCK_NEED_POSITIVE",
    "CHAN_SET_MLOCK_MODE_REG_BAD",
    "CHAN_SET_MLOCK_LINK_BAD",
    "CHAN_SET_MLOCK_LINK_SAME",
    "CHAN_SET_MLOCK_REQUIRES",
    "CHAN_SET_MLOCK_BAD_PARAM",
    "CHAN_SET_MLOCK_UNKNOWN_CHAR",
    "CHAN_SET_MLOCK_CANNOT_LOCK",
    "CHAN_MLOCK_CHANGED",
    "CHAN_MLOCK_REMOVED",
    "CHAN_SET_HIDE_SYNTAX",
    "CHAN_SET_HIDE_EMAIL_ON",
    "CHAN_SET_HIDE_EMAIL_OFF",
    "CHAN_SET_HIDE_TOPIC_ON",
    "CHAN_SET_HIDE_TOPIC_OFF",
    "CHAN_SET_HIDE_MLOCK_ON",
    "CHAN_SET_HIDE_MLOCK_OFF",
    "CHAN_SET_KEEPTOPIC_SYNTAX",
    "CHAN_SET_KEEPTOPIC_ON",
    "CHAN_SET_KEEPTOPIC_OFF",
    "CHAN_SET_TOPICLOCK_SYNTAX",
    "CHAN_SET_TOPICLOCK_ON",
    "CHAN_SET_TOPICLOCK_OFF",
    "CHAN_SET_PRIVATE_SYNTAX",
    "CHAN_SET_PRIVATE_ON",
    "CHAN_SET_PRIVATE_OFF",
    "CHAN_SET_SECUREOPS_SYNTAX",
    "CHAN_SET_SECUREOPS_ON",
    "CHAN_SET_SECUREOPS_OFF",
    "CHAN_SET_LEAVEOPS_SYNTAX",
    "CHAN_SET_LEAVEOPS_ON",
    "CHAN_SET_LEAVEOPS_OFF",
    "CHAN_SET_RESTRICTED_SYNTAX",
    "CHAN_SET_RESTRICTED_ON",
    "CHAN_SET_RESTRICTED_OFF",
    "CHAN_SET_SECURE_SYNTAX",
    "CHAN_SET_SECURE_ON",
    "CHAN_SET_SECURE_OFF",
    "CHAN_SET_DEBUG_SYNTAX",
    "CHAN_SET_DEBUG_ON",
    "CHAN_SET_DEBUG_OFF",
    "CHAN_SET_ENFORCE_SYNTAX",
    "CHAN_SET_ENFORCE_ON",
    "CHAN_SET_ENFORCE_OFF",
    "CHAN_SET_MEMO_RESTRICTED_SYNTAX",
    "CHAN_SET_MEMO_RESTRICTED_ON",
    "CHAN_SET_MEMO_RESTRICTED_OFF",
    "CHAN_SET_NOEXPIRE_SYNTAX",
    "CHAN_SET_NOEXPIRE_ON",
    "CHAN_SET_NOEXPIRE_OFF",
    "CHAN_UNSET_SYNTAX",
    "CHAN_SUCCESSOR_UNSET",
    "CHAN_URL_UNSET",
    "CHAN_EMAIL_UNSET",
    "CHAN_ENTRY_MSG_UNSET",
    "CHAN_ACCESS_SYNTAX",
    "CHAN_ACCESS_ADD_SYNTAX",
    "CHAN_ACCESS_DEL_SYNTAX",
    "CHAN_ACCESS_LIST_SYNTAX",
    "CHAN_ACCESS_LISTLEVEL_SYNTAX",
    "CHAN_ACCESS_COUNT_SYNTAX",
    "CHAN_ACCESS_DISABLED",
    "CHAN_ACCESS_LEVEL_NONZERO",
    "CHAN_ACCESS_LEVEL_RANGE",
    "CHAN_ACCESS_NICKS_ONLY",
    "CHAN_ACCESS_NOOP",
    "CHAN_ACCESS_REACHED_LIMIT",
    "CHAN_ACCESS_LEVEL_UNCHANGED",
    "CHAN_ACCESS_LEVEL_CHANGED",
    "CHAN_ACCESS_ADDED",
    "CHAN_ACCESS_NOT_FOUND",
    "CHAN_ACCESS_DELETED",
    "CHAN_ACCESS_LIST_EMPTY",
    "CHAN_ACCESS_NO_MATCH",
    "CHAN_ACCESS_LIST_HEADER",
    "CHAN_ACCESS_LIST_FORMAT",
    "CHAN_ACCESS_COUNT",
    "CHAN_SOP_SYNTAX",
    "CHAN_AOP_SYNTAX",
    "CHAN_HOP_SYNTAX",
    "CHAN_VOP_SYNTAX",
    "CHAN_NOP_SYNTAX",
    "CHAN_SOP_LIST_SYNTAX",
    "CHAN_AOP_LIST_SYNTAX",
    "CHAN_HOP_LIST_SYNTAX",
    "CHAN_VOP_LIST_SYNTAX",
    "CHAN_NOP_LIST_SYNTAX",
    "CHAN_XOP_ADDED",
    "CHAN_XOP_LEVEL_CHANGED",
    "CHAN_XOP_LEVEL_UNCHANGED",
    "CHAN_XOP_NICKS_ONLY",
    "CHAN_XOP_NOOP",
    "CHAN_XOP_NICKS_ONLY_HOP",
    "CHAN_XOP_REACHED_LIMIT",
    "CHAN_XOP_REACHED_LIMIT_HOP",
    "CHAN_XOP_NOT_FOUND",
    "CHAN_XOP_DELETED",
    "CHAN_XOP_LIST_EMPTY",
    "CHAN_XOP_NO_MATCH",
    "CHAN_XOP_LIST_HEADER",
    "CHAN_XOP_COUNT",
    "CHAN_AKICK_SYNTAX",
    "CHAN_AKICK_LIST_SYNTAX",
    "CHAN_AKICK_VIEW_SYNTAX",
    "CHAN_AKICK_DISABLED",
    "CHAN_AKICK_ALREADY_EXISTS",
    "CHAN_AKICK_REACHED_LIMIT",
    "CHAN_AKICK_ADDED",
    "CHAN_AKICK_NOT_FOUND",
    "CHAN_AKICK_DELETED",
    "CHAN_AKICK_LIST_EMPTY",
    "CHAN_AKICK_NO_MATCH",
    "CHAN_AKICK_LIST_HEADER",
    "CHAN_AKICK_VIEW_FORMAT",
    "CHAN_AKICK_VIEW_UNUSED_FORMAT",
    "CHAN_AKICK_COUNT",
    "CHAN_AKICK_ENFORCE_DONE",
    "CHAN_LEVELS_SYNTAX",
    "CHAN_LEVELS_READONLY",
    "CHAN_LEVELS_RANGE",
    "CHAN_LEVELS_CHANGED",
    "CHAN_LEVELS_UNKNOWN",
    "CHAN_LEVELS_DISABLED",
    "CHAN_LEVELS_LIST_HEADER",
    "CHAN_LEVELS_LIST_DISABLED",
    "CHAN_LEVELS_LIST_FOUNDER",
    "CHAN_LEVELS_LIST_NORMAL",
    "CHAN_LEVELS_RESET",
    "CHAN_INFO_SYNTAX",
    "CHAN_INFO_HEADER",
    "CHAN_INFO_FOUNDER",
    "CHAN_INFO_SUCCESSOR",
    "CHAN_INFO_DESCRIPTION",
    "CHAN_INFO_ENTRYMSG",
    "CHAN_INFO_TIME_REGGED",
    "CHAN_INFO_LAST_USED",
    "CHAN_INFO_LAST_TOPIC",
    "CHAN_INFO_TOPIC_SET_BY",
    "CHAN_INFO_URL",
    "CHAN_INFO_EMAIL",
    "CHAN_INFO_OPTIONS",
    "CHAN_INFO_OPT_PRIVATE",
    "CHAN_INFO_OPT_KEEPTOPIC",
    "CHAN_INFO_OPT_TOPICLOCK",
    "CHAN_INFO_OPT_SECUREOPS",
    "CHAN_INFO_OPT_LEAVEOPS",
    "CHAN_INFO_OPT_RESTRICTED",
    "CHAN_INFO_OPT_SECURE",
    "CHAN_INFO_OPT_DEBUG",
    "CHAN_INFO_OPT_ENFORCE",
    "CHAN_INFO_OPT_MEMO_RESTRICTED",
    "CHAN_INFO_OPT_NONE",
    "CHAN_INFO_MODE_LOCK",
    "CHAN_INFO_NO_EXPIRE",
    "CHAN_INFO_SUSPEND_DETAILS",
    "CHAN_INFO_SUSPEND_REASON",
    "CHAN_INFO_SHOW_ALL",
    "CHAN_LIST_SYNTAX",
    "CHAN_LIST_OPER_SYNTAX",
    "CHAN_LIST_HEADER",
    "CHAN_LIST_NO_MATCH",
    "CHAN_INVITE_SYNTAX",
    "CHAN_INVITE_OK",
    "CHAN_OPVOICE_SYNTAX",
    "CHAN_OP_SUCCEEDED",
    "CHAN_OP_ALREADY",
    "CHAN_OP_FAILED",
    "CHAN_DEOP_SUCCEEDED",
    "CHAN_DEOP_ALREADY",
    "CHAN_DEOP_FAILED",
    "CHAN_VOICE_SUCCEEDED",
    "CHAN_VOICE_ALREADY",
    "CHAN_VOICE_FAILED",
    "CHAN_DEVOICE_SUCCEEDED",
    "CHAN_DEVOICE_ALREADY",
    "CHAN_DEVOICE_FAILED",
    "CHAN_HALFOP_SUCCEEDED",
    "CHAN_HALFOP_ALREADY",
    "CHAN_HALFOP_FAILED",
    "CHAN_DEHALFOP_SUCCEEDED",
    "CHAN_DEHALFOP_ALREADY",
    "CHAN_DEHALFOP_FAILED",
    "CHAN_PROTECT_SUCCEEDED",
    "CHAN_PROTECT_ALREADY",
    "CHAN_PROTECT_FAILED",
    "CHAN_DEPROTECT_SUCCEEDED",
    "CHAN_DEPROTECT_ALREADY",
    "CHAN_DEPROTECT_FAILED",
    "CHAN_UNBAN_SYNTAX",
    "CHAN_UNBANNED",
    "CHAN_KICK_SYNTAX",
    "CHAN_KICK_PROTECTED",
    "CHAN_KICKED",
    "CHAN_TOPIC_SYNTAX",
    "CHAN_CLEAR_SYNTAX",
    "CHAN_CLEARED_BANS",
    "CHAN_CLEARED_EXCEPTIONS",
    "CHAN_CLEARED_INVITES",
    "CHAN_CLEARED_MODES",
    "CHAN_CLEARED_OPS",
    "CHAN_CLEARED_HALFOPS",
    "CHAN_CLEARED_VOICES",
    "CHAN_CLEARED_USERS",
    "CHAN_GETPASS_SYNTAX",
    "CHAN_GETPASS_UNAVAILABLE",
    "CHAN_GETPASS_PASSWORD_IS",
    "CHAN_FORBID_SYNTAX",
    "CHAN_FORBID_SHORT_CHANNEL",
    "CHAN_FORBID_SUCCEEDED",
    "CHAN_FORBID_FAILED",
    "CHAN_SUSPEND_SYNTAX",
    "CHAN_SUSPEND_SUCCEEDED",
    "CHAN_SUSPEND_ALREADY_SUSPENDED",
    "CHAN_UNSUSPEND_SYNTAX",
    "CHAN_UNSUSPEND_SUCCEEDED",
    "CHAN_UNSUSPEND_NOT_SUSPENDED",
    "MEMO_HAVE_NEW_MEMO",
    "MEMO_HAVE_NEW_MEMOS",
    "MEMO_TYPE_READ_LAST",
    "MEMO_TYPE_READ_NUM",
    "MEMO_TYPE_LIST_NEW",
    "MEMO_AT_LIMIT",
    "MEMO_OVER_LIMIT",
    "MEMO_NEW_MEMO_ARRIVED",
    "MEMO_NEW_CHAN_MEMO_ARRIVED",
    "MEMO_HAVE_NO_MEMOS",
    "MEMO_HAVE_NO_NEW_MEMOS",
    "MEMO_DOES_NOT_EXIST",
    "MEMO_LIST_NOT_FOUND",
    "MEMO_SEND_SYNTAX",
    "MEMO_SEND_DISABLED",
    "MEMO_SEND_PLEASE_WAIT",
    "MEMO_SEND_CHAN_NOT_AVAIL",
    "MEMO_X_GETS_NO_MEMOS",
    "MEMO_X_HAS_TOO_MANY_MEMOS",
    "MEMO_SENT",
    "MEMO_SEND_FAILED",
    "MEMO_LIST_SYNTAX",
    "MEMO_LIST_MEMOS",
    "MEMO_LIST_NEW_MEMOS",
    "MEMO_LIST_HEADER",
    "MEMO_LIST_FORMAT",
    "MEMO_READ_SYNTAX",
    "MEMO_HEADER",
    "MEMO_CHAN_HEADER",
    "MEMO_SAVE_SYNTAX",
    "MEMO_SAVED_ONE",
    "MEMO_SAVED_SEVERAL",
    "MEMO_DEL_SYNTAX",
    "MEMO_DELETED_NONE",
    "MEMO_DELETED_ONE",
    "MEMO_DELETED_SEVERAL",
    "MEMO_DELETED_ALL",
    "MEMO_RENUMBER_ONLY_YOU",
    "MEMO_RENUMBER_DONE",
    "MEMO_SET_SYNTAX",
    "MEMO_SET_DISABLED",
    "MEMO_SET_UNKNOWN_OPTION",
    "MEMO_SET_NOTIFY_SYNTAX",
    "MEMO_SET_NOTIFY_ON",
    "MEMO_SET_NOTIFY_LOGON",
    "MEMO_SET_NOTIFY_NEW",
    "MEMO_SET_NOTIFY_OFF",
    "MEMO_SET_LIMIT_SYNTAX",
    "MEMO_SET_LIMIT_OPER_SYNTAX",
    "MEMO_SET_YOUR_LIMIT_FORBIDDEN",
    "MEMO_SET_LIMIT_FORBIDDEN",
    "MEMO_SET_YOUR_LIMIT_TOO_HIGH",
    "MEMO_SET_LIMIT_TOO_HIGH",
    "MEMO_SET_LIMIT_OVERFLOW",
    "MEMO_SET_YOUR_LIMIT",
    "MEMO_SET_YOUR_LIMIT_ZERO",
    "MEMO_SET_YOUR_LIMIT_DEFAULT",
    "MEMO_UNSET_YOUR_LIMIT",
    "MEMO_SET_LIMIT",
    "MEMO_SET_LIMIT_ZERO",
    "MEMO_SET_LIMIT_DEFAULT",
    "MEMO_UNSET_LIMIT",
    "MEMO_INFO_NO_MEMOS",
    "MEMO_INFO_MEMO",
    "MEMO_INFO_MEMO_UNREAD",
    "MEMO_INFO_MEMOS",
    "MEMO_INFO_MEMOS_ONE_UNREAD",
    "MEMO_INFO_MEMOS_SOME_UNREAD",
    "MEMO_INFO_MEMOS_ALL_UNREAD",
    "MEMO_INFO_LIMIT",
    "MEMO_INFO_HARD_LIMIT",
    "MEMO_INFO_LIMIT_ZERO",
    "MEMO_INFO_HARD_LIMIT_ZERO",
    "MEMO_INFO_NO_LIMIT",
    "MEMO_INFO_NOTIFY_OFF",
    "MEMO_INFO_NOTIFY_ON",
    "MEMO_INFO_NOTIFY_RECEIVE",
    "MEMO_INFO_NOTIFY_SIGNON",
    "MEMO_INFO_X_NO_MEMOS",
    "MEMO_INFO_X_MEMO",
    "MEMO_INFO_X_MEMO_UNREAD",
    "MEMO_INFO_X_MEMOS",
    "MEMO_INFO_X_MEMOS_ONE_UNREAD",
    "MEMO_INFO_X_MEMOS_SOME_UNREAD",
    "MEMO_INFO_X_MEMOS_ALL_UNREAD",
    "MEMO_INFO_X_LIMIT",
    "MEMO_INFO_X_HARD_LIMIT",
    "MEMO_INFO_X_NO_LIMIT",
    "MEMO_INFO_X_NOTIFY_OFF",
    "MEMO_INFO_X_NOTIFY_ON",
    "MEMO_INFO_X_NOTIFY_RECEIVE",
    "MEMO_INFO_X_NOTIFY_SIGNON",
    "MEMO_FORWARD_MAIL_SUBJECT",
    "MEMO_FORWARD_MULTIPLE_MAIL_SUBJECT",
    "MEMO_FORWARD_MAIL_BODY",
    "MEMO_FORWARD_CHANMEMO_MAIL_BODY",
    "MEMO_FORWARD_SYNTAX",
    "MEMO_FORWARD_NEED_EMAIL",
    "MEMO_FORWARD_PLEASE_WAIT",
    "MEMO_FORWARD_FAILED",
    "MEMO_FORWARDED_NONE",
    "MEMO_FORWARDED_ONE",
    "MEMO_FORWARDED_SEVERAL",
    "MEMO_FORWARDED_ALL",
    "MEMO_SET_FORWARD_SYNTAX",
    "MEMO_SET_FORWARD_ON",
    "MEMO_SET_FORWARD_COPY",
    "MEMO_SET_FORWARD_OFF",
    "MEMO_IGNORE_SYNTAX",
    "MEMO_IGNORE_ADD_SYNTAX",
    "MEMO_IGNORE_DEL_SYNTAX",
    "MEMO_IGNORE_LIST_FULL",
    "MEMO_IGNORE_ALREADY_PRESENT",
    "MEMO_IGNORE_ADDED",
    "MEMO_IGNORE_NOT_FOUND",
    "MEMO_IGNORE_DELETED",
    "MEMO_IGNORE_LIST_EMPTY",
    "MEMO_IGNORE_LIST",
    "MEMO_IGNORE_LIST_X_EMPTY",
    "MEMO_IGNORE_LIST_X",
    "OPER_BOUNCY_MODES",
    "OPER_BOUNCY_MODES_U_LINE",
    "OPER_GLOBAL_SYNTAX",
    "OPER_STATS_UNKNOWN_OPTION",
    "OPER_STATS_RESET_USER_COUNT",
    "OPER_STATS_CURRENT_USERS",
    "OPER_STATS_MAX_USERS",
    "OPER_STATS_UPTIME_DHM",
    "OPER_STATS_UPTIME_HM_MS",
    "OPER_STATS_KBYTES_READ",
    "OPER_STATS_KBYTES_WRITTEN",
    "OPER_STATS_NETBUF_SOCK",
    "OPER_STATS_NETBUF_SOCK_PERCENT",
    "OPER_STATS_NETBUF_TOTAL",
    "OPER_STATS_NETBUF_TOTAL_PERCENT",
    "OPER_STATS_ALL_USER_MEM",
    "OPER_STATS_ALL_CHANNEL_MEM",
    "OPER_STATS_ALL_SERVER_MEM",
    "OPER_STATS_ALL_NICKGROUPINFO_MEM",
    "OPER_STATS_ALL_NICKINFO_MEM",
    "OPER_STATS_ALL_CHANSERV_MEM",
    "OPER_STATS_ALL_STATSERV_MEM",
    "OPER_STATS_ALL_NEWS_MEM",
    "OPER_STATS_ALL_AKILL_MEM",
    "OPER_STATS_ALL_EXCEPTION_MEM",
    "OPER_STATS_ALL_SGLINE_MEM",
    "OPER_STATS_ALL_SQLINE_MEM",
    "OPER_STATS_ALL_SZLINE_MEM",
    "OPER_STATS_ALL_SESSION_MEM",
    "OPER_STATS_ALL_ELINE_MEM",
    "OPER_GETKEY_SYNTAX",
    "OPER_GETKEY_KEY_IS",
    "OPER_GETKEY_NO_KEY",
    "OPER_MODE_SYNTAX",
    "OPER_CLEARMODES_SYNTAX",
    "OPER_CLEARMODES_DONE",
    "OPER_CLEARMODES_ALL_DONE",
    "OPER_CLEARCHAN_SYNTAX",
    "OPER_CLEARCHAN_DONE",
    "OPER_KICK_SYNTAX",
    "OPER_ADMIN_SYNTAX",
    "OPER_ADMIN_ADD_SYNTAX",
    "OPER_ADMIN_DEL_SYNTAX",
    "OPER_ADMIN_NO_NICKSERV",
    "OPER_ADMIN_EXISTS",
    "OPER_ADMIN_ADDED",
    "OPER_ADMIN_TOO_MANY",
    "OPER_ADMIN_REMOVED",
    "OPER_ADMIN_NOT_FOUND",
    "OPER_ADMIN_LIST_HEADER",
    "OPER_OPER_SYNTAX",
    "OPER_OPER_ADD_SYNTAX",
    "OPER_OPER_DEL_SYNTAX",
    "OPER_OPER_NO_NICKSERV",
    "OPER_OPER_EXISTS",
    "OPER_OPER_ADDED",
    "OPER_OPER_TOO_MANY",
    "OPER_OPER_REMOVED",
    "OPER_OPER_NOT_FOUND",
    "OPER_OPER_LIST_HEADER",
    "OPER_MASKDATA_SYNTAX",
    "OPER_MASKDATA_ADD_SYNTAX",
    "OPER_MASKDATA_DEL_SYNTAX",
    "OPER_MASKDATA_CLEAR_SYNTAX",
    "OPER_MASKDATA_LIST_SYNTAX",
    "OPER_MASKDATA_CHECK_SYNTAX",
    "OPER_MASKDATA_LIST_FORMAT",
    "OPER_MASKDATA_VIEW_FORMAT",
    "OPER_MASKDATA_VIEW_UNUSED_FORMAT",
    "OPER_TOO_MANY_AKILLS",
    "OPER_AKILL_EXISTS",
    "OPER_AKILL_NO_NICK",
    "OPER_AKILL_MASK_TOO_GENERAL",
    "OPER_AKILL_EXPIRY_LIMITED",
    "OPER_AKILL_ADDED",
    "OPER_AKILL_REMOVED",
    "OPER_AKILL_CLEARED",
    "OPER_AKILL_NOT_FOUND",
    "OPER_AKILL_LIST_HEADER",
    "OPER_AKILL_LIST_EMPTY",
    "OPER_AKILL_LIST_NO_MATCH",
    "OPER_AKILL_CHECK_NO_MATCH",
    "OPER_AKILL_CHECK_HEADER",
    "OPER_AKILL_CHECK_TRAILER",
    "OPER_AKILL_COUNT",
    "OPER_AKILLCHAN_SYNTAX",
    "OPER_AKILLCHAN_AKILLED",
    "OPER_AKILLCHAN_KILLED",
    "OPER_AKILLCHAN_AKILLED_ONE",
    "OPER_AKILLCHAN_KILLED_ONE",
    "OPER_TOO_MANY_EXCLUDES",
    "OPER_EXCLUDE_EXISTS",
    "OPER_EXCLUDE_ADDED",
    "OPER_EXCLUDE_REMOVED",
    "OPER_EXCLUDE_CLEARED",
    "OPER_EXCLUDE_NOT_FOUND",
    "OPER_EXCLUDE_LIST_HEADER",
    "OPER_EXCLUDE_LIST_EMPTY",
    "OPER_EXCLUDE_LIST_NO_MATCH",
    "OPER_EXCLUDE_CHECK_NO_MATCH",
    "OPER_EXCLUDE_CHECK_HEADER",
    "OPER_EXCLUDE_CHECK_TRAILER",
    "OPER_EXCLUDE_COUNT",
    "OPER_TOO_MANY_SLINES",
    "OPER_SLINE_EXISTS",
    "OPER_SLINE_MASK_TOO_GENERAL",
    "OPER_SLINE_ADDED",
    "OPER_SLINE_REMOVED",
    "OPER_SLINE_CLEARED",
    "OPER_SLINE_NOT_FOUND",
    "OPER_SLINE_LIST_HEADER",
    "OPER_SLINE_LIST_EMPTY",
    "OPER_SLINE_LIST_NO_MATCH",
    "OPER_SLINE_CHECK_NO_MATCH",
    "OPER_SLINE_CHECK_HEADER",
    "OPER_SLINE_CHECK_TRAILER",
    "OPER_SLINE_COUNT",
    "OPER_SZLINE_NOT_AVAIL",
    "OPER_SU_SYNTAX",
    "OPER_SU_NO_PASSWORD",
    "OPER_SU_SUCCEEDED",
    "OPER_SU_FAILED",
    "OPER_SET_SYNTAX",
    "OPER_SET_IGNORE_ON",
    "OPER_SET_IGNORE_OFF",
    "OPER_SET_IGNORE_ERROR",
    "OPER_SET_READONLY_ON",
    "OPER_SET_READONLY_OFF",
    "OPER_SET_READONLY_ERROR",
    "OPER_SET_DEBUG_ON",
    "OPER_SET_DEBUG_OFF",
    "OPER_SET_DEBUG_LEVEL",
    "OPER_SET_DEBUG_ERROR",
    "OPER_SET_SUPASS_FAILED",
    "OPER_SET_SUPASS_OK",
    "OPER_SET_SUPASS_NONE",
    "OPER_SET_UNKNOWN_OPTION",
    "OPER_JUPE_SYNTAX",
    "OPER_JUPE_INVALID_NAME",
    "OPER_JUPE_ALREADY_JUPED",
    "OPER_RAW_SYNTAX",
    "OPER_UPDATE_SYNTAX",
    "OPER_UPDATE_FORCE_FAILED",
    "OPER_UPDATING",
    "OPER_UPDATE_COMPLETE",
    "OPER_UPDATE_FAILED",
    "OPER_REHASHING",
    "OPER_REHASHED",
    "OPER_REHASH_ERROR",
    "OPER_KILLCLONES_SYNTAX",
    "OPER_KILLCLONES_UNKNOWN_NICK",
    "OPER_KILLCLONES_KILLED",
    "OPER_KILLCLONES_KILLED_AKILL",
    "OPER_EXCEPTION_SYNTAX",
    "OPER_EXCEPTION_ADD_SYNTAX",
    "OPER_EXCEPTION_DEL_SYNTAX",
    "OPER_EXCEPTION_CLEAR_SYNTAX",
    "OPER_EXCEPTION_MOVE_SYNTAX",
    "OPER_EXCEPTION_LIST_SYNTAX",
    "OPER_EXCEPTION_ALREADY_PRESENT",
    "OPER_EXCEPTION_TOO_MANY",
    "OPER_EXCEPTION_ADDED",
    "OPER_EXCEPTION_MOVED",
    "OPER_EXCEPTION_NO_SUCH_ENTRY",
    "OPER_EXCEPTION_NOT_FOUND",
    "OPER_EXCEPTION_NO_MATCH",
    "OPER_EXCEPTION_EMPTY",
    "OPER_EXCEPTION_DELETED",
    "OPER_EXCEPTION_DELETED_ONE",
    "OPER_EXCEPTION_DELETED_SEVERAL",
    "OPER_EXCEPTION_CLEARED",
    "OPER_EXCEPTION_LIST_HEADER",
    "OPER_EXCEPTION_LIST_COLHEAD",
    "OPER_EXCEPTION_LIST_FORMAT",
    "OPER_EXCEPTION_VIEW_FORMAT",
    "OPER_EXCEPTION_CHECK_SYNTAX",
    "OPER_EXCEPTION_CHECK_NO_MATCH",
    "OPER_EXCEPTION_CHECK_HEADER",
    "OPER_EXCEPTION_CHECK_TRAILER",
    "OPER_EXCEPTION_COUNT",
    "OPER_EXCEPTION_INVALID_LIMIT",
    "OPER_EXCEPTION_INVALID_HOSTMASK",
    "OPER_SESSION_SYNTAX",
    "OPER_SESSION_LIST_SYNTAX",
    "OPER_SESSION_VIEW_SYNTAX",
    "OPER_SESSION_INVALID_THRESHOLD",
    "OPER_SESSION_NOT_FOUND",
    "OPER_SESSION_LIST_HEADER",
    "OPER_SESSION_LIST_COLHEAD",
    "OPER_SESSION_LIST_FORMAT",
    "OPER_SESSION_VIEW_FORMAT",
    "NEWS_LOGON_TEXT",
    "NEWS_OPER_TEXT",
    "NEWS_LOGON_SYNTAX",
    "NEWS_LOGON_LIST_HEADER",
    "NEWS_LOGON_LIST_ENTRY",
    "NEWS_LOGON_LIST_NONE",
    "NEWS_LOGON_ADD_SYNTAX",
    "NEWS_LOGON_ADD_FULL",
    "NEWS_LOGON_ADDED",
    "NEWS_LOGON_DEL_SYNTAX",
    "NEWS_LOGON_DEL_NOT_FOUND",
    "NEWS_LOGON_DELETED",
    "NEWS_LOGON_DEL_NONE",
    "NEWS_LOGON_DELETED_ALL",
    "NEWS_OPER_SYNTAX",
    "NEWS_OPER_LIST_HEADER",
    "NEWS_OPER_LIST_ENTRY",
    "NEWS_OPER_LIST_NONE",
    "NEWS_OPER_ADD_SYNTAX",
    "NEWS_OPER_ADD_FULL",
    "NEWS_OPER_ADDED",
    "NEWS_OPER_DEL_SYNTAX",
    "NEWS_OPER_DEL_NOT_FOUND",
    "NEWS_OPER_DELETED",
    "NEWS_OPER_DEL_NONE",
    "NEWS_OPER_DELETED_ALL",
    "NEWS_HELP_LOGON",
    "NEWS_HELP_OPER",
    "STAT_SERVERS_REMOVE_SERV_FIRST",
    "STAT_SERVERS_SERVER_EXISTS",
    "STAT_SERVERS_SYNTAX",
    "STAT_SERVERS_STATS_TOTAL",
    "STAT_SERVERS_STATS_ON_OFFLINE",
    "STAT_SERVERS_LASTQUIT_WAS",
    "STAT_SERVERS_LIST_HEADER",
    "STAT_SERVERS_LIST_FORMAT",
    "STAT_SERVERS_LIST_RESULTS",
    "STAT_SERVERS_VIEW_HEADER_ONLINE",
    "STAT_SERVERS_VIEW_HEADER_OFFLINE",
    "STAT_SERVERS_VIEW_LASTJOIN",
    "STAT_SERVERS_VIEW_LASTQUIT",
    "STAT_SERVERS_VIEW_QUITMSG",
    "STAT_SERVERS_VIEW_USERS_OPERS",
    "STAT_SERVERS_VIEW_RESULTS",
    "STAT_SERVERS_DELETE_SYNTAX",
    "STAT_SERVERS_DELETE_DONE",
    "STAT_SERVERS_COPY_SYNTAX",
    "STAT_SERVERS_COPY_DONE",
    "STAT_SERVERS_RENAME_SYNTAX",
    "STAT_SERVERS_RENAME_DONE",
    "STAT_USERS_SYNTAX",
    "STAT_USERS_TOTUSERS",
    "STAT_USERS_TOTOPERS",
    "STAT_USERS_SERVUSERS",
    "STAT_USERS_SERVOPERS",
    "CREG_ESTADO_REGISTRADO",
    "CREG_ESTADO_ENPROCESO_REG",
    "CREG_ESTADO_DENEGADO",
    "ADMIN_ELINE_VIEW_FORMAT",
    "ADMIN_ELINE_LIST_FORMAT",
    "ADMIN_ELINE_LIST_HEADER",
    "ADMIN_ELINE_LIST_COLHEAD",
    "ADMIN_ELINE_DELETED_ONE",
    "ADMIN_ELINE_DELETED_SEVERAL",
    "ADMIN_ELINE_DELETED",
    "ADMIN_ELINE_NO_MATCH",
    "ADMIN_ELINE_EMPTY",
    "NICK_HELP",
    "NICK_HELP_EXPIRES",
    "NICK_HELP_WARNING",
    "NICK_HELP_COMMANDS",
    "NICK_HELP_COMMANDS_AUTH",
    "NICK_HELP_COMMANDS_LINK",
    "NICK_HELP_COMMANDS_ACCESS",
    "NICK_HELP_COMMANDS_AJOIN",
    "NICK_HELP_COMMANDS_SET",
    "NICK_HELP_COMMANDS_LIST",
    "NICK_HELP_COMMANDS_LISTCHANS",
    "NICK_HELP_REGISTER",
    "NICK_HELP_REGISTER_EMAIL",
    "NICK_HELP_REGISTER_EMAIL_REQ",
    "NICK_HELP_REGISTER_EMAIL_AUTH",
    "NICK_HELP_REGISTER_END",
    "NICK_HELP_IDENTIFY",
    "NICK_HELP_DROP",
    "NICK_HELP_DROP_LINK",
    "NICK_HELP_DROP_END",
    "NICK_HELP_AUTH",
    "NICK_HELP_SENDAUTH",
    "NICK_HELP_REAUTH",
    "NICK_HELP_RESTOREMAIL",
    "NICK_HELP_LINK",
    "NICK_HELP_UNLINK",
    "NICK_HELP_LISTLINKS",
    "NICK_HELP_ACCESS",
    "NICK_HELP_REQUESTPASSWORD",
    "NICK_HELP_SET",
    "NICK_HELP_SET_OPTION_MAINNICK",
    "NICK_HELP_SET_END",
    "NICK_HELP_SET_PASSWORD",
    "NICK_HELP_SET_LANGUAGE",
    "NICK_HELP_SET_URL",
    "NICK_HELP_SET_EMAIL",
    "NICK_HELP_SET_HIDEMAIL",
    "NICK_HELP_SET_INFO",
    "NICK_HELP_SET_KILL",
    "NICK_HELP_SET_NEVEROP",
    "NICK_HELP_SET_SECURE",
    "NICK_HELP_SET_PRIVATE",
    "NICK_HELP_SET_NOOP",
    "NICK_HELP_SET_HIDE",
    "NICK_HELP_SET_TIMEZONE",
    "NICK_HELP_SET_MAINNICK",
    "NICK_HELP_UNSET",
    "NICK_HELP_UNSET_REQ_EMAIL",
    "NICK_HELP_RECOVER",
    "NICK_HELP_RELEASE",
    "NICK_HELP_GHOST",
    "NICK_HELP_INFO",
    "NICK_HELP_INFO_AUTH",
    "NICK_HELP_LISTCHANS",
    "NICK_HELP_LIST",
    "NICK_HELP_LIST_OPERSONLY",
    "NICK_HELP_LISTEMAIL",
    "NICK_HELP_STATUS",
    "NICK_HELP_AJOIN",
    "NICK_HELP_AJOIN_END",
    "NICK_HELP_AJOIN_END_CHANSERV",
    "NICK_OPER_HELP_COMMANDS",
    "NICK_OPER_HELP_COMMANDS_DROPEMAIL",
    "NICK_OPER_HELP_COMMANDS_GETPASS",
    "NICK_OPER_HELP_COMMANDS_FORBID",
    "NICK_OPER_HELP_COMMANDS_SETAUTH",
    "NICK_OPER_HELP_COMMANDS_END",
    "NICK_OPER_HELP_DROPNICK",
    "NICK_OPER_HELP_DROPEMAIL",
    "NICK_OPER_HELP_SET",
    "NICK_OPER_HELP_SET_NOEXPIRE",
    "NICK_OPER_HELP_UNSET",
    "NICK_OPER_HELP_OLD_UNLINK",
    "NICK_OPER_HELP_UNLINK",
    "NICK_OPER_HELP_OLD_LISTLINKS",
    "NICK_OPER_HELP_LISTLINKS",
    "NICK_OPER_HELP_ACCESS",
    "NICK_OPER_HELP_INFO",
    "NICK_OPER_HELP_LISTCHANS",
    "NICK_OPER_HELP_LIST",
    "NICK_OPER_HELP_LIST_AUTH",
    "NICK_OPER_HELP_LIST_END",
    "NICK_OPER_HELP_GETPASS",
    "NICK_OPER_HELP_UNFORBID",
    "NICK_OPER_HELP_FORBID",
    "NICK_OPER_HELP_SUSPEND",
    "NICK_OPER_HELP_UNSUSPEND",
    "NICK_OPER_HELP_AJOIN",
    "NICK_OPER_HELP_SETAUTH",
    "NICK_OPER_HELP_GETAUTH",
    "NICK_OPER_HELP_CLEARAUTH",
    "NICK_ADMIN_HELP_COMMANDS",
    "HOST_HELP",
    "HOST_HELP_ACTIVAR",
    "HOST_HELP_ANULAR",
    "HOST_OPER_HELP",
    "HOST_OPER_HELP_VHOST",
    "CHAN_HELP_REQSOP_LEVXOP",
    "CHAN_HELP_REQSOP_LEV",
    "CHAN_HELP_REQSOP_XOP",
    "CHAN_HELP_REQAOP_LEVXOP",
    "CHAN_HELP_REQAOP_LEV",
    "CHAN_HELP_REQAOP_XOP",
    "CHAN_HELP_REQHOP_LEVXOP",
    "CHAN_HELP_REQHOP_LEV",
    "CHAN_HELP_REQHOP_XOP",
    "CHAN_HELP_REQVOP_LEVXOP",
    "CHAN_HELP_REQVOP_LEV",
    "CHAN_HELP_REQVOP_XOP",
    "CHAN_HELP",
    "CHAN_HELP_EXPIRES",
    "CHAN_HELP_COMMANDS",
    "CHAN_HELP_COMMANDS_LIST",
    "CHAN_HELP_COMMANDS_AKICK",
    "CHAN_HELP_COMMANDS_LEVELS",
    "CHAN_HELP_COMMANDS_XOP",
    "CHAN_HELP_COMMANDS_HOP",
    "CHAN_HELP_COMMANDS_XOP_2",
    "CHAN_HELP_COMMANDS_OPVOICE",
    "CHAN_HELP_COMMANDS_HALFOP",
    "CHAN_HELP_COMMANDS_PROTECT",
    "CHAN_HELP_COMMANDS_INVITE",
    "CHAN_HELP_REGISTER",
    "CHAN_HELP_REGISTER_ADMINONLY",
    "CHAN_HELP_IDENTIFY",
    "CHAN_HELP_DROP",
    "CHAN_HELP_SET",
    "CHAN_HELP_SET_FOUNDER",
    "CHAN_HELP_SET_SUCCESSOR",
    "CHAN_HELP_SET_PASSWORD",
    "CHAN_HELP_SET_DESC",
    "CHAN_HELP_SET_URL",
    "CHAN_HELP_SET_EMAIL",
    "CHAN_HELP_SET_ENTRYMSG",
    "CHAN_HELP_SET_KEEPTOPIC",
    "CHAN_HELP_SET_TOPICLOCK",
    "CHAN_HELP_SET_MLOCK",
    "CHAN_HELP_SET_HIDE",
    "CHAN_HELP_SET_PRIVATE",
    "CHAN_HELP_SET_RESTRICTED",
    "CHAN_HELP_SET_SECURE",
    "CHAN_HELP_SET_SECUREOPS",
    "CHAN_HELP_SET_LEAVEOPS",
    "CHAN_HELP_SET_DEBUG",
    "CHAN_HELP_SET_ENFORCE",
    "CHAN_HELP_SET_MEMO_RESTRICTED",
    "CHAN_HELP_SET_NAME",
    "CHAN_HELP_SET_TOPIC",
    "CHAN_HELP_UNSET",
    "CHAN_HELP_SOP",
    "CHAN_HELP_SOP_MID1",
    "CHAN_HELP_SOP_MID1_CHANPROT",
    "CHAN_HELP_SOP_MID2",
    "CHAN_HELP_SOP_MID2_HALFOP",
    "CHAN_HELP_SOP_END",
    "CHAN_HELP_AOP",
    "CHAN_HELP_AOP_MID",
    "CHAN_HELP_AOP_MID_HALFOP",
    "CHAN_HELP_AOP_END",
    "CHAN_HELP_HOP",
    "CHAN_HELP_VOP",
    "CHAN_HELP_NOP",
    "CHAN_HELP_ACCESS",
    "CHAN_HELP_ACCESS_XOP",
    "CHAN_HELP_ACCESS_XOP_HALFOP",
    "CHAN_HELP_ACCESS_LEVELS",
    "CHAN_HELP_ACCESS_LEVELS_HALFOP",
    "CHAN_HELP_ACCESS_LEVELS_END",
    "CHAN_HELP_LEVELS",
    "CHAN_HELP_LEVELS_XOP",
    "CHAN_HELP_LEVELS_XOP_HOP",
    "CHAN_HELP_LEVELS_END",
    "CHAN_HELP_LEVELS_DESC",
    "CHAN_HELP_AKICK",
    "CHAN_HELP_INFO",
    "CHAN_HELP_LIST",
    "CHAN_HELP_LIST_OPERSONLY",
    "CHAN_HELP_OP",
    "CHAN_HELP_DEOP",
    "CHAN_HELP_VOICE",
    "CHAN_HELP_DEVOICE",
    "CHAN_HELP_HALFOP",
    "CHAN_HELP_DEHALFOP",
    "CHAN_HELP_PROTECT",
    "CHAN_HELP_DEPROTECT",
    "CHAN_HELP_INVITE",
    "CHAN_HELP_UNBAN",
    "CHAN_HELP_KICK",
    "CHAN_HELP_KICK_PROTECTED",
    "CHAN_HELP_TOPIC",
    "CHAN_HELP_CLEAR",
    "CHAN_HELP_CLEAR_EXCEPTIONS",
    "CHAN_HELP_CLEAR_INVITES",
    "CHAN_HELP_CLEAR_MID",
    "CHAN_HELP_CLEAR_HALFOPS",
    "CHAN_HELP_CLEAR_END",
    "CHAN_HELP_STATUS",
    "CHAN_HELP_DELSUCCESSOR",
    "CHAN_OPER_HELP_COMMANDS",
    "CHAN_OPER_HELP_COMMANDS_GETPASS",
    "CHAN_OPER_HELP_COMMANDS_FORBID",
    "CHAN_OPER_HELP_COMMANDS_END",
    "CHAN_OPER_HELP_DROPCHAN",
    "CHAN_OPER_HELP_SET",
    "CHAN_OPER_HELP_SET_NOEXPIRE",
    "CHAN_OPER_HELP_UNSET",
    "CHAN_OPER_HELP_INFO",
    "CHAN_OPER_HELP_LIST",
    "CHAN_OPER_HELP_GETPASS",
    "CHAN_OPER_HELP_FORBID",
    "CHAN_OPER_HELP_SUSPEND",
    "CHAN_OPER_HELP_UNSUSPEND",
    "CREG_HELP",
    "CREG_HELP_REGISTER",
    "CREG_HELP_ESTADO",
    "CREG_HELP_FOOTER",
    "CREG_OPER_HELP",
    "CREG_ADMIN_HELP",
    "CREG_OPER_HELP_APROBAR",
    "CREG_OPER_HELP_DENEGAR",
    "MEMO_HELP",
    "MEMO_HELP_EXPIRES",
    "MEMO_HELP_END_LEVELS",
    "MEMO_HELP_END_XOP",
    "MEMO_HELP_COMMANDS",
    "MEMO_HELP_COMMANDS_FORWARD",
    "MEMO_HELP_COMMANDS_SAVE",
    "MEMO_HELP_COMMANDS_DEL",
    "MEMO_HELP_COMMANDS_IGNORE",
    "MEMO_HELP_SEND",
    "MEMO_HELP_LIST",
    "MEMO_HELP_LIST_EXPIRE",
    "MEMO_HELP_READ",
    "MEMO_HELP_SAVE",
    "MEMO_HELP_DEL",
    "MEMO_HELP_RENUMBER",
    "MEMO_HELP_SET",
    "MEMO_HELP_SET_OPTION_FORWARD",
    "MEMO_HELP_SET_END",
    "MEMO_HELP_SET_NOTIFY",
    "MEMO_HELP_SET_LIMIT",
    "MEMO_HELP_INFO",
    "MEMO_OPER_HELP_COMMANDS",
    "MEMO_OPER_HELP_SET_LIMIT",
    "MEMO_OPER_HELP_INFO",
    "MEMO_HELP_FORWARD",
    "MEMO_HELP_SET_FORWARD",
    "MEMO_HELP_IGNORE",
    "OPER_HELP",
    "OPER_HELP_COMMANDS",
    "OPER_HELP_COMMANDS_SERVOPER",
    "OPER_HELP_COMMANDS_AKILL",
    "OPER_HELP_COMMANDS_EXCLUDE",
    "OPER_HELP_COMMANDS_SLINE",
    "OPER_HELP_COMMANDS_SESSION",
    "OPER_HELP_COMMANDS_NEWS",
    "OPER_HELP_COMMANDS_SERVADMIN",
    "OPER_HELP_COMMANDS_SERVROOT",
    "OPER_HELP_COMMANDS_RAW",
    "OPER_HELP_GLOBAL",
    "OPER_HELP_STATS",
    "OPER_HELP_SERVERMAP",
    "OPER_HELP_OPER",
    "OPER_HELP_ADMIN",
    "OPER_HELP_GETKEY",
    "OPER_HELP_MODE",
    "OPER_HELP_CLEARMODES",
    "OPER_HELP_CLEARCHAN",
    "OPER_HELP_KICK",
    "OPER_HELP_AKILL",
    "OPER_HELP_AKILL_OPERMAXEXPIRY",
    "OPER_HELP_AKILL_END",
    "OPER_HELP_AKILLCHAN",
    "OPER_HELP_EXCLUDE",
    "OPER_HELP_SGLINE",
    "OPER_HELP_SQLINE",
    "OPER_HELP_SQLINE_KILL",
    "OPER_HELP_SQLINE_NOKILL",
    "OPER_HELP_SQLINE_IGNOREOPERS",
    "OPER_HELP_SQLINE_END",
    "OPER_HELP_SZLINE",
    "OPER_HELP_EXCEPTION",
    "OPER_HELP_SESSION",
    "OPER_HELP_SU",
    "OPER_HELP_SET",
    "OPER_HELP_SET_READONLY",
    "OPER_HELP_SET_DEBUG",
    "OPER_HELP_SET_SUPASS",
    "OPER_HELP_JUPE",
    "OPER_HELP_RAW",
    "OPER_HELP_UPDATE",
    "OPER_HELP_QUIT",
    "OPER_HELP_SHUTDOWN",
    "OPER_HELP_RESTART",
    "OPER_HELP_REHASH",
    "OPER_HELP_KILLCLONES",
    "ADMIN_HELP",
    "ADMIN_ROOT_HELP",
    "DDB_HELP",
    "DDB_ROOT_HELP",
    "DDB_FOOTER_HELP",
    "STAT_HELP",
    "STAT_HELP_COMMANDS",
    "STAT_HELP_SERVERS",
    "STAT_HELP_USERS",
    "STAT_OPER_HELP_SERVERS",
    "OPER_HELP_KILL",
    "OPER_HELP_FJOIN",
    "OPER_HELP_FPART",
    "OPER_HELP_TGLINE",
    "OPER_HELP_HACK",
    "HELP_CABECERA",
    "HELP_FOOTER",
    "HELP_COMMAND_FOOTER",
    "GLOBAL_HELP",
    "GLOBAL_HELP_NICK",
    "GLOBAL_NICK_SYNTAX",
    "CHAN_INFORMA_UNSET",
    "CHAN_INFO_INFORMA",
    "CHAN_HELP_SET_INFORMA",
    "CHAN_INFORMA_CHANGED",
    "PREOP_HELP",
    "PREOP_FOOTER_HELP",
};
#endif
