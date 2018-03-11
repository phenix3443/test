cmake_minimum_required(VERSION 3.0)

include_directories(
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/>
  )

add_subdirectory(main)
add_subdirectory(module_1)
