cmake_minimum_required(VERSION 3.16)
project(TrainingProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_GENERATOR "Ninja")

add_executable(training_project src/main.cpp)

enable_testing()
add_executable(training_project_test tests/main.cpp)
target_link_libraries(training_project_test gtest gtest_main)

add_test(NAME training_project_test COMMAND training_project_test)