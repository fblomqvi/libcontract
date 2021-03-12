__libcontract__ provides a convenient way to create a contract checking
statement (CCS) library for any project written in C.

__libcontract__ has two templates that can be used to generate a CCS library, a
basic template and an extended template. The basic version implements CCSs
roughly as was proposed for C++20, while the more extensive set of CCSs
correspond to the proposal/roadmap [Contract Checking in C++: A (long-term)
Road Map](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1332r0.txt)

The goal of __libcontract__ is to provide CCS libraries that are useful for
both library and application developers. Moreover, the CCSs must be easily
testable during unit testing.

# Usage
The usage model is simple: Use `create_contract_lib.py` to create a CCS library
from one of the provided templates according to your needs. Then use the
created library in your project in one of three ways:
- Copy the relevant files into your project
- Include the whole library directory in your project (requires cmake)
- Build and install the CCS library and use it like any other installed library

# Dependencies
`create_contract_lib.py` requires [docopt](https://github.com/docopt/docopt).
The CCS libraries created from the templates have no dependencies themselves,
but to build and run all the unit tests you need:
- [check](https://libcheck.github.io/check/)
- [cmocka](https://cmocka.org/)
- [CppUTest](https://cpputest.github.io/)
- [GoogleTest](https://github.com/google/googletest)

# Compiler support
Compiling the generated CCS libraries requires a C99 compiler, and building the
unit tests require a C/C++ compilers that conforms to the minimum requirements
imposed by the unit testing frameworks.

Some of CCS macros rely on  the `__builtin_unreachable` intrinsic and usage
thus requires `gcc` or `clang`.

# Standard assert vs CCS macros
Why bother to use CCS macros when the standard library already provides the
`assert` macro? There are several benefits to the CCS macros:
- Easier to find the violations. `assert` only prints the failed assertion, but
  the CCS macros pass the source location to the violation handler.
- The CCSs are easy to verify during unit testing with the help of the
  `CHECK_VIOLATES_CONTRACT` macro. In contrast, it is hard to test asserts in
  unit tests without overriding the `assert` macro, replace `abort` during
  linking or similar tricks. Alternatively, on can use a unit testing framework
  that supports catching signals. This is how the CCS macros and the default
  violation handler is tested. It is, however, very slow, and would not be a
  good testing strategy in large projects.
- The code inside your CCSs will be checked by the compiler even if all CCSs
  are turned off.
- More versatile:
    - several levels of CCSs, each with configurable behaviour
    - you can easily use your own violation handler

There are ways to make standard asserts easier to debug, see for instance
[asserts in llvm](https://llvm.org/docs/CodingStandards.html#assert-liberally),
but is still not as verbose as the information provided by the CCS macros.

# Basic vs extended CCSs
For most new projects the basic version of the CCSs should suffice. If you want
to add CCSs to an existing projects of at least moderate size, then the
extended version is probably a better fit because of the *review role*. The
extended version is compatible with the basic version so it is not a problem if
you start out with the basic one and then later on realize that you need the
functionality provided by the extended version.

# How-to
Suppose we are working on a project called `gsl`. Furthermore, we have decided
that basic CCSs are sufficient for our needs.

First, we generate our CCS library from the basic template:

    ./create_contract_lib.py --prefix=gsl_ std-template

## Embed the CCS library in your project
The easiest way to include the generated CCS library into your project is to
copy the header and source files to your project and add them to your build.

    cp -r gsl_contract/include/gsl_contract <project include directory>
    cp gsl_contract/src/contract.c <project source directory>

The advantage of this way is that the CCS library will be distributed along
with your project. If you chose this method, then it might still be a good idea
to build the CCS library and run the self tests to verify that everything is
working correctly.

## Building with autotools

    # autotools
    cd gsl_contract
    autoreconf -if
    ./configure
    make

    # Optionally run self tests
    make check

The configure script will fail if if all the available dependencies are not
found. Either install the missing dependencies or disable building of the self
tests:

    ./configure --disable-tests


## Building with cmake

    # cmake
    cd gsl_contract
    mkdir build && cd build
    cmake ..
    make

    # Optionally run self tests
    make test

cmake will fail if if all the available dependencies are not found. Either
install the missing dependencies or disable building of the self tests:

    cmake .. -DTESTS=OFF

## Writing CCSs
To make the CCS macros available we must include the header
`gsl_contract/contract.h`.

```C
#include "gsl_contract/contract.h"

// Very contrived example
void gsl_strcpy(char* dest, cont char* src)
{
    GSL_EXPECT(dest != NULL);
    GSL_EXPECT(src != NULL);
    // Do the real work
}
```

```C
GSL_EXPECT(cond); // Shorthand for GSL_EXPECT_DEFAULT
GSL_ENSURE(cond); // Shorthand for GSL_ENSURE_DEFAULT
GSL_ASSERT(cond); // Shorthand for GSL_ASSERT_DEFAULT

// Default level CCSs. Checked in default and audit level builds.
GSL_EXPECT_DEFAULT(cond);
GSL_ENSURE_DEFAULT(cond);
GSL_ASSERT_DEFAULT(cond);

// Audit level CCSs. Only checked in audit level builds.
GSL_EXPECT_AUDIT(cond);
GSL_ENSURE_AUDIT(cond);
GSL_ASSERT_AUDIT(cond);

// CCSs that cannot be checked. 'cond' is assumed to be true or not
// checked (ignored) depending on the build mode.
GSL_EXPECT_AXIOM(cond);
GSL_ENSURE_AXIOM(cond);
GSL_ASSERT_AXIOM(cond);
```

## Testing CCSs during unit testing
__libcontract____ already supports four unit testing frameworks:
- [check](https://libcheck.github.io/check/)
- [cmocka](https://cmocka.org/)
- [CppUTest](https://cpputest.github.io/))
- [GoogleTest](https://github.com/google/googletest)

Furthermore, it easy to add support for more unit testing frameworks.

CCSs are tested with the macro `CHECK_VIOLATES_CONTRACT`.

```C
// Function to be testes in some .c file.
void foo(int *ptr)
{
    GSL_EXPECT(ptr != NULL);
    // Do something useful
}

// In UT file. Include the header that corresponds to the UT
// framework in use.
#include "gsl_contract/ut/CppUTest.h"

TEST(test_foo, test_precondition)
{
    CHECK_VIOLATES_CONTRACT(foo(NULL));
}
```

If there is no contract violation, then the test will be marked as failed. You
can only test one contract violation at the time with the violation check
macro. The first violation will be caught, and the code that would produce the
second violation will never be run.

```C
// Wrong. bar will never be called because foo(NULL) violates the precondition.
TEST(test_foo, test_precondition)
{
    CHECK_VIOLATES_CONTRACT(foo(NULL); bar(NULL));
}

// The correct way to test many CCSs in the same test.
TEST(test_foo, test_precondition)
{
    CHECK_VIOLATES_CONTRACT(foo(NULL));
    CHECK_VIOLATES_CONTRACT(bar(NULL));
}
```

### Limitations
The mechanism that allows CCSs to be tested during unit tests is implemented
with `setjmp` and `longjmp`. The global variables are thread local, but the
mechanism is not thread safe. Certain multithreaded use cases are safe, while
others are not.

## Using a custom violation handler
Whenever a contract is violated the global contract violation handler is
called. The default handler prints a contract violation message to `stderr`,
and then calls `abort()`. If the default violation handler does not fit your
needs, then you can provide your own. See the README's of the CCS templates for
further details.

## Customizing the CCS macros
It is possible to customize the generated CCS macros to a certain degree by
giving appropriate options to `create_contract_lib.py`. For instance,

    ./create_contract_lib.py --prefix=gsl_ --expect-name=pre --ensure-name=post std-templates

will create a CCS library with the macros
```C
GSL_PRE(cond);
GSL_POST(cond);
GSL_ASSERT(cond);
...
```

See the help of `create_contract_lib.py` for all available options.

# Resources and references

- Papers
    - [Contract Checking in C++: A (long-term) Road Map](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1332r0.txt)
- Talks
    - [Avoid Misuse of Contracts! - Rostislav Khlebnikov - CppCon 2019](https://www.youtube.com/watch?v=KFJ5p-T-S7Q)
    - [CppCon 2019: Joshua Berne "Contract use: Past, Present, and Future"](https://www.youtube.com/watch?v=mmyIZzqh5ls)
    - [CppCon 2014: John Lakos "Defensive Programming Done Right, Part I"](https://www.youtube.com/watch?v=1QhtXRMp3Hg)
    - [CppCon 2014: John Lakos "Defensive Programming Done Right, Part II"](https://www.youtube.com/watch?v=tz2khnjnUx8)
