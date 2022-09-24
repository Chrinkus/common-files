# Test with CMocka
find_package(cmocka)

# Project headers
include_directories("${PROJECT_SOURCE_DIR}/src")

# Test build target
add_custom_target(tests)

# List of tests
set(test_sources
        "tests_config.c"
        "tests_home.c"
        "tests_path.c"
)

# Strip prefix
string(LENGTH "tests_" test_prefix_len)

# Generate test names
foreach(file IN LISTS test_sources)
        get_filename_component(file_we "${file}" NAME_WE)
        string(SUBSTRING "${file_we}" ${test_prefix_len} -1 func)
        set(cmd_name "${func}_test")

        add_executable("${cmd_name}" EXCLUDE_FROM_ALL "${file}")
        target_link_libraries("${cmd_name}" PRIVATE "${LIB_NAME}" cmocka)
        add_test(NAME "${func}" COMMAND "${cmd_name}")
        add_dependencies(tests "${cmd_name}")
endforeach()
