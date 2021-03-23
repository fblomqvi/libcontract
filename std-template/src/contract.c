/* SPDX-License-Identifier: MIT */

/*
 * contract.c
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include "$prefix$contract/contract.h"
#include <stdio.h>
#include <stdlib.h>

static void print_violation(const char *type, const char *condition,
                            const char *file, const char *function, size_t line)
{
    fprintf(stderr, "%s:%zu: in %s: %s '%s' violated\n", file, line, function,
            type, condition);
}

static void default_handler(const char *type, const char *condition,
                            const char *file, const char *function, size_t line)
{
    print_violation(type, condition, file, function, line);
    abort();
}

static $prefix$contract_handler_t g_handler = default_handler;

$prefix$contract_handler_t $prefix$contract_get_handler(void)
{
    return g_handler;
}

void $prefix$contract_set_handler($prefix$contract_handler_t handler)
{
    g_handler = handler;
}

void _$prefix$contract_handle_violation(const char *type, const char *condition,
                                        const char *file, const char *function,
                                        size_t line)
{
    g_handler(type, condition, file, function, line);
}

/* UT stuff */
#include "$prefix$contract/ut/framework.h"

static enum $prefix$contract_ut_verbosity verbosity_level =
    $PREFIX$CONTRACT_UT_QUIET;

static _CONTRACT_THREAD_LOCAL int contract_check_active = 0;
_CONTRACT_THREAD_LOCAL jmp_buf _$prefix$contract_jmp_buf;

static void ut_handler(const char *type, const char *condition,
                       const char *file, const char *function, size_t line)
{

    if (!contract_check_active) {
        fprintf(stderr, "Unexpected contract violation:\n");
        default_handler(type, condition, file, function, line);
    }

    if (verbosity_level == $PREFIX$CONTRACT_UT_VERBOSE) {
        print_violation(type, condition, file, function, line);
    }

    longjmp(_$prefix$contract_jmp_buf, 1);
}

void _$prefix$contract_check_push(void)
{
    contract_check_active++;
}

void _$prefix$contract_check_pop(void)
{
    contract_check_active--;
}

void $prefix$contract_ut_set_verbosity(
    enum $prefix$contract_ut_verbosity verbosity)
{
    verbosity_level = verbosity;
}

void $prefix$contract_ut_init(void)
{
    $prefix$contract_set_handler(ut_handler);
}
