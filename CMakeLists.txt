cmake_minimum_required(VERSION 3.2)

#find_package(GTest REQUIRED)
#find_package(Threads REQUIRED)

project(ip_filter)
add_executable(${PROJECT_NAME} main.cpp split.cpp filter.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
