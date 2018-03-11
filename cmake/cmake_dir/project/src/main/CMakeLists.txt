cmake_minimum_required(VERSION 3.0)

add_executable(say_hello main.cpp)

target_link_libraries(say_hello person)

install(TARGETS say_hello DESTINATION bin/)
