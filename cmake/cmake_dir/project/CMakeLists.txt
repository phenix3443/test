cmake_minimum_required(VERSION 3.0)
project(cmake_project_layout VERSION 0.2)

add_subdirectory(src)           # 添加源码目录
add_subdirectory(test)          # 添加测试目录

set(CPACK_GENERATOR "TGZ")
include (CPack)                 # 只在project下设置打包的路径
