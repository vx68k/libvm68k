## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -DTEST -I$(top_builddir)/src -I$(top_srcdir)/src \
-I$(top_srcdir)/libvm68kapi -I$(top_builddir)/libvm68kapi
AM_CXXFLAGS = $(CPPUNIT_CFLAGS)

TESTS =
XFAIL_TESTS =
CLEANFILES =

if CPPUNIT
check_SCRIPTS = runtest
check_PROGRAMS = data.test memory.test context.test
TEST_LOG_COMPILER = ./runtest

TESTS += $(check_PROGRAMS)
XFAIL_TESTS += context.test
CLEANFILES += $(check_SCRIPTS) test-reports/*
endif

EXTRA_PROGRAMS = vm68k_test

data_test_LDFLAGS = -no-install
data_test_SOURCES = testmain.cpp testdata.cpp
data_test_LDADD = $(top_builddir)/libvm68kapi/libvm68kapi.la $(CPPUNIT_LIBS)

memory_test_LDFLAGS = -no-install
memory_test_SOURCES = testmain.cpp testmemory.cpp
memory_test_LDADD = $(top_builddir)/libvm68kapi/libvm68kapi.la $(CPPUNIT_LIBS)

context_test_LDFLAGS = -no-install
context_test_SOURCES = testmain.cpp testcontext.cpp
context_test_LDADD = $(top_builddir)/src/libvm68k.la \
$(top_builddir)/libvm68kapi/libvm68kapi.la $(CPPUNIT_LIBS)

vm68k_test_SOURCES = vm68k_test.cpp Test_vm68kdata.cpp Test_vm68kmem.cpp
vm68k_test_LDADD = ../src/libvm68k.la

noinst_HEADERS = Test_vm68kdata.h Test_vm68kmem.h

EXTRA_DIST = runtest.in vm68k_test.cbproj

runtest: runtest.in Makefile
	cat  < $(srcdir)/runtest.in > $@
	chmod +x $@
