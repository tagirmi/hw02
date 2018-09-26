cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cpp split.cpp filter.cpp)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

# unit tests
include_directories(${GTEST_INCLUDE_DIR})
add_executable(test_split split.cpp test_split.cpp)
target_link_libraries(test_split ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_filter filter.cpp test_filter.cpp)
target_link_libraries(test_filter ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(${PROJECT_NAME} test_split test_filter PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

enable_testing()
add_test(TestSplit test_split)
add_test(TestFilter test_filter)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT tagirmi@gmail.com)

include (CPack)
