/* SPDX-License-Identifier: MIT */

/*
 * contract.h
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#ifndef _$PREFIX$CONTRACT_HEADER_CONTRACT_H_
#define _$PREFIX$CONTRACT_HEADER_CONTRACT_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct $prefix$contract_violation {
    const char *file;
    size_t line;
    const char *function;
    const char *type;
    const char *condition;
};

typedef void (*$prefix$contract_handler_t)(
    const struct $prefix$contract_violation *);

/**
 * @brief Get the global violation handler.
 */
$prefix$contract_handler_t $prefix$contract_get_handler(void);

/**
 * @brief Sets the global violation handler.
 *
 * If the global handler is not set, then the default handler will be used.
 * This default handler prints the violation to stderr and then calls abort().
 */
void $prefix$contract_set_handler($prefix$contract_handler_t handler);

/**
 * @brief Calls the global violation handler that can be set by
 * $prefix$contract_set_handler().
 */
void _$prefix$contract_handle_violation(
    const struct $prefix$contract_violation *v);

/* Default shorthand macros */
#define $PREFIX$$EXPECT$(cond) $PREFIX$$EXPECT$_DEFAULT(cond)
#define $PREFIX$$ENSURE$(cond) $PREFIX$$ENSURE$_DEFAULT(cond)
#define $PREFIX$$ASSERT$(cond) $PREFIX$$ASSERT$_DEFAULT(cond)

/* Default macros */
#define $PREFIX$$EXPECT$_DEFAULT(cond) \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_DEFAULT_, cond)

#define $PREFIX$$ENSURE$_DEFAULT(cond) \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_DEFAULT_, cond)

#define $PREFIX$$ASSERT$_DEFAULT(cond) \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_DEFAULT_, cond)

/* Audit macros */
#define $PREFIX$$EXPECT$_AUDIT(cond) \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_AUDIT_, cond)

#define $PREFIX$$ENSURE$_AUDIT(cond) \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_AUDIT_, cond)

#define $PREFIX$$ASSERT$_AUDIT(cond) \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_AUDIT_, cond)

/* Axiom macros */
#define $PREFIX$$EXPECT$_AXIOM(cond) \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_AXIOM_, cond)

#define $PREFIX$$ENSURE$_AXIOM(cond) \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_AXIOM_, cond)

#define $PREFIX$$ASSERT$_AXIOM(cond) \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_AXIOM_, cond)

/* Helper macros */
#define _$PREFIX$CONTRACT_CREATE_EXPECT_(check, cond) \
    check(_$PREFIX$CONTRACT_TYPE_EXPECT_, cond)

#define _$PREFIX$CONTRACT_CREATE_ENSURE_(check, cond) \
    check(_$PREFIX$CONTRACT_TYPE_ENSURE_, cond)

#define _$PREFIX$CONTRACT_CREATE_ASSERT_(check, cond) \
    check(_$PREFIX$CONTRACT_TYPE_ASSERT_, cond)

/* Contract names */
#define _$PREFIX$CONTRACT_TYPE_EXPECT_ "precondition"
#define _$PREFIX$CONTRACT_TYPE_ENSURE_ "postcondition"
#define _$PREFIX$CONTRACT_TYPE_ASSERT_ "assertion"

#if defined(__clang__)
    #if __has_builtin(__builtin_unreachable)
        #define _CONTRACT_HAVE_BUILTIN_UNREACHABLE 1
    #endif
#elif defined(__GNUC__)
    #if __GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
        #define _CONTRACT_HAVE_BUILTIN_UNREACHABLE 1
    #endif
#endif

#if defined(_MSC_VER)
    #define _CONTRACT_HAVE_BUILTIN_ASSUME 1
#endif

/* Contract modes */
#define _$PREFIX$CONTRACT_IGNORE_(type, cond) (void) sizeof((cond) ? 1 : 0)

#if _CONTRACT_HAVE_BUILTIN_UNREACHABLE
    #define _$PREFIX$CONTRACT_ASSUME_(type, cond) \
        ((cond) ? (void) 0 : __builtin_unreachable())
#elif _CONTRACT_HAVE_BUILTIN_ASSUME
    #define _$PREFIX$CONTRACT_ASSUME_(type, cond) __assume(cond)
#else
    #define _$PREFIX$CONTRACT_ASSUME_(type, cond) \
        _$PREFIX$CONTRACT_IGNORE_(type, cond)
#endif

