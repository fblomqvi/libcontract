/* SPDX-License-Identifier: MIT */

/*
 * tests/test_contract_off.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <check.h>
#include <signal.h>
#include <stdlib.h>

#include "standard_tests.h"

Suite *off_suite(void)
{
    Suite *s = suite_create("Off Level");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, TEST_contracts_honored);

    /* Default level is ignored so we run int UB if we violate them */
    tcase_add_test_raise_signal(tc_core, TEST_expect_default, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_ensure_default, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_assert_default, SIGSEGV);

    /* Audit level is ignored so we run int UB if we violate them */
    tcase_add_test_raise_signal(tc_core, TEST_expect_audit, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_ensure_audit, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_assert_audit, SIGSEGV);

    /* Axiom level is assumed so we run int UB if we violate them */
    tcase_add_test_raise_signal(tc_core, TEST_expect_axiom, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_ensure_axiom, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_assert_axiom, SIGSEGV);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    Suite *s = off_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_ENV);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
