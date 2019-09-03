cmake_minimum_required(VERSION 3.0.0)
project(zlog_test
  VERSION 0.0.0.1
  DESCRIPTION "线程函数测试")

link_libraries(zlog)

add_executable(level ${CMAKE_CURRENT_SOURCE_DIR}/level.c)
add_executable(dzlog ${CMAKE_CURRENT_SOURCE_DIR}/dzlog.c)
