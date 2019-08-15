cmake_minimum_required(VERSION 3.0)
project(cpp_code_test
  VERSION 0.0.0.1
  DESCRIPTION "cpp 代码测试")

set(CMAKE_VERBOSE_MAKEFILE on)

add_compile_options(-g -std=c++11)

# add_library(pthread log4cplus)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lang)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/log4cplus)
