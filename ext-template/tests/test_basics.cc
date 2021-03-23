/* SPDX-License-Identifier: MIT */

/*
 * tests/test_basics.cc
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "CppUTest/TestRegistry.h"

#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupportPlugin.h"

#include "$prefix$contract/contract.h"


static void test_handler(enum $prefix$contract_violation_cont_mode mode,
                         const char* role, const char* type,
                         const char* condition, const char* file,
                         const char* function, size_t line)
{
    mock().actualCall("test_handler")
        .withParameter("mode", mode)
        .withParameter("role", role)
        .withParameter("type", type)
        .withParameter("condition", condition)
        .withParameter("file", file)
        .withParameter("function", function)
        .withParameter("line", line);
}

TEST_GROUP(BasicFunctions)
{
    void setup()
    {
        $prefix$contract_set_handler(test_handler);
    }
};

TEST(BasicFunctions, TestGetSetHandler)
{
    CHECK($prefix$contract_get_handler() == test_handler);
}

TEST(BasicFunctions, TestContractHandleViolation)
{
    enum $prefix$contract_violation_cont_mode mode = NEVER_CONTINUE;
    const char* condition = "1 == 2";
    const char* function = "my_function";
    const char* type = "precondition";
    const char* file = __FILE__;
    const char* role = "default";
    size_t line = 42;

    mock().expectOneCall("test_handler")
        .withParameter("mode", mode)
        .withParameter("role", role)
        .withParameter("type", type)
        .withParameter("condition", condition)
        .withParameter("file", file)
        .withParameter("function", function)
        .withParameter("line", line);

    _$prefix$contract_handle_violation(mode, role, type, condition,
                                       file, function, line);
}

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}

