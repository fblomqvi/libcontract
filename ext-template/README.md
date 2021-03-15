# Available CCS macros
```C
$PREFIX$$EXPECT$(cond); // Shorthand for $PREFIX$$EXPECT$_DEFAULT
$PREFIX$$ENSURE$(cond); // Shorthand for $PREFIX$$ENSURE$_DEFAULT
$PREFIX$$ASSERT$(cond); // Shorthand for $PREFIX$$ASSERT$_DEFAULT

// Default role, default level CCSs. Checked in default and audit level builds.
$PREFIX$$EXPECT$_DEFAULT(cond);
$PREFIX$$ENSURE$_DEFAULT(cond);
$PREFIX$$ASSERT$_DEFAULT(cond);

// Default role, audit level CCSs. Only checked in audit level builds.
$PREFIX$$EXPECT$_AUDIT(cond);
$PREFIX$$ENSURE$_AUDIT(cond);
$PREFIX$$ASSERT$_AUDIT(cond);

// Default role, CCSs that cannot be checked. 'cond' is assumed to be true
// or not checked (ignored) depending on the build mode.
$PREFIX$$EXPECT$_AXIOM(cond);
$PREFIX$$ENSURE$_AXIOM(cond);
$PREFIX$$ASSERT$_AXIOM(cond);

/* Review role shorthand macros */
$PREFIX$$EXPECT$_REVIEW(cond) // Shorthand for $PREFIX$$EXPECT$_DEFAULT_REVIEW
$PREFIX$$ENSURE$_REVIEW(cond) // Shorthand for $PREFIX$$ENSURE$_DEFAULT_REVIEW
$PREFIX$$ASSERT$_REVIEW(cond) // Shorthand for $PREFIX$$ASSERT$_DEFAULT_REVIEW

// Review role, default level CCSs.
$PREFIX$$EXPECT$_DEFAULT_REVIEW(cond)
$PREFIX$$ENSURE$_DEFAULT_REVIEW(cond)
$PREFIX$$ASSERT$_DEFAULT_REVIEW(cond)

// Review role, audit level CCSs.
$PREFIX$$EXPECT$_AUDIT_REVIEW(cond)
$PREFIX$$ENSURE$_AUDIT_REVIEW(cond)
$PREFIX$$ASSERT$_AUDIT_REVIEW(cond)

// Review role, axiom level CCSs
$PREFIX$$EXPECT$_AXIOM_REVIEW(cond)
$PREFIX$$ENSURE$_AXIOM_REVIEW(cond)
$PREFIX$$ASSERT$_AXIOM_REVIEW(cond)

// Explicit behaviour, ignore macros
$PREFIX$$EXPECT$_IGNORE(cond)
$PREFIX$$ENSURE$_IGNORE(cond)
$PREFIX$$ASSERT$_IGNORE(cond)

// Explicit behaviour, assume macros
$PREFIX$$EXPECT$_ASSUME(cond)
$PREFIX$$ENSURE$_ASSUME(cond)
$PREFIX$$ASSERT$_ASSUME(cond)

// Explicit behaviour, never_continue macros
$PREFIX$$EXPECT$_NEVER_CONTINUE(cond)
$PREFIX$$ENSURE$_NEVER_CONTINUE(cond)
$PREFIX$$ASSERT$_NEVER_CONTINUE(cond)

// Explicit behaviour, maybe_continue macros
$PREFIX$$EXPECT$_MAYBE_CONTINUE(cond)
$PREFIX$$ENSURE$_MAYBE_CONTINUE(cond)
$PREFIX$$ASSERT$_MAYBE_CONTINUE(cond)

// Explicit behaviour, always_continue macros
$PREFIX$$EXPECT$_ALWAYS_CONTINUE(cond)
$PREFIX$$ENSURE$_ALWAYS_CONTINUE(cond)
$PREFIX$$ASSERT$_ALWAYS_CONTINUE(cond)
```

# Using a custom violation handler
If the default violation handler does not fit your needs, then you can provide
your own. Note that the violation handler must respect the following rules:
- if `mode == NEVER_CONTINUE`, then unconditionally abort;
- if `mode == MAYBE_CONTINUE`, the handler can decide wether to return or abort;
- if `mode == ALWAYS_CONTINUE`, unconditionally return.

```C
// Example handler
void custom_handler(enum $prefix$contract_violation_cont_mode mode,
		    const char* role, const char* type,
		    const char* condition, const char* file,
		    const char* function, size_t line)
{
    // Do something useful. Ideally print an informative message
    // about the contract violation.
    // ...

    // Abort or return depending on the mode.
}

int main(void)
{
    // Use your custom handler
    $prefix$contract_set_handler(custom_handler);

    // ...
}
```
