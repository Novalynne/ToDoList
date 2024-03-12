cmake_minimum_required(VERSION 3.26)

add_subdirectory(./lib/googletest-1.8.x)
set(gtest_SOURCE_DIR, ./lib/googletest-1.8.x/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp DateTest.cpp RegisterTest.cpp ActivityTest.cpp)
add_executable(runToDoListTests ${TEST_SOURCE_FILES})
target_link_libraries(runToDoListTests gtest gtest_main core ${CURSES_LIBRARIES})