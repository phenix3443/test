cmake_minimum_required(VERSION 3.0.0)
project(libevent_test
  VERSION 0.0.0.1
  DESCRIPTION "libevent函数测试")

link_libraries(event)

add_executable(tutor ${CMAKE_CURRENT_SOURCE_DIR}/tutor.c)
