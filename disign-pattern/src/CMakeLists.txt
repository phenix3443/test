cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)

add_executable(test_singleton test_singleton.cpp)

target_link_libraries(test_singleton ${GTEST_LIBRARIES} pthread)

target_compile_options(test_singleton PUBLIC
  -std=c++11)

install(TARGETS test_singleton DESTINATION bin)
