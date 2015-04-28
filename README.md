# SDLTestCLion
Creating sample project in Clion

Requirements to get it working:
-MinGW-W64
-MinGW build of SDL
-Place SDL2.dll in C:/MinGW-W64/mingw64/bin
-Place\n 
  libSDL2.a<br>
  libSDL2.dll.a\n
  libSDL2.la\n
  libSDL2_test.a\n
  libSDL2main.a\n
in C:/MinGW-W64/mingw64/x86_64-w64-mingw32/lib
-Add to compile options the following flags in this order
  -lmingw32 -lSDL2main -lSDL2

Possible CMakeLists:
cmake_minimum_required(VERSION 3.1)
project(SDL2Sample1)

set(SDL_FLAGS "-lmingw32 -lSDL2main -lSDL2")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SDL_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MainWindow.cpp)
add_executable(SDLTestCLion ${SOURCE_FILES})

These steps should work in Linux also. Just replace windows directories with Linux directories.
