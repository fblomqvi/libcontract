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

enum $prefix$contract_violation_cont_mode {
    NEVER_CONTINUE = 0,
    MAYBE_CONTINUE,
    ALWAYS_CONTINUE
};

extern volatile int _$prefix$contract_unknowable_int_;

typedef void (*$prefix$contract_handler_t)(
    enum $prefix$contract_violation_cont_mode mode, const char *, const char *,
    const char *, const char *, const char *, size_t);

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
    enum $prefix$contract_violation_cont_mode mode, const char *role,
    const char *type, const char *condition, const char *file,
    const char *function, size_t line);

/* Default role shorthand macros */
#define $PREFIX$$EXPECT$(cond) $PREFIX$$EXPECT$_DEFAULT(cond)
#define $PREFIX$$ENSURE$(cond) $PREFIX$$ENSURE$_DEFAULT(cond)
#define $PREFIX$$ASSERT$(cond) $PREFIX$$ASSERT$_DEFAULT(cond)

/* Default role default macros */
#define $PREFIX$$EXPECT$_DEFAULT(cond)                                \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_DEFAULT_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

#define $PREFIX$$ENSURE$_DEFAULT(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_DEFAULT_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

#define $PREFIX$$ASSERT$_DEFAULT(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_DEFAULT_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

/* Default role audit macros */
#define $PREFIX$$EXPECT$_AUDIT(cond)                                \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_AUDIT_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

#define $PREFIX$$ENSURE$_AUDIT(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_AUDIT_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

#define $PREFIX$$ASSERT$_AUDIT(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_AUDIT_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

/* Default role axiom macros */
#define $PREFIX$$EXPECT$_AXIOM(cond)                                \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_AXIOM_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

#define $PREFIX$$ENSURE$_AXIOM(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_AXIOM_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

#define $PREFIX$$ASSERT$_AXIOM(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_AXIOM_, \
                                     _$PREFIX$CONTRACT_ROLE_DEFAULT_, cond)

/* Review role shorthand macros */
#define $PREFIX$$EXPECT$_REVIEW(cond) $PREFIX$$EXPECT$_DEFAULT_REVIEW(cond)
#define $PREFIX$$ENSURE$_REVIEW(cond) $PREFIX$$ENSURE$_DEFAULT_REVIEW(cond)
#define $PREFIX$$ASSERT$_REVIEW(cond) $PREFIX$$ASSERT$_DEFAULT_REVIEW(cond)

/* Review role default macros */
#define $PREFIX$$EXPECT$_DEFAULT_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

#define $PREFIX$$ENSURE$_DEFAULT_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

#define $PREFIX$$ASSERT$_DEFAULT_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

/* Review role audit macros */
#define $PREFIX$$EXPECT$_AUDIT_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

#define $PREFIX$$ENSURE$_AUDIT_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

#define $PREFIX$$ASSERT$_AUDIT_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

/* Review role axiom macros */
#define $PREFIX$$EXPECT$_AXIOM_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

#define $PREFIX$$ENSURE$_AXIOM_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

#define $PREFIX$$ASSERT$_AXIOM_REVIEW(cond)                                \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_, \
                                     _$PREFIX$CONTRACT_ROLE_REVIEW_, cond)

/* Explicit behaviour, ignore */
#define $PREFIX$$EXPECT$_IGNORE(cond)                           \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_IGNORE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ENSURE$_IGNORE(cond)                           \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_IGNORE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ASSERT$_IGNORE(cond)                           \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_IGNORE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

/* Explicit behaviour, assume */
#define $PREFIX$$EXPECT$_ASSUME(cond)                           \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_ASSUME_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ENSURE$_ASSUME(cond)                           \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_ASSUME_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ASSERT$_ASSUME(cond)                           \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_ASSUME_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

/* Explicit behaviour, never_continue */
#define $PREFIX$$EXPECT$_NEVER_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ENSURE$_NEVER_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ASSERT$_NEVER_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

/* Explicit behaviour, maybe_continue */
#define $PREFIX$$EXPECT$_MAYBE_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_CHECK_MAYBE_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ENSURE$_MAYBE_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_CHECK_MAYBE_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ASSERT$_MAYBE_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_CHECK_MAYBE_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

/* Explicit behaviour, always_continue */
#define $PREFIX$$EXPECT$_ALWAYS_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_EXPECT_(_$PREFIX$CONTRACT_CHECK_ALWAYS_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ENSURE$_ALWAYS_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_ENSURE_(_$PREFIX$CONTRACT_CHECK_ALWAYS_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

#define $PREFIX$$ASSERT$_ALWAYS_CONTINUE(cond)                                 \
    _$PREFIX$CONTRACT_CREATE_ASSERT_(_$PREFIX$CONTRACT_CHECK_ALWAYS_CONTINUE_, \
                                     _$PREFIX$CONTRACT_ROLE_NO_, cond)

/* Helper macros */
#define _$PREFIX$CONTRACT_CREATE_EXPECT_(check, role, cond) \
    check(role, _$PREFIX$CONTRACT_TYPE_EXPECT_, cond)

