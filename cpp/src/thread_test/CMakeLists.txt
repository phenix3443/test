cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)

set(targets thread_test thread_cleanup main_thread_dead thread_race mutex_test)

foreach(t ${targets})
  add_executable(${t} ${t}.cpp)
target_link_libraries(${t} ${GTEST_LIBRARIES} pthread)
target_compile_options(${t} PUBLIC
  -std=c++11)
endforeach(t)
