/* SPDX-License-Identifier: MIT */

/*
 * tests/test_explicit_behviour.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#include <check.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "$prefix$contract/contract.h"
#include "test_helper.h"

/* Handler that continues on MAYBE_CONTINUE */
static void continuing_handler(enum $prefix$contract_violation_cont_mode mode,
                               const char *role, const char *type,
                               const char *condition, const char *file,
                               const char *function, size_t line)
{
    fprintf(stderr, "%s:%zu: in %s: %s '%s' violated (%s role)\n", file, line,
            function, type, condition, role);

    if (mode == NEVER_CONTINUE)
        abort();
}

/* ASSUME */
START_TEST(TEST_expect_assume)
{
    test_expect_assume(NULL);
}
END_TEST

START_TEST(TEST_ensure_assume)
{
    test_ensure_assume(NULL);
}
END_TEST

START_TEST(TEST_assert_assume)
{
    test_assert_assume(NULL);
}
END_TEST

/* IGNORE */
START_TEST(TEST_expect_ignore)
{
    test_expect_ignore(NULL);
}
END_TEST

START_TEST(TEST_ensure_ignore)
{
    test_ensure_ignore(NULL);
}
END_TEST

START_TEST(TEST_assert_ignore)
{
    test_assert_ignore(NULL);
}
END_TEST

/* NEVER_CONTINUE */
START_TEST(TEST_expect_never_continue)
{
    test_expect_never_continue(NULL);
}
END_TEST

START_TEST(TEST_ensure_never_continue)
{
    test_ensure_never_continue(NULL);
}
END_TEST

START_TEST(TEST_assert_never_continue)
{
    test_assert_never_continue(NULL);
}
END_TEST

/* MAYBE_CONTINUE */
START_TEST(TEST_expect_maybe_continue)
{
    test_expect_maybe_continue(NULL);
}
END_TEST

START_TEST(TEST_ensure_maybe_continue)
{
    test_ensure_maybe_continue(NULL);
}
END_TEST

START_TEST(TEST_assert_maybe_continue)
{
    test_assert_maybe_continue(NULL);
}
END_TEST

START_TEST(TEST_maybe_continue_continues)
{
    $prefix$contract_set_handler(continuing_handler);
    test_assert_maybe_continue(NULL);
}
END_TEST

/* ALWAYS_CONTINUE */
START_TEST(TEST_expect_always_continue)
{
    test_expect_always_continue(NULL);
}
END_TEST

START_TEST(TEST_ensure_always_continue)
{
    test_ensure_always_continue(NULL);
}
END_TEST

START_TEST(TEST_assert_always_continue)
{
    test_assert_always_continue(NULL);
}
END_TEST

Suite *explixit_suite(void)
{
    Suite *s = suite_create("Explicit beahviour");

    /* Assumed contracts are not checked so we run into UB */
    TCase *tc_assume = tcase_create("ASSUME");
    tcase_add_test_raise_signal(tc_assume, TEST_expect_assume, SIGSEGV);
    tcase_add_test_raise_signal(tc_assume, TEST_ensure_assume, SIGSEGV);
    tcase_add_test_raise_signal(tc_assume, TEST_assert_assume, SIGSEGV);
    suite_add_tcase(s, tc_assume);

    /* Ignored contracts are ignored so we run into UB */
    TCase *tc_ignore = tcase_create("IGNORE");
    tcase_add_test_raise_signal(tc_ignore, TEST_expect_ignore, SIGSEGV);
    tcase_add_test_raise_signal(tc_ignore, TEST_ensure_ignore, SIGSEGV);
    tcase_add_test_raise_signal(tc_ignore, TEST_assert_ignore, SIGSEGV);
    suite_add_tcase(s, tc_ignore);

    /* We always abort if a NEVER_CONTINUE CCS is violated */
    TCase *tc_never_continue = tcase_create("NEVER CONTINUE");
    tcase_add_test_raise_signal(tc_never_continue, TEST_expect_never_continue,
                                SIGABRT);
    tcase_add_test_raise_signal(tc_never_continue, TEST_ensure_never_continue,
                                SIGABRT);
    tcase_add_test_raise_signal(tc_never_continue, TEST_assert_never_continue,
                                SIGABRT);
    suite_add_tcase(s, tc_never_continue);

    /* The default violation handler aborts if a MAYBE_CONTINUE CCS is violated
     */
    TCase *tc_maybe_continue = tcase_create("MAYBE CONTINUE");
    tcase_add_test_raise_signal(tc_maybe_continue, TEST_expect_maybe_continue,
                                SIGABRT);
    tcase_add_test_raise_signal(tc_maybe_continue, TEST_ensure_maybe_continue,
                                SIGABRT);
    tcase_add_test_raise_signal(tc_maybe_continue, TEST_assert_maybe_continue,
                                SIGABRT);

    /* We run into UB when the violation handler continues */
    tcase_add_test_raise_signal(tc_maybe_continue,
                                TEST_maybe_continue_continues, SIGSEGV);
    suite_add_tcase(s, tc_maybe_continue);

    /* We always continue after a violated ALWAYS_CONTINUE CCS so we run into UB
     */
    TCase *tc_always_continue = tcase_create("ALWAYS CONTINUE");
    tcase_add_test_raise_signal(tc_always_continue, TEST_expect_always_continue,
                                SIGSEGV);
    tcase_add_test_raise_signal(tc_always_continue, TEST_ensure_always_continue,
                                SIGSEGV);
    tcase_add_test_raise_signal(tc_always_continue, TEST_assert_always_continue,
                                SIGSEGV);
    suite_add_tcase(s, tc_always_continue);
    return s;
}

int main(void)
{
    Suite *s = explixit_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_ENV);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
