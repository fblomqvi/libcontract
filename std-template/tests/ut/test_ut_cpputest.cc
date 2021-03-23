/* SPDX-License-Identifier: MIT */

/*
 * tests/ut/test_ut_cpputest.cc
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

#include "$prefix$contract/ut/CppUTest.h"
#include "test_helper.h"

TEST_GROUP(ContractUtMacros){};

TEST(ContractUtMacros, TEST_expect)
{
    CHECK_VIOLATES_CONTRACT(test_expect_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_default(NULL));

    CHECK_VIOLATES_CONTRACT(test_expect_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_audit(NULL));
}

int main(int ac, char **av)
{
    $prefix$contract_ut_init();
    return CommandLineTestRunner::RunAllTests(ac, av);
}