#define _$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_(type, cond)  \
    do {                                                     \
        if (!(cond)) {                                       \
            _$PREFIX$CONTRACT_HANDLE_VIOLATION_(type, cond); \
            abort();                                         \
        }                                                    \
    } while (0)

/* Create violation handler call */
#define _$PREFIX$CONTRACT_HANDLE_VIOLATION_(type, cond)                       \
    do {                                                                      \
        const struct $prefix$contract_violation _v = {__FILE__, __LINE__,     \
                                                      __func__, type, #cond}; \
        _$prefix$contract_handle_violation(&_v);                              \
    } while (0)

/* Build configuration options */
#if defined $PREFIX$CONTRACT_OFF
    #if defined $PREFIX$CONTRACT_DEFAULT || defined $PREFIX$CONTRACT_AUDIT || \
        defined $PREFIX$CONTRACT_TEST
        #error At most one of $PREFIX$CONTRACT_OFF, $PREFIX$CONTRACT_DEFAULT, $PREFIX$CONTRACT_AUDIT and $PREFIX$CONTRACT_TEST must be specified
    #endif
    #define _$PREFIX$CONTRACT_BUILD_ _$PREFIX$CONTRACT_BUILD_MODE_OFF_
#elif defined $PREFIX$CONTRACT_DEFAULT
    #if defined $PREFIX$CONTRACT_AUDIT || defined $PREFIX$CONTRACT_TEST
        #error At most one of $PREFIX$CONTRACT_OFF, $PREFIX$CONTRACT_DEFAULT, $PREFIX$CONTRACT_AUDIT and $PREFIX$CONTRACT_TEST must be specified
    #endif
    #define _$PREFIX$CONTRACT_BUILD_ _$PREFIX$CONTRACT_BUILD_MODE_DEFAULT_
#elif defined $PREFIX$CONTRACT_AUDIT
    #if defined $PREFIX$CONTRACT_TEST
        #error At most one of $PREFIX$CONTRACT_OFF, $PREFIX$CONTRACT_DEFAULT, $PREFIX$CONTRACT_AUDIT and $PREFIX$CONTRACT_TEST must be specified
    #endif
    #define _$PREFIX$CONTRACT_BUILD_ _$PREFIX$CONTRACT_BUILD_MODE_AUDIT_
#elif defined $PREFIX$CONTRACT_TEST
    #define _$PREFIX$CONTRACT_BUILD_ _$PREFIX$CONTRACT_BUILD_MODE_AUDIT_
#else /* Default build */
    #define _$PREFIX$CONTRACT_BUILD_ _$PREFIX$CONTRACT_BUILD_MODE_DEFAULT_
#endif

#define _$PREFIX$CONTRACT_BUILD_MODE_OFF_ 0
#define _$PREFIX$CONTRACT_BUILD_MODE_DEFAULT_ 1
#define _$PREFIX$CONTRACT_BUILD_MODE_AUDIT_ 2

/* Standard build configurations */
#if _$PREFIX$CONTRACT_BUILD_ == _$PREFIX$CONTRACT_BUILD_MODE_OFF_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_ _$PREFIX$CONTRACT_IGNORE_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_ _$PREFIX$CONTRACT_IGNORE_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_ _$PREFIX$CONTRACT_ASSUME_
#elif _$PREFIX$CONTRACT_BUILD_ == _$PREFIX$CONTRACT_BUILD_MODE_DEFAULT_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_ \
        _$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_ _$PREFIX$CONTRACT_IGNORE_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_ _$PREFIX$CONTRACT_IGNORE_
#elif _$PREFIX$CONTRACT_BUILD_ == _$PREFIX$CONTRACT_BUILD_MODE_AUDIT_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_ \
        _$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_ \
        _$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_ _$PREFIX$CONTRACT_IGNORE_
#endif

/* Options to override standard build configurations */
#if defined $PREFIX$CONTRACT_MODE_DEFAULT
    #undef _$PREFIX$CONTRACT_MODE_DEFAULT_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_ $PREFIX$CONTRACT_MODE_DEFAULT
#endif

#if defined $PREFIX$CONTRACT_MODE_AUDIT
    #undef _$PREFIX$CONTRACT_MODE_AUDIT_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_ $PREFIX$CONTRACT_MODE_AUDIT
#endif

#if defined $PREFIX$CONTRACT_MODE_AXIOM
    #undef _$PREFIX$CONTRACT_MODE_AXIOM_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_ $PREFIX$CONTRACT_MODE_AXIOM
#endif

#ifdef __cplusplus
}
#endif

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_H_ */
