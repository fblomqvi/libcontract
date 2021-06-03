/* SPDX-License-Identifier: MIT */

/*
 * tests/test_basics.cc
 * Copyright (C) 2020 Ferdinand Blomqvist
 *
 * $autogen_notice$
 */
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/TestRegistry.h>

#include <CppUTestExt/MockSupport.h>
#include <CppUTestExt/MockSupportPlugin.h>

#include "$prefix$contract/contract.h"


static void test_handler(const struct $prefix$contract_violation *v)
{
    mock().actualCall("test_handler").withParameter("v", v);
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
    const struct $prefix$contract_violation v = {
        __FILE__, __LINE__, "my_function", "precondition",
        "1 == 2", "default", NEVER_CONTINUE
    };

    mock().expectOneCall("test_handler").withParameter("v", &v);

    _$prefix$contract_handle_violation(&v);
}

int main(int ac, char** av)
{
    MockSupportPlugin mockPlugin;
    TestRegistry::getCurrentRegistry()->installPlugin(&mockPlugin);
    return CommandLineTestRunner::RunAllTests(ac, av);
}

