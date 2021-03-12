find_package(PkgConfig REQUIRED)
pkg_check_modules(Check REQUIRED IMPORTED_TARGET check)

add_executable(test_array test_array.c)
target_link_libraries(test_array
    PRIVATE
	array_ut
	PkgConfig::Check
)

add_test(NAME TestArray COMMAND test_array)
