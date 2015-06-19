cmake_minimum_required(VERSION 3.1)
project(SDL2Sample1)

IF(WIN32)

#logging flags
SET(LOGGING_FLAGS "-llog4cpp -lws2_32")

#SDL variables
set(SDL_FLAGS "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image")
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} ${SDL_FLAGS} ${LOGGING_FLAGS}")
ELSE()
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDL2Sample1_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)
ENDIF()

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\Chris\\ClionProjects\\SDLTestCLion\\output")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(SDLTestCLion ${SOURCE_FILES}  utility/common.h helpers/ImageLoader.h helpers/ImageLoader.cpp
core/GameLoop.cpp core/GameLoop.h window/MainWindow.cpp window/MainWindow.h
core/EventHandler.cpp core/EventHandler.h
main.cpp
utility/resource_path.h utility/resource_path_template.h
helpers/TextureLoader.cpp helpers/TextureLoader.h
player/Dot.cpp player/Dot.h
settings/GameConfig.cpp settings/GameConfig.h)

IF(WIN32)
ELSE()
include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(SDLTestCLion ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES})
ENDIF()