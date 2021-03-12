/* SPDX-License-Identifier: MIT */

/*
 * ut/check.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CHECK_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CHECK_H_

#include "framework.h"
#include <check.h>

#define CHECK_VIOLATES_CONTRACT(call) \
    _CHECK_VIOLATES_CONTRACT_(call, ck_assert_msg)

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CHECK_H_ */
