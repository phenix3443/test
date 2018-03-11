cmake_minimum_required(VERSION 3.0)
project(cpp_project)

add_subdirectory(src/test)

set(CPACK_GENERATOR "TGZ")
include (CPack)
