cmake_minimum_required(VERSION 3.22.0)
project(Lesson03_Task1)

add_subdirectory(Catch2 Catch2-build)
add_executable(task1 "List.cpp" "test-main.cpp")
target_link_libraries(task1 PRIVATE Catch2::Catch2)