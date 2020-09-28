## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -D_LIBVM68KAPI

pkgconfigdir = $(libdir)/pkgconfig

lib_LTLIBRARIES = libvm68kapi.la

EXTRA_DIST = vm68kapi.pc.in

pkgconfig_DATA = vm68kapi.pc

nobase_include_HEADERS = vm68k/data vm68k/memory \
vm68k/register \
vm68k/instruction \
bits/vm68kapi.h bits/vm68k/data.h \
bits/vm68k/memory_map.h \
bits/vm68k/memory_exception.h \
bits/vm68k/register.h \
bits/vm68k/instruction.h \
bits/vm68k/instruction_decoder.h \
bits/vm68k/virtual_machine.h

libvm68kapi_la_LDFLAGS = -no-undefined -version-info 1:0:0
libvm68kapi_la_SOURCES = \
data.cpp \
memory_map.cpp \
memory_exception.cpp \
register.cpp \
instruction.cpp \
virtual_machine.cpp

CLEANFILES = $(pkgconfig_DATA)

vm68kapi.pc: $(srcdir)/vm68kapi.pc.in $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status --file=$(subdir)/$@

installcheck-local:
	if test -n '$(PKG_CONFIG)'; then \
	    export PKG_CONFIG_PATH=$(pkgconfigdir); \
	    $(PKG_CONFIG) --exists --exact-version=$(VERSION) vm68kapi; \
	fi
