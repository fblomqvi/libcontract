# Must init the autoconf setup
# The first parameter is project name
# second is version number
# third is bug report address
AC_INIT([$prefix$contract], [1.0], [https://github.com/fblomqvi/libcontract])

# Force autoconf to be at least this version number:
AC_PREREQ([2.69])

# Safety check - list a source file that wouldn't be in other directories:
AC_CONFIG_SRCDIR([src/contract.c])

# Put autotools auxiliary files in subdirectories to reduce clutter:
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Init automake, and specify this program use relaxed structures.
# i.e. this program doesn't follow the gnu coding standards, and doesn't have
# ChangeLog, COPYING, AUTHORS, INSTALL, README etc. files.
AM_INIT_AUTOMAKE([1.11 -Wall -Werror foreign subdir-objects silent-rules])
AM_SILENT_RULES([yes])

# Check for C and CPP compiler
AC_PROG_CC
AC_PROG_CXX

# We can add more checks in this section
#AC_PROG_RANLIB
AM_PROG_AR
LT_INIT

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h] [stddef.h])
if [test -z "$HAVE_stdlib.h"] ; then
    AC_MSG_ERROR([Cannot find stdlib.h!])
fi
if [test -z "$HAVE_stddef.h"] ; then
    AC_MSG_ERROR([Cannot find stddef.h!])
fi

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([abort])

# Example of default-enabled feature
AC_ARG_ENABLE([tests],
    AS_HELP_STRING([--disable-tests], [Disable self tests]))

AS_IF([test "x$enable_tests" = "xno"], [
    # Do not build any self tests
    with_check=no
    with_cmocka=no
    with_CppUTest=no
    with_gtest=no
])

#AM_CONDITIONAL([BUILD_TESTS], [test "x$enable_tests" != "xno"])

AC_ARG_WITH([check],
    AS_HELP_STRING([--without-check], [Do not build unit tests that require check]))

AS_IF([test "x$with_check" != "xno"],
      [PKG_CHECK_MODULES([check], [check], [have_check=yes], 
		         [AC_MSG_ERROR([check is required but not found])])],
      [have_check=no])

AM_CONDITIONAL([BUILD_CHECK_TESTS], [test "x$have_check" = "xyes"])

AC_ARG_WITH([cmocka],
    AS_HELP_STRING([--without-cmocka], [Do not build unit tests that require cmocka]))

AS_IF([test "x$with_cmocka" != "xno"],
      [PKG_CHECK_MODULES([cmocka], [cmocka], [have_cmocka=yes], 
		         [AC_MSG_ERROR([cmocka is required but not found])])],
      [have_cmocka=no])

AM_CONDITIONAL([BUILD_CMOCKA_TESTS], [test "x$have_cmocka" = "xyes"])

AC_ARG_WITH([CppUTest],
    AS_HELP_STRING([--without-CppUTest], [Do not build unit tests that require CppUTest]))

AS_IF([test "x$with_CppUTest" != "xno"],
      [PKG_CHECK_MODULES([CppUTest], [cpputest], [have_CppUTest=yes], 
		         [AC_MSG_ERROR([CppUTest is required but not found])])],
      [have_CppUTest=no])

AM_CONDITIONAL([BUILD_CPPUTEST_TESTS], [test "x$have_CppUTest" = "xyes"])

AC_ARG_WITH([gtest],
    AS_HELP_STRING([--without-gtest], [Do not build unit tests that require gtest]))

AS_IF([test "x$with_gtest" != "xno"],
      [PKG_CHECK_MODULES([GTest], [gtest], [have_gtest=yes], 
		         [AC_MSG_ERROR([gtest is required but not found])])],
      [have_gtest=no])

AM_CONDITIONAL([BUILD_GTEST_TESTS], [test "x$have_gtest" = "xyes"])

# Tells automake to create a Makefile
# See https://www.gnu.org/software/automake/manual/html_node/Requirements.html
#AC_CONFIG_FILES([Makefile tests/Makefile tests/ut/Makefile contract.pc])
AC_CONFIG_FILES([Makefile $prefix$contract.pc])

# Generate the output
AC_OUTPUT
