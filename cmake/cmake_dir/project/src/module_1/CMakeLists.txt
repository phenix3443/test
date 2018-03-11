cmake_minimum_required(VERSION 3.0)

add_library(person person.cpp)

target_compile_options(person
  PUBLIC -std=c++11
  )

install(FILES person.hpp DESTINATION include/module_1)
install(TARGETS person DESTINATION lib/)
