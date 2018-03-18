cmake_minimum_required(VERSION 3.0)

add_executable(tmp_test tmp_test.cpp)

add_executable(lang_overview overview.cpp)

target_compile_options(lang_overview PUBLIC
  -std=c++11)

add_executable(lang_test
  lang_test.cpp

  io_test.cpp
  control_test.cpp

  buildin_test.cpp
  number_test.cpp
  var_test.cpp
  extern_var.cpp
  extern_test.cpp
  const_test.cpp

  )

find_package(GTest REQUIRED)
target_link_libraries(lang_test ${GTEST_LIBRARIES} pthread)


target_compile_options(lang_test PUBLIC
  -std=c++11)

install(TARGETS lang_test DESTINATION bin)
