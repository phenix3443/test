cmake_minimum_required(VERSION 3.0.0)
project(thread_test
  VERSION 0.0.0.1
  DESCRIPTION "线程函数测试")

link_libraries(pthread)

add_executable(tutor ${CMAKE_CURRENT_SOURCE_DIR}/tutor.c)
