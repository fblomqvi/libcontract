find_package(contract)

add_library(array
    array.c
    array.h
)

target_compile_definitions(array PUBLIC ${CONTRACT_LEVEL})
target_link_libraries(array PUBLIC contract)

add_library(array_ut EXCLUDE_FROM_ALL
    array.c
    array.h
)

target_compile_definitions(array_ut PUBLIC CONTRACT_TEST)
target_link_libraries(array_ut PUBLIC contract)
target_include_directories(array_ut INTERFACE ${CMAKE_CURRENT_LIST_DIR})

install(TARGETS array
    DESTINATION lib
    EXPORT array_lib
)

install(FILES array.h DESTINATION include)

install(EXPORT array_lib
    FILE array.cmake
    DESTINATION lib/cmake/array
)
