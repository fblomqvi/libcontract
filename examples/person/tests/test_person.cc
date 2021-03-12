#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <contract/ut/CppUTest.h>

#include "person.h"

static const char *const jane_doe_name = "Jane Doe";
static const int jane_doe_age = 42;

/* Names with 31 and 32 characters respective */
static const char *const ok_name = "This name is just short enough.";
static const char *const long_name = "This is a very long name. Boom!!";

static const int ok_age = 0;
static const int negative_age = -1;

TEST_GROUP(PersonCreateFree){};

TEST(PersonCreateFree, TEST_person_create_free)
{
    CHECK_VIOLATES_CONTRACT(person_create(NULL, ok_age));
    CHECK_VIOLATES_CONTRACT(person_create(long_name, ok_age));
    CHECK_VIOLATES_CONTRACT(person_create(ok_name, negative_age));

    auto p = person_create(ok_name, ok_age);
    CHECK(p);
    person_free(p);
}

TEST_GROUP(PersonGetSet)
{
    struct person *jane_doe;

    void setup()
    {
        jane_doe = person_create(jane_doe_name, jane_doe_age);
        CHECK(jane_doe);
    }

    void teardown()
    {
        person_free(jane_doe);
    }
};

TEST(PersonGetSet, TEST_person_get_set_name)
{
    CHECK_VIOLATES_CONTRACT(person_get_name(NULL));

    const char *name = person_get_name(jane_doe);
    STRCMP_EQUAL(name, jane_doe_name);

    CHECK_VIOLATES_CONTRACT(person_set_name(NULL, ok_name));
    CHECK_VIOLATES_CONTRACT(person_set_name(jane_doe, NULL));
    CHECK_VIOLATES_CONTRACT(person_set_name(jane_doe, long_name));

    person_set_name(jane_doe, ok_name);
    name = person_get_name(jane_doe);
    STRCMP_EQUAL(name, ok_name);
}

TEST(PersonGetSet, TEST_person_get_set_age)
{
    CHECK_VIOLATES_CONTRACT(person_get_age(NULL));

    int age = person_get_age(jane_doe);
    CHECK(age == jane_doe_age);

    CHECK_VIOLATES_CONTRACT(person_set_age(NULL, ok_age));
    CHECK_VIOLATES_CONTRACT(person_set_age(jane_doe, negative_age));

    person_set_age(jane_doe, ok_age);
    age = person_get_age(jane_doe);
    CHECK(age == ok_age);
}

int main(int ac, char **av)
{
    contract_ut_init();
    return CommandLineTestRunner::RunAllTests(ac, av);
}
