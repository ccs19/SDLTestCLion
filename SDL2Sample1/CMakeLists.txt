cmake_minimum_required(VERSION 3.1)
project(SDL2Sample1)


IF(WIN32)
set(SDL_FLAGS "-lmingw32 -lSDL2main -lSDL2 -llog4cpp -lws2_32 ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -LC:\\MinGW-W64\\mingw64\\lib")
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} ${SDL_FLAGS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lws2_32 ")
ELSE()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDL2Sample1_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)
#link_libraries(-llog4cxx)
ENDIF()
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\Chris\\ClionProjects\\SDLTestCLion\\output")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(SDLTestCLion ${SOURCE_FILES}  utility/common.h helpers/BitmapLoader.h helpers/BitmapLoader.cpp
core/GameLoop.cpp core/GameLoop.h window/MainWindow.cpp window/MainWindow.h core/EventHandler.cpp core/EventHandler.h main.cpp)

IF(WIN32)

ELSE()
include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(SDLTestCLion ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES})
ENDIF()

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\Chris\\ClionProjects\\SDLTestCLion\\output")
#set(SOURCE_FILES main.cpp MainWindow.cpp)
#add_executable(SDLTestCLion ${SOURCE_FILES})