/* SPDX-License-Identifier: MIT */

/*
 * tests/test_contract_audit.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#include <check.h>
#include <signal.h>
#include <stdlib.h>

#include "standard_tests.h"

Suite *audit_suite(void)
{
    Suite *s = suite_create("Audit Level");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, TEST_contracts_honored);

    /* Default level is enforced so we cannot violate those contracts */
    tcase_add_test_raise_signal(tc_core, TEST_expect_default, SIGABRT);
    tcase_add_test_raise_signal(tc_core, TEST_ensure_default, SIGABRT);
    tcase_add_test_raise_signal(tc_core, TEST_assert_default, SIGABRT);

    /* Audit level is enforced so we cannot violate those contracts */
    tcase_add_test_raise_signal(tc_core, TEST_expect_audit, SIGABRT);
    tcase_add_test_raise_signal(tc_core, TEST_ensure_audit, SIGABRT);
    tcase_add_test_raise_signal(tc_core, TEST_assert_audit, SIGABRT);

    /* Axiom level is ignored so we run int UB if we violate them */
    tcase_add_test_raise_signal(tc_core, TEST_expect_axiom, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_ensure_axiom, SIGSEGV);
    tcase_add_test_raise_signal(tc_core, TEST_assert_axiom, SIGSEGV);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    Suite *s = audit_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_ENV);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
