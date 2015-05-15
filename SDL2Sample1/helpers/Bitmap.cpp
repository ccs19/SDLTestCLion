//
// Created by christopher on 5/14/15.
//

#include <iostream>
#include "../utility/ResPath.h"

Bitmap::loadBitmap(){
    std::string imagePath = res_path::getResPath() + "hello.bmp";
    std::cout << "Image Path" << imagePath;
    bmp = SDL_LoadBMP(imagePath.c_str());


}