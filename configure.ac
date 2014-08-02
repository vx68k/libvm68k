# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([libvm68k], [2.0],
[https://bitbucket.org/kazssym/libvm68k/issues/new],,
[http://www.vx68k.org/libvm68k])
AC_CONFIG_SRCDIR([src/bits/vm68kmemory.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([no-define])
LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
XX_PROG_CXX_STD11

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T

# Checks for library functions.
AM_PATH_CPPUNIT([1.12.1])
AM_CONDITIONAL([CPPUNIT], [test "$no_cppunit" != yes])

AC_CONFIG_FILES([Makefile config/Makefile src/Makefile test/Makefile])
AC_OUTPUT
