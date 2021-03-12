/* SPDX-License-Identifier: MIT */

/*
 * tests/ut/test_ut_cmocka.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#include "$prefix$contract/ut/cmocka.h"
#include "test_helper.h"

/* clang-format off */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
/* clang-format on */

static void test_macros(void **state)
{
    (void) state;

    CHECK_VIOLATES_CONTRACT(test_expect_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_default(NULL));

    CHECK_VIOLATES_CONTRACT(test_expect_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_audit(NULL));
}

int main(void)
{
    $prefix$contract_ut_init();

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_macros),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
