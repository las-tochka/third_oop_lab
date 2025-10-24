cmake_minimum_required(VERSION 3.14)
project(FigureProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(figure_lib
			src/Figure.cpp
			src/Square.cpp
			src/Rectangle.cpp
			src/Trapezoid.cpp)
add_executable(figure_tests tests/tests.cpp)
target_link_libraries(figure_tests GTest::gtest GTest::gtest_main figure_lib)

enable_testing()
add_test(NAME FigureTests COMMAND figure_tests)

add_executable(main_exec main.cpp)
target_link_libraries(main_exec PRIVATE figure_lib)
