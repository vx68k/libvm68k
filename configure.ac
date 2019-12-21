# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([libvm68k], [2.0],
[https://bitbucket.org/kazssym/libvm68k/issues/new],,
[http://www.vx68k.org/libvm68k])
AC_CONFIG_SRCDIR([src/context.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
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
PKG_CHECK_MODULES([CPPUNIT], [cppunit],, [no_cppunit=yes])
AM_CONDITIONAL([CPPUNIT], [test "$no_cppunit" != yes])

AC_CONFIG_FILES([Makefile config/Makefile libvm68kapi/Makefile
src/Makefile test/Makefile])
AC_CONFIG_HEADERS([config.h])
AC_OUTPUT
