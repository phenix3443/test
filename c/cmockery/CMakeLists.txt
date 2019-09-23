cmake_minimum_required(VERSION 3.0.0)
project(cmockery_test
  VERSION 0.0.0.1
  DESCRIPTION "cmockery测试")

add_executable(test_cmockery ${CMAKE_CURRENT_SOURCE_DIR}/cmockery.c)


target_link_libraries(test_cmockery
  PRIVATE
  cmockery
  )
