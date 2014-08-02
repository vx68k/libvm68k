## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = parallel-tests
AM_CPPFLAGS = -DTEST -I$(top_builddir)/src -I$(top_srcdir)/src
AM_CXXFLAGS = $(CPPUNIT_CFLAGS)
AM_TEST_LOG_FLAGS = -x $(@:.log=.xml)

TESTS =
CLEANFILES =

if CPPUNIT
check_PROGRAMS = runtest
TEST_LOG_COMPILER = ./runtest

TESTS += unit.test
CLEANFILES += unit.test $(TEST_LOGS:.log=.xml)
endif

EXTRA_PROGRAMS = vm68k_test

runtest_LDADD = $(LDADD) $(CPPUNIT_LIBS)
runtest_SOURCES = testmain.cpp testdata.cpp

vm68k_test_SOURCES = vm68k_test.cpp Test_vm68kdata.cpp Test_vm68kmem.cpp
vm68k_test_LDADD = ../src/libvm68k.la

noinst_HEADERS = Test_vm68kdata.h Test_vm68kmem.h

EXTRA_DIST = vm68k_test.cbproj

unit.test:
	touch $@
