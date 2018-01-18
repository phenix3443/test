cmake_minimum_required(VERSION 3.0)
project(cmake_test VERSION 0.2)

add_library(hello src/hello/hello.cpp)
target_include_directories(hello PRIVATE
  /home/lsl/github/test/cmake/src/hello/include)

add_executable(cmake_test src/test/test.cpp)
target_link_libraries(cmake_test hello)
target_include_directories(cmake_test PUBLIC
  /home/lsl/github/test/cmake/src/hello/include)

message(${PROJECT_NAME})
message(${PROJECT_VERSION})
message(${cmake_test_SOURCE_DIR})
# message(${PROJECT_DESCRIPTION})

install(TARGETS hello DESTINATION bin)
include(CPack)
