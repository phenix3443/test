cmake_minimum_required(VERSION 3.0.0)
project(thread_test
  VERSION 0.0.0.1
  DESCRIPTION "线程函数测试")

link_libraries(pthread)

add_executable(thread ${CMAKE_CURRENT_SOURCE_DIR}/thread.c)
add_executable(main_thread_exit ${CMAKE_CURRENT_SOURCE_DIR}/main_thread_exit.c)
