/* SPDX-License-Identifier: MIT */

/*
 * tests/standard_tests.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include "test_helper.h"
#include <check.h>

static int value = 1;

START_TEST(TEST_contracts_honored)
{
    test_expect_default(&value);
    test_ensure_default(&value);
    test_assert_default(&value);
    test_expect_audit(&value);
    test_ensure_audit(&value);
    test_assert_audit(&value);
    test_expect_axiom(&value);
    test_ensure_axiom(&value);
    test_assert_axiom(&value);
}
END_TEST

START_TEST(TEST_expect_default)
{
    test_expect_default(NULL);
}
END_TEST

START_TEST(TEST_ensure_default)
{
    test_ensure_default(NULL);
}
END_TEST

START_TEST(TEST_assert_default)
{
    test_assert_default(NULL);
}
END_TEST

START_TEST(TEST_expect_audit)
{
    test_expect_audit(NULL);
}
END_TEST

START_TEST(TEST_ensure_audit)
{
    test_ensure_audit(NULL);
}
END_TEST

START_TEST(TEST_assert_audit)
{
    test_assert_audit(NULL);
}
END_TEST

START_TEST(TEST_expect_axiom)
{
    test_expect_axiom(NULL);
}
END_TEST

START_TEST(TEST_ensure_axiom)
{
    test_ensure_axiom(NULL);
}
END_TEST

START_TEST(TEST_assert_axiom)
{
    test_assert_axiom(NULL);
}
END_TEST
