/* SPDX-License-Identifier: MIT */

/*
 * tests/test_helper.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include "test_helper.h"
#include "$prefix$contract/contract.h"

int test_expect_default(int *ptr)
{
    $PREFIX$$EXPECT$(ptr);
    return *ptr;
}

int test_ensure_default(int *ptr)
{
    $PREFIX$$ENSURE$(ptr);
    return *ptr;
}

int test_assert_default(int *ptr)
{
    $PREFIX$$ASSERT$(ptr);
    return *ptr;
}

int test_expect_audit(int *ptr)
{
    $PREFIX$$EXPECT$_AUDIT(ptr);
    return *ptr;
}

int test_ensure_audit(int *ptr)
{
    $PREFIX$$ENSURE$_AUDIT(ptr);
    return *ptr;
}

int test_assert_audit(int *ptr)
{
    $PREFIX$$ASSERT$_AUDIT(ptr);
    return *ptr;
}

int test_expect_axiom(int *ptr)
{
    $PREFIX$$EXPECT$_AXIOM(ptr);
    return *ptr;
}

int test_ensure_axiom(int *ptr)
{
    $PREFIX$$ENSURE$_AXIOM(ptr);
    return *ptr;
}

int test_assert_axiom(int *ptr)
{
    $PREFIX$$ASSERT$_AXIOM(ptr);
    return *ptr;
}

int test_expect_default_review(int *ptr)
{
    $PREFIX$$EXPECT$_REVIEW(ptr);
    return *ptr;
}

int test_ensure_default_review(int *ptr)
{
    $PREFIX$$ENSURE$_REVIEW(ptr);
    return *ptr;
}

int test_assert_default_review(int *ptr)
{
    $PREFIX$$ASSERT$_REVIEW(ptr);
    return *ptr;
}

int test_expect_audit_review(int *ptr)
{
    $PREFIX$$EXPECT$_AUDIT_REVIEW(ptr);
    return *ptr;
}

int test_ensure_audit_review(int *ptr)
{
    $PREFIX$$ENSURE$_AUDIT_REVIEW(ptr);
    return *ptr;
}

int test_assert_audit_review(int *ptr)
{
    $PREFIX$$ASSERT$_AUDIT_REVIEW(ptr);
    return *ptr;
}

int test_expect_axiom_review(int *ptr)
{
    $PREFIX$$EXPECT$_AXIOM_REVIEW(ptr);
    return *ptr;
}

int test_ensure_axiom_review(int *ptr)
{
    $PREFIX$$ENSURE$_AXIOM_REVIEW(ptr);
    return *ptr;
}

int test_assert_axiom_review(int *ptr)
{
    $PREFIX$$ASSERT$_AXIOM_REVIEW(ptr);
    return *ptr;
}

int test_expect_assume(int *ptr)
{
    $PREFIX$$EXPECT$_ASSUME(ptr);
    return *ptr;
}

int test_ensure_assume(int *ptr)
{
    $PREFIX$$ENSURE$_ASSUME(ptr);
    return *ptr;
}

int test_assert_assume(int *ptr)
{
    $PREFIX$$ASSERT$_ASSUME(ptr);
    return *ptr;
}

int test_expect_ignore(int *ptr)
{
    $PREFIX$$EXPECT$_IGNORE(ptr);
    return *ptr;
}

int test_ensure_ignore(int *ptr)
{
    $PREFIX$$ENSURE$_IGNORE(ptr);
    return *ptr;
}

int test_assert_ignore(int *ptr)
{
    $PREFIX$$ASSERT$_IGNORE(ptr);
    return *ptr;
}

int test_expect_never_continue(int *ptr)
{
    $PREFIX$$EXPECT$_NEVER_CONTINUE(ptr);
    return *ptr;
}

int test_ensure_never_continue(int *ptr)
{
    $PREFIX$$ENSURE$_NEVER_CONTINUE(ptr);
    return *ptr;
}

int test_assert_never_continue(int *ptr)
{
    $PREFIX$$ASSERT$_NEVER_CONTINUE(ptr);
    return *ptr;
}

int test_expect_maybe_continue(int *ptr)
{
    $PREFIX$$EXPECT$_MAYBE_CONTINUE(ptr);
    return *ptr;
}

int test_ensure_maybe_continue(int *ptr)
{
    $PREFIX$$ENSURE$_MAYBE_CONTINUE(ptr);
    return *ptr;
}

int test_assert_maybe_continue(int *ptr)
{
    $PREFIX$$ASSERT$_MAYBE_CONTINUE(ptr);
    return *ptr;
}

int test_expect_always_continue(int *ptr)
{
    $PREFIX$$EXPECT$_ALWAYS_CONTINUE(ptr);
    return *ptr;
}

int test_ensure_always_continue(int *ptr)
{
    $PREFIX$$ENSURE$_ALWAYS_CONTINUE(ptr);
    return *ptr;
}

int test_assert_always_continue(int *ptr)
{
    $PREFIX$$ASSERT$_ALWAYS_CONTINUE(ptr);
    return *ptr;
}
