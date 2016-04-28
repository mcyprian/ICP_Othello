cmake_minimum_required(VERSION 2.6)
project(Othello)

include_directories($(CMAKE_PROJECT_DIR)include)

set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall -Wextra -pedantic -O0")
set(CMAKE_SOURCE_DIR $(CMAKE_PROJECT_DIR)/src )
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(src)
