/* SPDX-License-Identifier: MIT */

/*
 * tests/test_helper.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
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

int test_expect_default(int *ptr);
int test_ensure_default(int *ptr);
int test_assert_default(int *ptr);

int test_expect_audit(int *ptr);
int test_ensure_audit(int *ptr);
int test_assert_audit(int *ptr);

int test_expect_axiom(int *ptr);
int test_ensure_axiom(int *ptr);
int test_assert_axiom(int *ptr);

#ifdef __cplusplus
}
#endif

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_TEST_HELPER_H_ */
