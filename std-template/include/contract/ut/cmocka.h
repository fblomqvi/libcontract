/* SPDX-License-Identifier: MIT */

/*
 * ut/cmocka.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CMOCKA_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CMOCKA_H_

#include "framework.h"

/* clang-format off */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
/* clang-format on */

#define CHECK_VIOLATES_CONTRACT(call) \
    _CHECK_VIOLATES_CONTRACT_(call, _CMOCKA_ASSERT_MSG_)

#define _CMOCKA_ASSERT_MSG_(cond, msg) \
    do {                               \
        if (!(cond)) {                 \
            fail_msg(msg);             \
        }                              \
    } while (0)

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CMOCKA_H_ */
