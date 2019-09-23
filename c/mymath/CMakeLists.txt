cmake_minimum_required(VERSION 3.0.0)
project(mymath
  VERSION 0.0.0.1
  DESCRIPTION "lib测试")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} MYLIB_SRC)

add_library(mymath ${MYLIB_SRC})
