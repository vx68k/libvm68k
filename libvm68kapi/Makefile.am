## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -D_VM68K_API_LIBRARY

lib_LTLIBRARIES = libvm68kapi.la

nobase_include_HEADERS = vm68k/data vm68k/memory \
bits/vm68kapi.h bits/vm68k/data.h bits/vm68k/memory.h \
bits/vm68k/virtual_machine.h

libvm68kapi_la_LDFLAGS = -version-info 1:0:0
libvm68kapi_la_SOURCES = data.cpp memory.cpp virtual_machine.cpp
