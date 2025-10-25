cmake_minimum_required(VERSION 3.16)
project(third_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(figure_lib STATIC
    src/Figure.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Trapezoid.cpp
)
target_include_directories(figure_lib PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)
add_executable(figure_tests
    tests/tests.cpp
)
target_link_libraries(figure_tests figure_lib GTest::gtest GTest::gtest_main)
target_include_directories(figure_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
enable_testing()
add_test(NAME FigureTests COMMAND figure_tests)