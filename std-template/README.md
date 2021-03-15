# Available CCS macros
```C
$PREFIX$$EXPECT$(cond); // Shorthand for $PREFIX$$EXPECT$_DEFAULT
$PREFIX$$ENSURE$(cond); // Shorthand for $PREFIX$$ENSURE$_DEFAULT
$PREFIX$$ASSERT$(cond); // Shorthand for $PREFIX$$ASSERT$_DEFAULT

// Default level CCSs. Checked in default and audit level builds.
$PREFIX$$EXPECT$_DEFAULT(cond);
$PREFIX$$ENSURE$_DEFAULT(cond);
$PREFIX$$ASSERT$_DEFAULT(cond);

// Audit level CCSs. Only checked in audit level builds.
$PREFIX$$EXPECT$_AUDIT(cond);
$PREFIX$$ENSURE$_AUDIT(cond);
$PREFIX$$ASSERT$_AUDIT(cond);

// CCSs that cannot be checked. 'cond' is assumed to be true or not
// checked (ignored) depending on the build mode.
$PREFIX$$EXPECT$_AXIOM(cond);
$PREFIX$$ENSURE$_AXIOM(cond);
$PREFIX$$ASSERT$_AXIOM(cond);
```

# Using a custom violation handler
If the default violation handler does not fit your needs, then you can provide
your own. Note that the violation handler should unconditionally abort.

```C
// Example handler
void custom_handler(const char* type, const char* condition,
		    const char* file, const char* function,
		    size_t line)
{
    // Do something useful. Ideally print an informative message
    // about the contract violation.
    // ...

    // NB: The violation handler must never return.
}

int main(void)
{
    // Use your custom handler
    $prefix$contract_set_handler(custom_handler);

    // ...
}
```
