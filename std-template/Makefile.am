ACLOCAL_AMFLAGS = -I m4

WARNINGS = -Wall -Wextra -pedantic
INCLUDE_DIRS = -I$(srcdir)/include/

AM_CFLAGS = $(WARNINGS) $(INCLUDE_DIRS)
AM_CXXFLAGS = $(WARNINGS) $(INCLUDE_DIRS)

LIBCONTRACT = lib$prefix$contract.la
lib_LTLIBRARIES = $(LIBCONTRACT)
lib$prefix$contract_la_SOURCES = src/contract.c


INCDIR = include/$prefix$contract
include_contractdir = $(includedir)/$prefix$contract
include_contract_HEADERS = $(INCDIR)/contract.h

UT_HEADER_DIR = $(INCDIR)/ut
include_contract_utdir = $(include_contractdir)/ut
include_contract_ut_HEADERS = $(UT_HEADER_DIR)/framework.h \
				$(UT_HEADER_DIR)/check.h \
				$(UT_HEADER_DIR)/cmocka.h \
				$(UT_HEADER_DIR)/CppUTest.h \
				$(UT_HEADER_DIR)/gtest.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = $prefix$contract.pc

if BUILD_CHECK_TESTS
CHECK_UT_TESTS = tests/test_contract_off \
	tests/test_contract_default \
	tests/test_contract_audit \
	tests/test_contract_level_override \
	tests/ut/test_ut_nested_checks \
	tests/ut/test_ut_check
endif

if BUILD_CMOCKA_TESTS
CMOCKA_UT_TEST = tests/ut/test_ut_cmocka
endif

if BUILD_CPPUTEST_TESTS
CPPUTEST_UT_TESTS = tests/test_basics \
		tests/ut/test_ut_cpputest
endif

if BUILD_GTEST_TESTS
GTEST_UT_TEST = tests/ut/test_ut_gtest
endif

# Build Tests that test the UT framework and macros
check_LIBRARIES = libtest_helper.a
libtest_helper_a_SOURCES = tests/test_helper.c tests/test_helper.h
libtest_helper_a_CFLAGS = $(AM_CFLAGS) -D$PREFIX$CONTRACT_TEST

TESTS = $(CHECK_UT_TESTS) $(CPPUTEST_UT_TESTS) $(CMOCKA_UT_TEST) $(GTEST_UT_TEST)

check_PROGRAMS = $(TESTS)

STD_TEST_HEADER = tests/standard_tests.h
TESTDIR = $(srcdir)/tests

if BUILD_CPPUTEST_TESTS
tests_test_basics_SOURCES = tests/test_basics.cc
tests_test_basics_LDADD = $(LIBCONTRACT)
tests_test_basics_CXXFLAGS = $(CppUTest_CFLAGS) $(AM_CXXFLAGS)
tests_test_basics_LDFLAGS = $(CppUTest_LIBS)

tests_ut_test_ut_cpputest_SOURCES = tests/ut/test_ut_cpputest.cc
tests_ut_test_ut_cpputest_LDADD = $(LIBCONTRACT) $(check_LIBRARIES)
tests_ut_test_ut_cpputest_CXXFLAGS = -I$(TESTDIR) $(CppUTest_CFLAGS) $(AM_CXXFLAGS)
tests_ut_test_ut_cpputest_LDFLAGS = $(CppUTest_LIBS)
endif

if BUILD_CHECK_TESTS
tests_test_contract_off_SOURCES = tests/test_contract_off.c \
				tests/test_helper.c \
				$(STD_TEST_HEADER)
tests_test_contract_off_LDADD = $(LIBCONTRACT)
tests_test_contract_off_CFLAGS = $(check_CFLAGS) $(AM_CFLAGS) -D$PREFIX$CONTRACT_OFF
tests_test_contract_off_LDFLAGS = $(check_LIBS)

tests_test_contract_default_SOURCES = tests/test_contract_default.c \
				tests/test_helper.c \
				$(STD_TEST_HEADER)
tests_test_contract_default_LDADD = $(LIBCONTRACT)
tests_test_contract_default_CFLAGS = $(check_CFLAGS) $(AM_CFLAGS) -D$PREFIX$CONTRACT_DEFAULT
tests_test_contract_default_LDFLAGS = $(check_LIBS)

tests_test_contract_audit_SOURCES = tests/test_contract_audit.c \
				tests/test_helper.c \
				$(STD_TEST_HEADER)
tests_test_contract_audit_LDADD = $(LIBCONTRACT)
tests_test_contract_audit_CFLAGS = $(check_CFLAGS) $(AM_CFLAGS) -D$PREFIX$CONTRACT_AUDIT
tests_test_contract_audit_LDFLAGS = $(check_LIBS)

tests_test_contract_level_override_SOURCES = tests/test_contract_level_override.c \
						tests/test_helper.c \
						$(STD_TEST_HEADER)
tests_test_contract_level_override_LDADD = $(LIBCONTRACT)
tests_test_contract_level_override_CFLAGS = $(check_CFLAGS) $(AM_CFLAGS) \
	-D$PREFIX$CONTRACT_AUDIT \
	-D$PREFIX$CONTRACT_MODE_DEFAULT=_$PREFIX$CONTRACT_IGNORE_ \
	-D$PREFIX$CONTRACT_MODE_AUDIT=_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_ \
	-D$PREFIX$CONTRACT_MODE_AXIOM=_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_
tests_test_contract_level_override_LDFLAGS = $(check_LIBS)

tests_ut_test_ut_nested_checks_SOURCES = tests/ut/test_ut_nested_checks.c
tests_ut_test_ut_nested_checks_LDADD = $(LIBCONTRACT) $(check_LIBRARIES)
tests_ut_test_ut_nested_checks_CFLAGS = -I$(TESTDIR) $(check_CFLAGS) $(AM_CFLAGS)
tests_ut_test_ut_nested_checks_LDFLAGS = $(check_LIBS)

tests_ut_test_ut_check_SOURCES = tests/ut/test_ut_check.c
tests_ut_test_ut_check_LDADD = $(LIBCONTRACT) $(check_LIBRARIES)
tests_ut_test_ut_check_CFLAGS = -I$(TESTDIR) $(check_CFLAGS) $(AM_CFLAGS)
tests_ut_test_ut_check_LDFLAGS = $(check_LIBS)
endif

if BUILD_CMOCKA_TESTS
tests_ut_test_ut_cmocka_SOURCES = tests/ut/test_ut_cmocka.c
tests_ut_test_ut_cmocka_LDADD = $(LIBCONTRACT) $(check_LIBRARIES)
tests_ut_test_ut_cmocka_CFLAGS = -I$(TESTDIR) $(cmocka_CFLAGS) $(AM_CFLAGS)
tests_ut_test_ut_cmocka_LDFLAGS = $(cmocka_LIBS)
endif

if BUILD_GTEST_TESTS
tests_ut_test_ut_gtest_SOURCES = tests/ut/test_ut_gtest.cc
tests_ut_test_ut_gtest_LDADD = $(LIBCONTRACT) $(check_LIBRARIES)
tests_ut_test_ut_gtest_CXXFLAGS = -I$(TESTDIR) $(GTest_CFLAGS) $(AM_CXXFLAGS)
tests_ut_test_ut_gtest_LDFLAGS = $(GTest_LIBS)
endif
