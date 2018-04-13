cmake_minimum_required(VERSION 3.0)

add_executable(thread_test thread_test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(thread_test ${GTEST_LIBRARIES} pthread)

target_compile_options(thread_test PUBLIC
  -std=c++11)

install(TARGETS thread_test DESTINATION bin)
