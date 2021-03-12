#include <check.h>
#include <contract/ut/check.h>

#include "array.h"

#define TEST_ARRAY_SIZE 100u
#define TEST_VALUE 42

static struct array *arr;

void setup()
{
    arr = array_alloc(TEST_ARRAY_SIZE);
    ck_assert(arr);
}

void teardown()
{
    array_free(arr);
}

START_TEST(TEST_array_alloc)
{
    ck_assert(array_size(arr) == TEST_ARRAY_SIZE);
}
END_TEST

START_TEST(TEST_array_get_set)
{
    array_set(arr, 0, 12);
    ck_assert(array_get(arr, 0) == 12);

    array_set(arr, 45, TEST_VALUE);
    ck_assert(array_get(arr, 45) == TEST_VALUE);
}
END_TEST

START_TEST(TEST_array_fill)
{
    array_fill(arr, TEST_VALUE);
    for (size_t i = 0; i < array_size(arr); i++) {
        ck_assert(array_get(arr, i) == TEST_VALUE);
    }
}
END_TEST

START_TEST(TEST_array_contracts)
{
    array_fill(arr, TEST_VALUE);

    CHECK_VIOLATES_CONTRACT(array_size(NULL));

    CHECK_VIOLATES_CONTRACT(array_get(NULL, 0));
    CHECK_VIOLATES_CONTRACT(array_get(arr, TEST_ARRAY_SIZE));
    ck_assert(array_get(arr, TEST_ARRAY_SIZE - 1) == TEST_VALUE);

    CHECK_VIOLATES_CONTRACT(array_set(NULL, 0, 0));
    CHECK_VIOLATES_CONTRACT(array_set(arr, TEST_ARRAY_SIZE, 0));
    array_set(arr, TEST_ARRAY_SIZE - 1, -1);

    CHECK_VIOLATES_CONTRACT(array_fill(NULL, 0));
}
END_TEST

Suite *array_suite(void)
{
    Suite *s = suite_create("Array");

    /* Core test case */
    TCase *tc_core = tcase_create("Core");
    TCase *tc_contracts = tcase_create("Contracts");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, TEST_array_alloc);
    tcase_add_test(tc_core, TEST_array_get_set);
    tcase_add_test(tc_core, TEST_array_fill);
    suite_add_tcase(s, tc_core);

    tcase_add_checked_fixture(tc_contracts, setup, teardown);
    tcase_add_test(tc_contracts, TEST_array_contracts);
    suite_add_tcase(s, tc_contracts);

    return s;
}

int main(void)
{
    contract_ut_init();
    // contract_ut_set_verbosity(CONTRACT_UT_VERBOSE);

    Suite *s = array_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_ENV);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
