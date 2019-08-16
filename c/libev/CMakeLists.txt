cmake_minimum_required(VERSION 3.0.0)
project(libev_test
  VERSION 0.0.0.1
  DESCRIPTION "网络函数测试")

link_libraries(ev)

add_executable(tutor ${CMAKE_CURRENT_SOURCE_DIR}/tutor.c)
