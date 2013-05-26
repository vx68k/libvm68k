#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([libvm68k], [2.0x], [vx68k@googlegroups.com])
AC_CONFIG_SRCDIR([src/bits/vm68kmemory.cpp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
LT_INIT
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile config/Makefile src/Makefile test/Makefile])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([tr1/cstdint boost/cstdint.hpp],,,
[// no default includes])
if test "$ac_cv_header_tr1_cstdint" = yes; then
    vm68kint=vm68kint_tr1
elif test "$ac_cv_header_boost_cstdint_hpp" = yes; then
    vm68kint=vm68kint_boost
else
    vm68kint=vm68kint_classic
fi
AC_CONFIG_LINKS([vm68kint.h:config/$vm68kint.h])
AC_LANG_POP([C++])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT
