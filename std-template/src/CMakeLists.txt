set(libcontract_headers
    ${PROJECT_SOURCE_DIR}/include/$prefix$contract/contract.h
)
    
add_library($prefix$contract
    contract.c
    ${libcontract_headers}
)

target_include_directories($prefix$contract PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/$prefix$contract>  # <prefix>/include/$prefix$contract
)

set(libcontract_ut_headers
    ${PROJECT_SOURCE_DIR}/include/$prefix$contract/ut/check.h
    ${PROJECT_SOURCE_DIR}/include/$prefix$contract/ut/cmocka.h
    ${PROJECT_SOURCE_DIR}/include/$prefix$contract/ut/CppUTest.h
    ${PROJECT_SOURCE_DIR}/include/$prefix$contract/ut/framework.h
    ${PROJECT_SOURCE_DIR}/include/$prefix$contract/ut/gtest.h
)

install(TARGETS $prefix$contract
    DESTINATION lib
    EXPORT $prefix$contract_libs
)

install(FILES ${libcontract_headers} DESTINATION include/$prefix$contract)
install(FILES ${libcontract_ut_headers} DESTINATION include/$prefix$contract/ut)

install(EXPORT $prefix$contract_libs
    FILE $prefix$contract.cmake
    DESTINATION lib/cmake/$prefix$contract
)
