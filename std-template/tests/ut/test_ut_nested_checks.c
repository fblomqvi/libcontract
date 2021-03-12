/* SPDX-License-Identifier: MIT */

/*
 * tests/ut/test_ut_nested_checks.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#include <check.h>
#include <signal.h>

#include "$prefix$contract/ut/check.h"
#include "test_helper.h"

static void violator2(int *ptr)
{
    CHECK_VIOLATES_CONTRACT(test_assert_default(ptr));
    test_ensure_default(NULL);
}
static void violator(int *ptr)
{
    CHECK_VIOLATES_CONTRACT(test_assert_default(ptr));
    CHECK_VIOLATES_CONTRACT(violator2(ptr));
    test_expect_default(NULL);
}

START_TEST(TEST_nested_violation_checks)
{
    CHECK_VIOLATES_CONTRACT(violator(NULL));
}
END_TEST

Suite *contract_suite(void)
{
    Suite *s = suite_create("Contract violations");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, TEST_nested_violation_checks);
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
