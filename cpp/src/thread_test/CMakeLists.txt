cmake_minimum_required(VERSION 3.0)

add_executable(thread_test thread_test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(thread_test ${GTEST_LIBRARIES} pthread)
target_compile_options(thread_test PUBLIC
  -std=c++11)

add_executable(thread_cleanup thread_cleanup.cpp)
target_link_libraries(thread_cleanup ${GTEST_LIBRARIES} pthread)
target_compile_options(thread_cleanup PUBLIC
  -std=c++11)

add_executable(main_thread_dead main_thread_dead.cpp)
target_link_libraries(main_thread_dead ${GTEST_LIBRARIES} pthread)
target_compile_options(main_thread_dead PUBLIC
  -std=c++11)

install(TARGETS thread_test DESTINATION bin)
