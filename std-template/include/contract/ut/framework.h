/* SPDX-License-Identifier: MIT */

/*
 * ut/framework.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * This file is part of lib$prefix$contract
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CONTRACT_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CONTRACT_H_

#if __cplusplus >= 201103L
    #define _CONTRACT_THREAD_LOCAL thread_local
#elif __STDC_VERSION__ >= 201112L
    #define _CONTRACT_THREAD_LOCAL _Thread_local
#else
    #define _CONTRACT_THREAD_LOCAL
#endif

#include "$prefix$contract/contract.h"
#include <setjmp.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

enum $prefix$contract_ut_verbosity {
    $PREFIX$CONTRACT_UT_QUIET = 0,
    $PREFIX$CONTRACT_UT_VERBOSE
};

extern _CONTRACT_THREAD_LOCAL jmp_buf _$prefix$contract_jmp_buf;

void $prefix$contract_ut_set_verbosity(
    enum $prefix$contract_ut_verbosity verbosity);

void $prefix$contract_ut_init(void);

void _$prefix$contract_check_push(void);
void _$prefix$contract_check_pop(void);

#define _CHECK_CONTRACT_VIOLATION_(call, check, expected, msg)                 \
    do {                                                                       \
        jmp_buf _old_jmp_buf;                                                  \
        int _violation_detected;                                               \
        _$prefix$contract_check_push();                                        \
        memcpy(_old_jmp_buf, _$prefix$contract_jmp_buf, sizeof(_old_jmp_buf)); \
        if (!setjmp(_$prefix$contract_jmp_buf)) {                              \
            call;                                                              \
            _violation_detected = 0;                                           \
        } else {                                                               \
            _violation_detected = 1;                                           \
        }                                                                      \
        check(_violation_detected == expected, msg);                           \
        memcpy(_$prefix$contract_jmp_buf, _old_jmp_buf, sizeof(_old_jmp_buf)); \
        _$prefix$contract_check_pop();                                         \
    } while (0)

#define _CHECK_VIOLATES_CONTRACT_(call, check) \
    _CHECK_CONTRACT_VIOLATION_(call, check, 1, \
                               "'" #call ";' does not violate any contract")

#ifdef __cplusplus
}
#endif

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_UT_CONTRACT_H_ */
