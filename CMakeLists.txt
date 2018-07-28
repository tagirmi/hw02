cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cpp split.cpp filter.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

# unit tests
include_directories(${GTEST_INCLUDE_DIR})
add_executable(test_split split.cpp test_split.cpp)
target_link_libraries(test_split ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_filter filter.cpp test_filter.cpp)
target_link_libraries(test_filter ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(TestSplit test_split)
add_test(TestFilter test_filter)
