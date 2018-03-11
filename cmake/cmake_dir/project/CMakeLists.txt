cmake_minimum_required(VERSION 3.0)
project(cmake_project_layout VERSION 0.2)

add_subdirectory(src)
add_subdirectory(test)

set(CPACK_GENERATOR "TGZ")
include (CPack)
