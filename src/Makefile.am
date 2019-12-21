## Process this file with automake to produce Makefile.in.

vm68kincludedir = $(includedir)/vm68k

AM_CPPFLAGS = -I$(top_srcdir)/config \
-I$(top_srcdir)/libvm68kapi -I$(top_builddir)/libvm68kapi

lib_LTLIBRARIES = libvm68k.la

libvm68k_la_SOURCES = data.cpp bits/vm68kcontext.cpp
EXTRA_libvm68k_la_SOURCES = win32dll.cpp

nobase_vm68kinclude_HEADERS = vm68k \
bits/vm68k/data.h bits/vm68k/context.h
noinst_HEADERS = vm68kPCH1.h

EXTRA_DIST = vm68k.cbproj ModelSupport_vm68k
