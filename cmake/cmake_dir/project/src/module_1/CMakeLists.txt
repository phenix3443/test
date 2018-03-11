cmake_minimum_required(VERSION 3.0)

add_library(person person.cpp)

target_include_directories(person PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../> #这是为了方便其他模块使用 include<module_1/person.hpp> 进行引用
  $<INSTALL_INTERFACE:include/>
  )

target_compile_options(person PUBLIC
  -std=c++11
  )

install(FILES person.hpp DESTINATION include/module_1) # 安装时候，将对外的头文件单独安装，方便其他模块使用 include<module_1/person.hpp> 进行引用
install(TARGETS person DESTINATION lib/)
