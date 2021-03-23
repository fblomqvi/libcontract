/* SPDX-License-Identifier: MIT */

/*
 * ut/CppUTest.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CPPUTEST_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CPPUTEST_H_

#include "framework.h"
#include <CppUTest/TestHarness.h>

#define CHECK_VIOLATES_CONTRACT(call) \
    _CHECK_VIOLATES_CONTRACT_(call, CHECK_TEXT)

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CPPUTEST_H_ */
