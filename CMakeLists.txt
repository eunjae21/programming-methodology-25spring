cmake_minimum_required(VERSION 3.14)
project(TodoListTDD)

set(CMAKE_CXX_STANDARD 17)

# GoogleTest 수동 추가
add_subdirectory(extern/googletest)
include(GoogleTest)

enable_testing()

add_executable(test_todo
    todo.cpp
    test_todo.cpp
)

target_link_libraries(test_todo
    gtest_main
)

gtest_discover_tests(test_todo)
