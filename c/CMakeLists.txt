cmake_minimum_required(VERSION 3.0.0)
project(c_code_test
  VERSION 0.0.0.1
  DESCRIPTION "c 代码测试")

add_executable(test ${SRC}/test.c)

# target_link_libraries(test
#   )

# target_compile_definitions(test
#   )

# target_compile_options(test
#   )

add_subdirectory(c99)
