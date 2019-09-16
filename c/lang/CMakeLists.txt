cmake_minimum_required(VERSION 3.0.0)
project(c_lang_test
  VERSION 0.0.0.1
  DESCRIPTION "c 语言测试")

add_executable(hello_c ${CMAKE_CURRENT_SOURCE_DIR}/hello_c.c)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/static_var_in_h static_var_in_h_src)
add_executable(static_var_in_h ${static_var_in_h_src})


add_executable(swtich ${CMAKE_CURRENT_SOURCE_DIR}/switch.c)

add_executable(sizeof ${CMAKE_CURRENT_SOURCE_DIR}/sizeof.c)
add_executable(comma_in_while.c ${CMAKE_CURRENT_SOURCE_DIR}/comma_in_while.c)
add_executable(count_1 ${CMAKE_CURRENT_SOURCE_DIR}/count_1.c)


add_executable(ntoc ${CMAKE_CURRENT_SOURCE_DIR}/ntoc.c)
add_executable(va_arg ${CMAKE_CURRENT_SOURCE_DIR}/va_arg.c)