#define _$PREFIX$CONTRACT_CREATE_ENSURE_(check, role, cond) \
    check(role, _$PREFIX$CONTRACT_TYPE_ENSURE_, cond)

#define _$PREFIX$CONTRACT_CREATE_ASSERT_(check, role, cond) \
    check(role, _$PREFIX$CONTRACT_TYPE_ASSERT_, cond)

/* Contract names */
#define _$PREFIX$CONTRACT_TYPE_EXPECT_ "precondition"
#define _$PREFIX$CONTRACT_TYPE_ENSURE_ "postcondition"
#define _$PREFIX$CONTRACT_TYPE_ASSERT_ "assertion"

/* Role names */
#define _$PREFIX$CONTRACT_ROLE_DEFAULT_ "default"
#define _$PREFIX$CONTRACT_ROLE_REVIEW_ "review"
#define _$PREFIX$CONTRACT_ROLE_NO_ \
    "no" /* Used in case of explicitly requested behaviour */

/* Contract modes */
#define _$PREFIX$CONTRACT_IGNORE_(role, type, cond) \
    (void) sizeof((cond) ? 1 : 0)

#define _$PREFIX$CONTRACT_ASSUME_(role, type, cond) \
    ((cond) ? (void) 0 : __builtin_unreachable())

#define _$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_(role, type, cond)           \
    do {                                                                    \
        if (!(cond)) {                                                      \
            _$PREFIX$CONTRACT_HANDLE_VIOLATION_(NEVER_CONTINUE, role, type, \
                                                cond);                      \
            abort();                                                        \
        }                                                                   \
    } while (0)

#define _$PREFIX$CONTRACT_CHECK_MAYBE_CONTINUE_(role, type, cond)           \
    do {                                                                    \
        if (!(cond)) {                                                      \
            _$PREFIX$CONTRACT_HANDLE_VIOLATION_(MAYBE_CONTINUE, role, type, \
                                                cond);                      \
            if (_$prefix$contract_unknowable_int_)                          \
                abort();                                                    \
        }                                                                   \
    } while (0)

#define _$PREFIX$CONTRACT_CHECK_ALWAYS_CONTINUE_(role, type, cond)           \
    do {                                                                     \
        if (!(cond)) {                                                       \
            _$PREFIX$CONTRACT_HANDLE_VIOLATION_(ALWAYS_CONTINUE, role, type, \
                                                cond);                       \
        }                                                                    \
    } while (0)

/* Create violation handler call */
#define _$PREFIX$CONTRACT_HANDLE_VIOLATION_(mode, role, type, cond)       \
    _$prefix$contract_handle_violation(mode, role, type, #cond, __FILE__, \
                                       __func__, __LINE__)

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

/* Standard build configurations for the default role */
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

/* Standard build configurations for the review role */
#if _$PREFIX$CONTRACT_BUILD_ == _$PREFIX$CONTRACT_BUILD_MODE_OFF_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_ _$PREFIX$CONTRACT_IGNORE_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_ _$PREFIX$CONTRACT_IGNORE_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_ _$PREFIX$CONTRACT_IGNORE_
#elif _$PREFIX$CONTRACT_BUILD_ == _$PREFIX$CONTRACT_BUILD_MODE_DEFAULT_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_ \
        _$PREFIX$CONTRACT_CHECK_ALWAYS_CONTINUE_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_ _$PREFIX$CONTRACT_IGNORE_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_ _$PREFIX$CONTRACT_IGNORE_
#elif _$PREFIX$CONTRACT_BUILD_ == _$PREFIX$CONTRACT_BUILD_MODE_AUDIT_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_ \
        _$PREFIX$CONTRACT_CHECK_MAYBE_CONTINUE_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_ \
        _$PREFIX$CONTRACT_CHECK_MAYBE_CONTINUE_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_ _$PREFIX$CONTRACT_IGNORE_
#endif

/* Options to override standard build configurations, default role */
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

/* Options to override standard build configurations, review role */
#if defined $PREFIX$CONTRACT_MODE_DEFAULT_REVIEW
    #undef _$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_
    #define _$PREFIX$CONTRACT_MODE_DEFAULT_REVIEW_ \
        $PREFIX$CONTRACT_MODE_DEFAULT_REVIEW
#endif

#if defined $PREFIX$CONTRACT_MODE_AUDIT_REVIEW
    #undef _$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_
    #define _$PREFIX$CONTRACT_MODE_AUDIT_REVIEW_ \
        $PREFIX$CONTRACT_MODE_AUDIT_REVIEW
#endif

#if defined $PREFIX$CONTRACT_MODE_AXIOM_REVIEW
    #undef _$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_
    #define _$PREFIX$CONTRACT_MODE_AXIOM_REVIEW_ \
        $PREFIX$CONTRACT_MODE_AXIOM_REVIEW
#endif

#ifdef __cplusplus
}
#endif

#endif /* _$PREFIX$CONTRACT_HEADER_CONTRACT_H_ */
