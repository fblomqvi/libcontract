/* SPDX-License-Identifier: MIT */

/*
 * tests/test_helper.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
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
