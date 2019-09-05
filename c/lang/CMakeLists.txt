cmake_minimum_required(VERSION 3.0.0)
project(c_lang_test
  VERSION 0.0.0.1
  DESCRIPTION "c 语言测试")

add_executable(overview ${CMAKE_CURRENT_SOURCE_DIR}/overview.c)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/static_var_in_h static_var_in_h_src)
add_executable(static_var_in_h ${static_var_in_h_src})

add_executable(swtich ${CMAKE_CURRENT_SOURCE_DIR}/switch.c)
