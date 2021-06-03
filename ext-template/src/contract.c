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

volatile int _$prefix$contract_unknowable_int_ = 0;

static void print_violation(const struct $prefix$contract_violation *v)
{
    fprintf(stderr, "%s:%zu: in %s: %s '%s' violated (%s role)\n", v->file,
            v->line, v->function, v->type, v->condition, v->role);
}

static void default_handler(const struct $prefix$contract_violation *v)
{
    print_violation(v);
    if (v->mode != ALWAYS_CONTINUE)
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

void _$prefix$contract_handle_violation(
    const struct $prefix$contract_violation *v)
{
    g_handler(v);
}

/* UT stuff */
#include "$prefix$contract/ut/framework.h"

static enum $prefix$contract_ut_verbosity verbosity_level =
    $PREFIX$CONTRACT_UT_QUIET;

static _CONTRACT_THREAD_LOCAL int contract_check_active = 0;
_CONTRACT_THREAD_LOCAL jmp_buf _$prefix$contract_jmp_buf;

static void ut_handler(const struct $prefix$contract_violation *v)
{
    if (!contract_check_active) {
        fprintf(stderr, "Unexpected contract violation:\n");
        print_violation(v);
        abort();
    }

    if (verbosity_level == $PREFIX$CONTRACT_UT_VERBOSE) {
        print_violation(v);
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
