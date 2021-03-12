include(FindPkgConfig)
pkg_check_modules(check REQUIRED IMPORTED_TARGET check)

set(test_contract_libs
    PRIVATE
	$prefix$contract
	PkgConfig::check
)

add_executable(test_contract_off
    test_contract_off.c
    test_helper.c
)

target_link_libraries(test_contract_off ${test_contract_libs})
target_compile_definitions(test_contract_off PRIVATE $PREFIX$CONTRACT_OFF)

add_executable(test_contract_default
    test_contract_default.c
    test_helper.c
)

target_link_libraries(test_contract_default ${test_contract_libs})
target_compile_definitions(test_contract_default PRIVATE $PREFIX$CONTRACT_DEFAULT)

add_executable(test_contract_audit
    test_contract_audit.c
    test_helper.c
)

target_link_libraries(test_contract_audit ${test_contract_libs})
target_compile_definitions(test_contract_audit PRIVATE $PREFIX$CONTRACT_AUDIT)

add_executable(test_contract_level_override
    test_contract_level_override.c
    test_helper.c
)

target_link_libraries(test_contract_level_override ${test_contract_libs})
target_compile_definitions(test_contract_level_override
    PRIVATE
	$PREFIX$CONTRACT_MODE_DEFAULT=_$PREFIX$CONTRACT_IGNORE_
	$PREFIX$CONTRACT_MODE_AUDIT=_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_
	$PREFIX$CONTRACT_MODE_AXIOM=_$PREFIX$CONTRACT_CHECK_NEVER_CONTINUE_
)

add_test(NAME TestContractOff COMMAND test_contract_off)
add_test(NAME TestContractDefault COMMAND test_contract_default)
add_test(NAME TestContractAudit COMMAND test_contract_audit)
add_test(NAME TestContractLevelOverride COMMAND test_contract_level_override)

find_package(CppUTest REQUIRED)
add_executable(test_basics test_basics.cc)
target_link_libraries(test_basics
    PRIVATE
	CppUTest
	CppUTestExt
	$prefix$contract
)

add_test(NAME TestBasics COMMAND test_basics)

add_subdirectory(ut)
