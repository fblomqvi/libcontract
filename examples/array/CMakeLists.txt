cmake_minimum_required(VERSION 3.10)

project(array VERSION 1.0)

OPTION(TESTS "Build self tests" ON)

add_subdirectory(contract)
add_subdirectory(src)

if (TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/arrayConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/example"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/arrayConfigVersion.cmake"
    VERSION "${array_VERSION_MAJOR}.${array_VERSION_MINOR}"
    COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/arrayConfig.cmake
    DESTINATION lib/cmake/array
)

# install the configuration file to the build directory
export(EXPORT array_lib
  FILE "${CMAKE_CURRENT_BINARY_DIR}/array.cmake"
)
