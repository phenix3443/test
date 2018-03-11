cmake_minimum_required(VERSION 3.0)

add_library(person person.cpp)

message(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(person PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
  $<INSTALL_INTERFACE:include/>)

target_compile_options(person
  PUBLIC -std=c++11
  )

install(FILES person.hpp DESTINATION include/person)
install(TARGETS person DESTINATION lib/)
