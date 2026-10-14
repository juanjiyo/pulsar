# Makefile for data directory.
#
# IRC Services is copyright (c) 1996-2009 Andrew Church.
#     E-mail: <achurch@achurch.org>
# Parts written by Andrew Kempe and others.
# This program is free but copyrighted software; see the file GPL.txt for
# details.

include ../Makefile.inc
TOPDIR=..

all: ejemplo-services.conf ejemplo-modules.conf

%.conf: %.conf.in Makefile ../Makefile.inc
	sed 's/@PROGRAM@/$(PROGRAM)/g' <$< >$@

install: all $(DATDEST)/helpfiles $(DATDEST)/PZhelpfiles
	$(INSTALL_DAT) ejemplo-services.conf "$(INSTALL_PREFIX)$(DATDEST)/ejemplo-$(PROGRAM).conf"
	$(INSTALL_DAT) ejemplo-modules.conf "$(INSTALL_PREFIX)$(DATDEST)/ejemplo-modules.conf"

$(DATDEST)/helpfiles:
	$(CP_ALL) helpfiles "$(DATDEST)"

$(DATDEST)/PZhelpfiles:
	$(CP_ALL) PZhelpfiles "$(DATDEST)"

