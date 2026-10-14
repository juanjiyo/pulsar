# Makefile for AdminServ modules.
#
# IRC Services is copyright (c) 1996-2009 Andrew Church.
#     E-mail: <achurch@achurch.org>
# Parts written by Andrew Kempe and others.
# This program is free but copyrighted software; see the file GPL.txt for
# details.

###########################################################################

include ../../Makefile.inc

MODULES = main.so sessions.so elines.so

INCLUDES = $(TOPDIR)/commands.h $(TOPDIR)/language.h
INCLUDES-main.o = $(TOPDIR)/databases.h \
	$(TOPDIR)/modules/operserv/operserv.h \
	$(TOPDIR)/modules/nickserv/nickserv.h \
	$(TOPDIR)/modules/chanserv/chanserv.h

INCLUDES-sessions.o = $(TOPDIR)/modules/operserv/maskdata.h $(TOPDIR)/modules/operserv/akill.h
INCLUDES-elines.o = $(TOPDIR)/modules/operserv/maskdata.h $(TOPDIR)/modules/operserv/akill.h
include ../Makerules

###########################################################################
