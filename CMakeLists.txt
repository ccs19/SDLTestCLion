cmake_minimum_required(VERSION 3.1)
project(SDLTestCLion)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDLTestCLion_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(SDLTestCLion ${SOURCE_FILES})

# Look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})