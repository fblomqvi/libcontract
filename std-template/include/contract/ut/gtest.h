/* SPDX-License-Identifier: MIT */

/*
 * ut/gtest.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_GTEST_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_GTEST_H_

#include "framework.h"
#include <gtest/gtest.h>

#define CHECK_VIOLATES_CONTRACT(call) ASSERT_VIOLATES_CONTRACT(call)

#define ASSERT_VIOLATES_CONTRACT(call) \
    _CHECK_VIOLATES_CONTRACT_(call, _ASSERT_MSG_)

#define EXPECT_VIOLATES_CONTRACT(call) \
    _CHECK_VIOLATES_CONTRACT_(call, _EXPECT_MSG_)

#define _ASSERT_MSG_(cond, msg) ASSERT_TRUE(cond) << msg;

#define _EXPECT_MSG_(cond, msg) EXPECT_TRUE(cond) << msg;

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_GTEST_H_ */
