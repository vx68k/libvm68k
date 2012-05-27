## Process this file with automake to produce Makefile.in.

ACLOCAL_AMFLAGS = -Im4
# Uses foreign for now.
AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(srcdir)/config -I$(srcdir)/src

vm68kincludedir = $(includedir)/vm68k

lib_LTLIBRARIES = libvm68k.la

libvm68k_la_SOURCES = src/vm68kmem.cpp
EXTRA_libvm68k_la_SOURCES = src/win32dll.cpp

nodist_vm68kinclude_HEADERS = vm68kint.h
vm68kinclude_HEADERS = config/vm68kint_std11.h \
src/vm68kdef.h src/vm68kmem.h
noinst_HEADERS = config/vm68kint_tr1.h config/vm68kint_boost.h \
config/vm68kint_classic.h

EXTRA_DIST = config/win32
