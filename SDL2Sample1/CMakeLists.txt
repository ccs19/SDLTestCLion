cmake_minimum_required(VERSION 3.1)
project(SDL2Sample1)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\Chris\\ClionProjects\\SDLTestCLion\\output")
set(SOURCE_FILES main.cpp MainWindow.cpp)
add_executable(SDLTestCLion ${SOURCE_FILES})