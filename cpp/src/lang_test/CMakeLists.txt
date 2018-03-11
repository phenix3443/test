cmake_minimum_required(VERSION 3.0)

add_executable(lang_test lang_test.cpp io_test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(lang_test ${GTEST_LIBRARIES} pthread)


install(TARGETS lang_test DESTINATION bin)
