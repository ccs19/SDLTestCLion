# SDLTestCLion<br>
Creating sample project in Clion<br>
<br>
Requirements to get it working:<br>
- MinGW-W64
- MinGW build of SDL
- Place SDL2.dll in C:/MinGW-W64/mingw64/bin
- Place in C:/MinGW-W64/mingw64/x86_64-w64-mingw32/lib<br>
  -   libSDL2.a
  -   libSDL2.dll.a
  -   libSDL2.la
  -   libSDL2_test.a
  -   libSDL2main.a<br>

- Add to compile options the following flags in this order<br>
  -lmingw32 -lSDL2main -lSDL2
<br><br>

Possible CMakeLists:<br>
```
cmake_minimum_required(VERSION 3.1)
project(SDL2Sample1)

set(SDL_FLAGS "-lmingw32 -lSDL2main -lSDL2")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SDL_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MainWindow.cpp)
add_executable(SDLTestCLion ${SOURCE_FILES})

```
<br>
These steps should work in Linux also. Just replace windows directories with Linux directories.


Extra Note:
The above CMakeLists.txt doesn't work. the SDL_Flags must be set before this point. They work if they're set in the CMAKE_CXX_STANDARD_LIBRARIES portion of the CMake cache.
