add_library(hello hello.cpp)
target_include_directories(hello PUBLIC
  INTERFACE include)
