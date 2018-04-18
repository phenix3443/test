cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)

add_executable(singleton_test singleton_test.cpp)

target_link_libraries(singleton_test ${GTEST_LIBRARIES} pthread)

target_compile_options(singleton_test PUBLIC
  -std=c++11)

install(TARGETS singleton_test DESTINATION bin)
