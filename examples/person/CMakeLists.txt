cmake_minimum_required(VERSION 3.10)

project(person)

OPTION(TESTS "Build self tests" ON)

add_compile_options(-Wall -Wextra -pedantic)

add_subdirectory(src)

if (TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
