/* SPDX-License-Identifier: MIT */

/*
 * tests/test_helper.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_TEST_HELPER_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_TEST_HELPER_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The test functions are placed in their own translation unit so that the
 * compiler cannot optimize away the contract checks. Furthermore, the compiler
 * cannot remove code that would be unreachable because off CCS's that are
 * violated.
 */

/* Test functions for the default role */
int test_expect_default(int *ptr);
int test_ensure_default(int *ptr);
int test_assert_default(int *ptr);

int test_expect_audit(int *ptr);
int test_ensure_audit(int *ptr);
int test_assert_audit(int *ptr);

int test_expect_axiom(int *ptr);
int test_ensure_axiom(int *ptr);
int test_assert_axiom(int *ptr);

/* Test functions for the review role */
int test_expect_default_review(int *ptr);
int test_ensure_default_review(int *ptr);
int test_assert_default_review(int *ptr);

int test_expect_audit_review(int *ptr);
int test_ensure_audit_review(int *ptr);
int test_assert_audit_review(int *ptr);

int test_expect_axiom_review(int *ptr);
int test_ensure_axiom_review(int *ptr);
int test_assert_axiom_review(int *ptr);

/* Test functions for explicit behaviour */
int test_expect_assume(int *ptr);
int test_ensure_assume(int *ptr);
int test_assert_assume(int *ptr);

int test_expect_ignore(int *ptr);
int test_ensure_ignore(int *ptr);
int test_assert_ignore(int *ptr);

int test_expect_never_continue(int *ptr);
int test_ensure_never_continue(int *ptr);
int test_assert_never_continue(int *ptr);

int test_expect_maybe_continue(int *ptr);
int test_ensure_maybe_continue(int *ptr);
int test_assert_maybe_continue(int *ptr);

int test_expect_always_continue(int *ptr);
int test_ensure_always_continue(int *ptr);
int test_assert_always_continue(int *ptr);

#ifdef __cplusplus
}
#endif

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_TEST_HELPER_H_ */
