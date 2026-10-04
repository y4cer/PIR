cmake_minimum_required(VERSION 3.20)

project(LWE VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# NTL supplies ntl.pc with its compiler and linker settings.
find_package(PkgConfig REQUIRED)
pkg_check_modules(NTL REQUIRED IMPORTED_TARGET ntl)

add_executable(lwe
    src/main.cpp
    src/lwe/lwe.cpp
)

set_target_properties(lwe PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_link_libraries(lwe PRIVATE PkgConfig::NTL)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lwe PRIVATE -Wall -Wextra -Wpedantic)
endif()
