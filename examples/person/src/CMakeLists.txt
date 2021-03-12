enable_testing()

add_library(contract
    contract.c
)
add_library(person
    person.c
    person.h
)

target_compile_definitions(person PRIVATE CONTRACT_AUDIT)
target_include_directories(person INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(person PRIVATE contract)

set(off_binary person_contract_off)
set(default_binary person_contract_default)
set(audit_binary person_contract_audit)

add_executable(${off_binary}
    main.c
    person.c
    person.h
)
target_link_libraries(${off_binary} PRIVATE contract)
target_compile_definitions(${off_binary} PRIVATE CONTRACT_OFF)

add_executable(${default_binary}
    main.c
    person.c
    person.h
)
target_link_libraries(${default_binary} PRIVATE contract)

add_executable(${audit_binary}
    main.c
    person.c
    person.h
)
target_link_libraries(${audit_binary} PRIVATE contract)
target_compile_definitions(${audit_binary} PRIVATE CONTRACT_AUDIT)

set(test_name_off PersonContractOff)
set(test_name_default PersonContractDefault)
set(test_name_audit PersonContractAudit)

add_test(NAME ${test_name_off}OK
    COMMAND ${off_binary} "This is a very long name that will be too long" -5)
add_test(NAME ${test_name_off}FAIL COMMAND ${off_binary} "Jane Doe" 42 fail)

add_test(NAME ${test_name_default}OK1 COMMAND ${default_binary} "Jane Doe" 42)
add_test(NAME ${test_name_default}OK2
    COMMAND ${default_binary} "This is a very long name that will be too long" 42)

add_test(NAME ${test_name_default}FAIL1 COMMAND ${default_binary} "Jane Doe" -5)
add_test(NAME ${test_name_default}FAIL2 COMMAND ${default_binary} "Jane Doe" 42 fail)

add_test(NAME ${test_name_audit}OK COMMAND ${audit_binary} "Jane Doe" 42)
add_test(NAME ${test_name_audit}FAIL1 COMMAND ${audit_binary} "Jane Doe" -5)
add_test(NAME ${test_name_audit}FAIL2 COMMAND ${audit_binary} "Jane Doe" 42 fail)
add_test(NAME ${test_name_audit}FAIL3
    COMMAND ${audit_binary} "This is a very long name that will be too long" 42)
