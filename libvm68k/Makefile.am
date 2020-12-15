## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -D_LIBVM68K \
-I$(top_srcdir)/libvm68kapi

pkgconfigdir = $(libdir)/pkgconfig

lib_LTLIBRARIES = libvm68k.la

EXTRA_DIST = vm68k.pc.in vm68k.cbproj ModelSupport_vm68k

pkgconfig_DATA = vm68k.pc

nobase_include_HEADERS = \
vm68k/runtime \
vm68k/pipeline \
bits/vm68kdef.h \
bits/vm68k/read_write_memory.h \
bits/vm68k/register_file.h \
bits/vm68k/execution_context.h \
bits/vm68k/executor.h \
bits/vm68k/instruction_decoder.h \
bits/vm68k/pipeline.h
noinst_HEADERS = vm68kPCH1.h

libvm68k_la_LDFLAGS = -no-undefined -version-info 1:0:0
libvm68k_la_SOURCES = \
read_write_memory.cpp \
execution_context.cpp \
executor.cpp \
instruction_decoder.cpp \
pipeline.cpp
libvm68k_la_LIBADD = -L$(top_builddir)/libvm68kapi -lvm68kapi

CLEANFILES = $(pkgconfig_DATA)

vm68k.pc: $(srcdir)/vm68k.pc.in $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status --file=$(subdir)/$@

installcheck-local:
	if test -n '$(PKG_CONFIG)'; then \
	    export PKG_CONFIG_PATH=$(pkgconfigdir); \
	    $(PKG_CONFIG) --exists --exact-version=$(VERSION) vm68k; \
	fi
