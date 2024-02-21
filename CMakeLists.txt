cmake_minimum_required(VERSION 3.26)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES Date.cpp
        Date.h
        Register.cpp
        Register.h
        Activity.cpp
        Activity.h)

add_executable(ToDoList main.cpp ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})
target_link_libraries(ToDoList ${CURSES_LIBRARIES} core)