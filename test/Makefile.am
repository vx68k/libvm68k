## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -DTEST -I$(top_srcdir)/src -I$(top_builddir)/src \
-I$(top_srcdir)/libvm68kapi -I$(top_builddir)/libvm68kapi
AM_CXXFLAGS = $(CPPUNIT_CFLAGS)

TEST_EXTENSIONS =
TESTS =
XFAIL_TESTS =
CLEANFILES =

if CPPUNIT
check_PROGRAMS = test_data.exec test_memory.exec test_context.exec
check_SCRIPTS = runtest

EXEC_TEST_LOG_COMPILER = ./runtest
TEST_EXTENSIONS += .exec
TESTS += $(check_PROGRAMS)

CLEANFILES += $(check_SCRIPTS)
endif

EXTRA_PROGRAMS = vm68k_test
noinst_HEADERS = xmlout.h Test_vm68kdata.h Test_vm68kmem.h

test_data_exec_LDFLAGS = -no-install
test_data_exec_SOURCES = testmain.cpp xmlout.cpp testdata.cpp
test_data_exec_LDADD = $(top_builddir)/libvm68kapi/libvm68kapi.la \
$(CPPUNIT_LIBS)

test_memory_exec_LDFLAGS = -no-install
test_memory_exec_SOURCES = testmain.cpp xmlout.cpp testmemory.cpp
test_memory_exec_LDADD = $(top_builddir)/libvm68kapi/libvm68kapi.la \
$(CPPUNIT_LIBS)

test_context_exec_LDFLAGS = -no-install
test_context_exec_SOURCES = testmain.cpp xmlout.cpp testcontext.cpp
test_context_exec_LDADD = $(top_builddir)/src/libvm68k.la \
$(top_builddir)/libvm68kapi/libvm68kapi.la $(CPPUNIT_LIBS)

vm68k_test_SOURCES = vm68k_test.cpp Test_vm68kdata.cpp Test_vm68kmem.cpp
vm68k_test_LDADD = ../src/libvm68k.la

EXTRA_DIST = runtest.in vm68k_test.cbproj

runtest: runtest.in Makefile
	cat  < $(srcdir)/runtest.in > $@
	chmod +x $@

clean-local:
	rm -rf test-reports
