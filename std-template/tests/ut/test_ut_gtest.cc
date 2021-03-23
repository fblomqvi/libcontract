/* SPDX-License-Identifier: MIT */

/*
 * tests/ut/test_ut_gtest.cc
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <gtest/gtest.h>

#include "$prefix$contract/ut/gtest.h"
#include "test_helper.h"

TEST(ContractUtMacros, TEST_expect)
{
    CHECK_VIOLATES_CONTRACT(test_expect_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_default(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_default(NULL));

    CHECK_VIOLATES_CONTRACT(test_expect_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_ensure_audit(NULL));
    CHECK_VIOLATES_CONTRACT(test_assert_audit(NULL));
}

int main(int argc, char **argv)
{
    $prefix$contract_ut_init();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
