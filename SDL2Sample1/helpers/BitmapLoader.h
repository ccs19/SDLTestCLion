//
// Created by christopher on 5/14/15.
//

#ifndef SDLTESTCLION_BITMAP_H
#define SDLTESTCLION_BITMAP_H
#include "../utility/common.h"


class BitmapLoader{
private:
    SDL_Surface *bmp;
    SDL_Texture *texture;
public:
public:
    /**
     *
     */
    BitmapLoader(std::string file, std::string path = ResPath::getBitmapPath());
    ~BitmapLoader();
    SDL_Surface* getBitmap(){return bmp;}

};

#endif //SDLTESTCLION_BITMAP_H
