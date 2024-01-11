cmake_minimum_required(VERSION 3.22.0)
project(Lesson03_Task2)

add_subdirectory(Catch2 Catch2-build)
add_executable(task2 "List.cpp" "test-main.cpp")
target_link_libraries(task2 PRIVATE Catch2::Catch2)