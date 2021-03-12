/* SPDX-License-Identifier: MIT */

/*
 * tests/standard_tests.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#include "test_helper.h"
#include <check.h>

static int value = 1;

/* Tests for default role */
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

START_TEST(TEST_ensure_axiom)
{
    test_ensure_axiom(NULL);
}

START_TEST(TEST_assert_axiom)
{
    test_assert_axiom(NULL);
}

/* Tests for review role */
START_TEST(TEST_contracts_honored_review)
{
    test_expect_default_review(&value);
    test_ensure_default_review(&value);
    test_assert_default_review(&value);
    test_expect_audit_review(&value);
    test_ensure_audit_review(&value);
    test_assert_audit_review(&value);
    test_expect_axiom_review(&value);
    test_ensure_axiom_review(&value);
    test_assert_axiom_review(&value);
}
END_TEST

START_TEST(TEST_expect_default_review)
{
    test_expect_default_review(NULL);
}
END_TEST

START_TEST(TEST_ensure_default_review)
{
    test_ensure_default_review(NULL);
}
END_TEST

START_TEST(TEST_assert_default_review)
{
    test_assert_default_review(NULL);
}
END_TEST

START_TEST(TEST_expect_audit_review)
{
    test_expect_audit_review(NULL);
}
END_TEST

START_TEST(TEST_ensure_audit_review)
{
    test_ensure_audit_review(NULL);
}
END_TEST

START_TEST(TEST_assert_audit_review)
{
    test_assert_audit_review(NULL);
}
END_TEST

START_TEST(TEST_expect_axiom_review)
{
    test_expect_axiom_review(NULL);
}

START_TEST(TEST_ensure_axiom_review)
{
    test_ensure_axiom_review(NULL);
}

START_TEST(TEST_assert_axiom_review)
{
    test_assert_axiom_review(NULL);
}
