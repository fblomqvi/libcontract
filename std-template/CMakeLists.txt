cmake_minimum_required(VERSION 3.10)

project($prefix$contract VERSION 1.0)

option(TESTS "Build and run unit tests" ON)

add_compile_options(-Wall -Wextra -pedantic -g -O2)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

if (TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Pkg-config file.
set($prefix$contract_PKGCONFIG_FILE $prefix$contract.pc)

set(prefix "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix "\${prefix}")
set(libdir "\${exec_prefix}/lib")
set(includedir "\${prefix}/include")
set(PACKAGE_VERSION "${$prefix$contract_VERSION_MAJOR}.${$prefix$contract_VERSION_MINOR}")

configure_file($prefix$contract.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/${$prefix$contract_PKGCONFIG_FILE} @ONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${$prefix$contract_PKGCONFIG_FILE}
    DESTINATION lib/pkgconfig
)


include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/$prefix$contractConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/example"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/$prefix$contractConfigVersion.cmake"
    VERSION "${$prefix$contract_VERSION_MAJOR}.${$prefix$contract_VERSION_MINOR}"
    COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/$prefix$contractConfig.cmake
    DESTINATION lib/cmake/$prefix$contract
)

# install the configuration file to the build directory
export(EXPORT $prefix$contract_libs
  FILE "${CMAKE_CURRENT_BINARY_DIR}/$prefix$contract.cmake"
)
