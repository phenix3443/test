cmake_minimum_required(VERSION 3.0.0)
project(c_code_test
  VERSION 0.0.0.1
  DESCRIPTION "c 代码测试")

set(CMAKE_VERBOSE_MAKEFILE on)

add_compile_options(-g -std=c99)

add_subdirectory(c99)
add_subdirectory(lang)
add_subdirectory(network)
