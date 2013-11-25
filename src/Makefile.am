## Process this file with automake to produce Makefile.in.

vm68kincludedir = $(includedir)/vm68k

AM_CPPFLAGS = -I$(srcdir)/config -I$(srcdir)/src

lib_LTLIBRARIES = libvm68k.la

libvm68k_la_SOURCES = \
bits/vm68kdata.cpp bits/vm68kmemory.cpp bits/vm68kcontext.cpp
EXTRA_libvm68k_la_SOURCES = win32dll.cpp

vm68kinclude_HEADERS = vm68k bits/vm68kdef.h \
bits/vm68kdata.h bits/vm68kmemory.h bits/vm68kcontext.h

EXTRA_DIST = vm68k.cbproj ModelSupport_vm68k
