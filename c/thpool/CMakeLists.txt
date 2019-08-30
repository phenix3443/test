cmake_minimum_required(VERSION 3.0.0)
project(thpool_test
  VERSION 0.0.0.1
  DESCRIPTION "多线程测试")

link_libraries(pthread)

add_executable(tp_test ${CMAKE_CURRENT_SOURCE_DIR}/test.c ${CMAKE_CURRENT_SOURCE_DIR}/thpool.h ${CMAKE_CURRENT_SOURCE_DIR}/thpool.c)
