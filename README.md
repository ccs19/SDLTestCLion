# SDLTestCLion<br>
Creating sample project in Clion<br>
<br>
Requirements to get it working:<br>
- MinGW-W64
- MinGW build of SDL
- Place SDL2.dll in C:/MinGW-W64/mingw64/bin
- Place\n 
  -   libSDL2.a
  -   libSDL2.dll.a
  -   libSDL2.la
  -   libSDL2_test.a
  -   libSDL2main.a<br>
in C:/MinGW-W64/mingw64/x86_64-w64-mingw32/lib<br>
- Add to compile options the following flags in this order<br>
  -lmingw32 -lSDL2main -lSDL2
<br>
Possible CMakeLists:<br>
cmake_minimum_required(VERSION 3.1)<br>
project(SDL2Sample1)<br>
<br>
set(SDL_FLAGS "-lmingw32 -lSDL2main -lSDL2")<br>
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} )<br>
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SDL_FLAGS} -std=c++11")<br>
<br>
set(SOURCE_FILES main.cpp MainWindow.cpp)<br>
add_executable(SDLTestCLion ${SOURCE_FILES})<br>
<br>
These steps should work in Linux also. Just replace windows directories with Linux directories.<br>
<br>
