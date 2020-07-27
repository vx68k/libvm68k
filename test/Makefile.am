## Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = -DTEST -I$(top_srcdir)/libvm68k -I$(top_builddir)/libvm68k \
-I$(top_srcdir)/libvm68kapi -I$(top_builddir)/libvm68kapi
AM_CXXFLAGS = $(CPPUNIT_CFLAGS)

TEST_EXTENSIONS = .exec
TESTS =
XFAIL_TESTS =
CLEANFILES =

if CPPUNIT
check_PROGRAMS = test_data.exec test_memory.exec test_runtime.exec
check_SCRIPTS = runtest

EXEC_LOG_COMPILER = $(SHELL) ./runtest
TESTS += $(check_PROGRAMS)
CLEANFILES += $(check_SCRIPTS)
endif

EXTRA_PROGRAMS = vm68k_test
noinst_HEADERS = xmlreport.h Test_vm68kdata.h Test_vm68kmem.h

test_data_exec_LDFLAGS = -no-install
test_data_exec_LDADD = $(top_builddir)/libvm68kapi/libvm68kapi.la \
$(CPPUNIT_LIBS)
test_data_exec_SOURCES = main.cpp xmlreport.cpp test_data.cpp

test_memory_exec_LDFLAGS = -no-install
test_memory_exec_LDADD = $(top_builddir)/libvm68kapi/libvm68kapi.la \
$(CPPUNIT_LIBS)
test_memory_exec_SOURCES = main.cpp xmlreport.cpp test_memory.cpp

test_runtime_exec_LDFLAGS = -no-install
test_runtime_exec_LDADD = $(top_builddir)/libvm68k/libvm68k.la \
$(top_builddir)/libvm68kapi/libvm68kapi.la $(CPPUNIT_LIBS)
test_runtime_exec_SOURCES = main.cpp xmlreport.cpp test_runtime.cpp

vm68k_test_SOURCES = vm68k_test.cpp Test_vm68kdata.cpp Test_vm68kmem.cpp
vm68k_test_LDADD = ../libvm68k/libvm68k.la

EXTRA_DIST = runtest.in vm68k_test.cbproj

runtest: $(srcdir)/runtest.in $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status --file=$(subdir)/$@
	chmod +x $@

clean-local:
	rm -rf test-reports
