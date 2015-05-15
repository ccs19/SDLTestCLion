cmake_minimum_required(VERSION 3.1)
project(SDL2Sample1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDL2Sample1_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)


set(SOURCE_FILES main.cpp window/MainWindow.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(SDLTestCLion ${SOURCE_FILES} utility/common.h helpers/Bitmap.h helpers/Bitmap.cpp)
include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(SDLTestCLion ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES})


