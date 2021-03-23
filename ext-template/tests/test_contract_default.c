/* SPDX-License-Identifier: MIT */

/*
 * tests/test_contract_default.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <check.h>
#include <signal.h>
#include <stdlib.h>

#include "standard_tests.h"

Suite *default_suite(void)
{
    Suite *s = suite_create("Default Level");

    TCase *tc_default = tcase_create("Default role");
    tcase_add_test(tc_default, TEST_contracts_honored);

    /* Default role, default level is enforced so we cannot violate those
     * contracts */
    tcase_add_test_raise_signal(tc_default, TEST_expect_default, SIGABRT);
    tcase_add_test_raise_signal(tc_default, TEST_ensure_default, SIGABRT);
    tcase_add_test_raise_signal(tc_default, TEST_assert_default, SIGABRT);

    /* Default role, audit level is ignored so we run int UB if we violate them
     */
    tcase_add_test_raise_signal(tc_default, TEST_expect_audit, SIGSEGV);
    tcase_add_test_raise_signal(tc_default, TEST_ensure_audit, SIGSEGV);
    tcase_add_test_raise_signal(tc_default, TEST_assert_audit, SIGSEGV);

    /* Default role, axiom level is ignored so we run int UB if we violate them
     */
    tcase_add_test_raise_signal(tc_default, TEST_expect_axiom, SIGSEGV);
    tcase_add_test_raise_signal(tc_default, TEST_ensure_axiom, SIGSEGV);
    tcase_add_test_raise_signal(tc_default, TEST_assert_axiom, SIGSEGV);
    suite_add_tcase(s, tc_default);

    TCase *tc_review = tcase_create("Review role");
    tcase_add_test(tc_review, TEST_contracts_honored_review);

    /* Review role, default level: We always continue so we run int UB if we
     * violate them */
    tcase_add_test_raise_signal(tc_review, TEST_expect_default_review, SIGSEGV);
    tcase_add_test_raise_signal(tc_review, TEST_ensure_default_review, SIGSEGV);
    tcase_add_test_raise_signal(tc_review, TEST_assert_default_review, SIGSEGV);

    /* Review role, audit level is ignored so we run int UB if we violate them
     */
    tcase_add_test_raise_signal(tc_review, TEST_expect_audit_review, SIGSEGV);
    tcase_add_test_raise_signal(tc_review, TEST_ensure_audit_review, SIGSEGV);
    tcase_add_test_raise_signal(tc_review, TEST_assert_audit_review, SIGSEGV);

    /* Review role, axiom level is ignored so we run int UB if we violate them
     */
    tcase_add_test_raise_signal(tc_review, TEST_expect_axiom_review, SIGSEGV);
    tcase_add_test_raise_signal(tc_review, TEST_ensure_axiom_review, SIGSEGV);
    tcase_add_test_raise_signal(tc_review, TEST_assert_axiom_review, SIGSEGV);
    suite_add_tcase(s, tc_review);

    return s;
}

int main(void)
{
    Suite *s = default_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_ENV);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
