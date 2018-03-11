add_executable(test_utils test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(test_utils ${GTEST_LIBRARIES} pthread)


install(TARGETS test_utils DESTINATION bin)
