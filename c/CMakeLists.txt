cmake_minimum_required(VERSION 3.0.0)
project(c_code_test
  VERSION 0.0.0.1
  DESCRIPTION "c 代码测试")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

add_executable(test ${SRC})

# target_link_libraries(test
#   )

# target_compile_definitions(test
#   )

# target_compile_options(test
#   )

set_target_properties(turn_manager
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
  )
