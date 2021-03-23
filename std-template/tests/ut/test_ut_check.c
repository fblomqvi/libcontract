/* SPDX-License-Identifier: MIT */

/*
 * tests/ut/test_ut_check.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <check.h>
#include <signal.h>

#define CONTRACT_UT_ABORT_ON_UNEXPECTED_VIOLATION
#include "$prefix$contract/ut/check.h"
#include "test_helper.h"

START_TEST(TEST_macros)
{
    CHECK_VIOLATES_CONTRACT(test_expect_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_default(NULL));

    CHECK_VIOLATES_CONTRACT(test_expect_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_audit(NULL));
}
END_TEST

START_TEST(TEST_unexpected_violation_catcher)
{
    test_expect_default(NULL);
}
END_TEST

Suite *contract_suite(void)
{
    Suite *s = suite_create("Contract violations");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, TEST_macros);
    tcase_add_test_raise_signal(tc_core, TEST_unexpected_violation_catcher,
                                SIGABRT);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    $prefix$contract_ut_init();

    Suite *s = contract_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_ENV);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
