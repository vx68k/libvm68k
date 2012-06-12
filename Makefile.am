## Process this file with automake to produce Makefile.in.

ACLOCAL_AMFLAGS = -Im4
# Uses foreign for now.
AUTOMAKE_OPTIONS = foreign

SUBDIRS = src test

vm68kincludedir = $(includedir)/vm68k

nodist_vm68kinclude_HEADERS = vm68kint.h
vm68kinclude_HEADERS = config/vm68kint_std11.h
noinst_HEADERS = config/vm68kint_tr1.h config/vm68kint_boost.h \
config/vm68kint_classic.h

EXTRA_DIST = config/win32
