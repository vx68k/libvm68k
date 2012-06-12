## Process this file with automake to produce Makefile.in.

vm68kincludedir = $(includedir)/vm68k

AM_CPPFLAGS = -I$(srcdir)/config -I$(srcdir)/src

lib_LTLIBRARIES = libvm68k.la

libvm68k_la_SOURCES = vm68kmem.cpp
EXTRA_libvm68k_la_SOURCES = win32dll.cpp

vm68kinclude_HEADERS = vm68kdef.h vm68kmem.h

EXTRA_DIST = #vm68k.cbproj
