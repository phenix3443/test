cmake_minimum_required(VERSION 3.0)
project(cmake_test VERSION 0.2  #[[DESCRIPTION "test"]])
add_executable(hello src/hello/hello.cpp)

message(${PROJECT_NAME})
message(${PROJECT_VERSION})
message(${cmake_test_SOURCE_DIR})
# message(${PROJECT_DESCRIPTION})

install(TARGETS hello DESTINATION bin)
include(CPack)
