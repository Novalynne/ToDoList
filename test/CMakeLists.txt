cmake_minimum_required(VERSION 3.26)

add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp DateTest.cpp RegisterTest.cpp ActivityTest.cpp)
add_executable(runToDoListTests ${TEST_SOURCE_FILES})
target_link_libraries(runToDoListTests gtest gtest_main core)