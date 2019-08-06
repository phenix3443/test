cmake_minimum_required(VERSION 3.0.0)
project(c99_test
  VERSION 0.0.0.1
  DESCRIPTION "c99特殊性测试")

add_executable(vlna ${CMAKE_CURRENT_SOURCE_DIR}/vlna.c)
add_executable(btest ${CMAKE_CURRENT_SOURCE_DIR}/btest.c)
# target_link_libraries(test
#   )

# target_compile_definitions(test
#   )

# target_compile_options(vlna PRIVATE -std=c99)
