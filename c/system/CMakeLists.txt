cmake_minimum_required(VERSION 3.0.0)
project(system_test
  VERSION 0.0.0.1
  DESCRIPTION "系统函数测试")

add_executable(signal ${CMAKE_CURRENT_SOURCE_DIR}/signal.c)
add_executable(all_events ${CMAKE_CURRENT_SOURCE_DIR}/all_events.c)
