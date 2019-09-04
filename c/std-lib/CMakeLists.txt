cmake_minimum_required(VERSION 3.0.0)
project(c_stdlib_test
  VERSION 0.0.0.1
  DESCRIPTION "c 语言标准库测试")

add_executable(perror ${CMAKE_CURRENT_SOURCE_DIR}/perror.c)
