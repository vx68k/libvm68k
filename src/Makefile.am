## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -I$(top_srcdir)/config \
-I$(top_srcdir)/libvm68kapi -I$(top_builddir)/libvm68kapi

lib_LTLIBRARIES = libvm68k.la

libvm68k_la_LDFLAGS = -version-info 1:0:0
libvm68k_la_SOURCES = context.cpp
EXTRA_libvm68k_la_SOURCES = win32dll.cpp

nobase_include_HEADERS = \
bits/vm68kcore.h bits/vm68k/register.h bits/vm68k/context.h
noinst_HEADERS = vm68kPCH1.h

EXTRA_DIST = vm68k.cbproj ModelSupport_vm68k
