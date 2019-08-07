cmake_minimum_required(VERSION 3.0.0)
project(network_test
  VERSION 0.0.0.1
  DESCRIPTION "网络函数测试")

add_executable(byte_order ${CMAKE_CURRENT_SOURCE_DIR}/endianness.c)
add_executable(addr_api ${CMAKE_CURRENT_SOURCE_DIR}/addr_api.c)
add_executable(sock_api ${CMAKE_CURRENT_SOURCE_DIR}/sock_api.c)
add_executable(get_remote_addr_by_accept ${CMAKE_CURRENT_SOURCE_DIR}/get_remote_addr_by_accept.c)
add_executable(get_remote_addr_by_getpeername ${CMAKE_CURRENT_SOURCE_DIR}/get_remote_addr_by_getpeername.c)
# add_executable(netinfo_api ${CMAKE_CURRENT_SOURCE_DIR}/netinfo_api.c)
# add_executable(echo_server ${CMAKE_CURRENT_SOURCE_DIR}/echo_server.c)

# target_link_libraries(test
#   )

# target_compile_definitions(test
#   )

# target_compile_options(vlna PRIVATE -std=c99)
