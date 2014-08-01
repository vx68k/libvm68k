## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = parallel-tests
AM_CPPFLAGS = -DTEST
AM_CXXFLAGS = $(CPPUNIT_CFLAGS)

if CPPUNIT
check_PROGRAMS = runtest
endif

runtest_LDADD = $(LDADD) $(CPPUNIT_LIBS)
runtest_SOURCES = testmain.cpp

EXTRA_PROGRAMS = vm68k_test

vm68k_test_SOURCES = vm68k_test.cpp Test_vm68kdata.cpp Test_vm68kmem.cpp
vm68k_test_LDADD = ../src/libvm68k.la

noinst_HEADERS = Test_vm68kdata.h Test_vm68kmem.h

EXTRA_DIST = vm68k_test.cbproj
