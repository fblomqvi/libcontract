add_library(test_helpers_lib STATIC ../test_helper.c)
target_include_directories(test_helpers_lib INTERFACE ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(test_helpers_lib PUBLIC $prefix$contract)
target_compile_definitions(test_helpers_lib PRIVATE $PREFIX$CONTRACT_TEST)

set(ut_contract_libs test_helpers_lib)

add_executable(test_ut_check test_ut_check.c)

target_link_libraries(test_ut_check
    PRIVATE
	PkgConfig::check
	${ut_contract_libs}
)

add_executable(test_ut_nested_checks test_ut_nested_checks.c)

target_link_libraries(test_ut_nested_checks
    PRIVATE
	PkgConfig::check
	${ut_contract_libs}
)

add_test(NAME TestUtNestedChecks COMMAND test_ut_nested_checks)
add_test(NAME TestUtCheck COMMAND test_ut_check)

add_executable(test_ut_cpputest test_ut_cpputest.cc)

target_link_libraries(test_ut_cpputest
    PRIVATE
	CppUTest
	${ut_contract_libs}
)

add_test(NAME TestUtCppUTest COMMAND test_ut_cpputest)

pkg_check_modules(cmocka IMPORTED_TARGET cmocka)
if (cmocka_FOUND)
    add_executable(test_ut_cmocka test_ut_cmocka.c)

    target_link_libraries(test_ut_cmocka
	PRIVATE
	    PkgConfig::cmocka
	    ${ut_contract_libs}
    )

    add_test(NAME TestUtCmocka COMMAND test_ut_cmocka)
else()
    message(STATUS "Cannot find 'cmocka', ommitting unit tests that depend on it")
endif()

pkg_check_modules(gtest IMPORTED_TARGET gtest)
if (gtest_FOUND)
    add_executable(test_ut_gtest test_ut_gtest.cc)

    target_link_libraries(test_ut_gtest
	PRIVATE
	    PkgConfig::gtest
	    ${ut_contract_libs}
    )

    add_test(NAME TestUtGtest COMMAND test_ut_gtest)
else()
    message(STATUS "Cannot find 'gtest', ommitting unit tests that depend on it")
endif()
