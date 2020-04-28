# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([libvm68k], [2-alpha.2],
[https://bitbucket.org/vx68k/libvm68k/issues/new],,
[https://www.vx68k.org/vx68k/libvm68k])
AC_CONFIG_SRCDIR([src/context.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
LT_PREREQ([2.4.6])
LT_INIT()
AM_INIT_AUTOMAKE([no-define])
# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
PKG_CHECK_MODULES([CPPUNIT], [cppunit],, [no_cppunit=yes])
AM_CONDITIONAL([CPPUNIT], [test "$no_cppunit" != yes])

AC_CONFIG_FILES([Makefile config/Makefile libvm68kapi/Makefile
src/Makefile test/Makefile])
AC_CONFIG_HEADERS([config.h])
AC_OUTPUT
