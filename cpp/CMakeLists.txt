cmake_minimum_required(VERSION 3.0)
project(cpp_code_test)

find_package(GTest REQUIRED)

# 语言特性测试
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/lang LANG_SRC)

add_executable(lang_test ${LANG_SRC})
target_compile_options(lang_test
  -std=c++11
  )

target_link_libraries(lang_test
  pthread
  )

# 多线程相关测试
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/pthread THREAD_SRC)
add_executable(log4cplus_test ${THREAD_SRC})
target_link_libraries(thread_test
  pthread
  )

# log4cplus 测试
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/log4cplus LOG4CPLUS_SRC)
add_executable(log4cplus_test ${LOG4CPLUS_SRC})
target_compile_options(lang_test
  -std=c++11
  )
target_link_libraries(log4cplus_test
  log4cplus
  )
