cmake_minimum_required(VERSION 3.0.0)
project(libcurl_test
  VERSION 0.0.0.1
  DESCRIPTION "libcurl测试")

link_libraries(curl)
add_executable(get_req ${CMAKE_CURRENT_SOURCE_DIR}/get_req.c)
add_executable(post_req ${CMAKE_CURRENT_SOURCE_DIR}/post_req.c)
