cmake_minimum_required(VERSION 3.22)

project(common-files VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED YES)

add_compile_options(-Wall -Wextra)

include(GNUInstallDirs)

set(LIB_NAME "cf")

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
