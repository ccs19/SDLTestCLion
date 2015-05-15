//
// Created by christopher on 5/14/15.
//

#ifndef SDLTESTCLION_BITMAP_H
#define SDLTESTCLION_BITMAP_H
#include "../utility/common.h"


class Bitmap{
private:
    SDL_Surface *bmp;
    SDL_Texture *texture;

public:
    /**
     *
     */
    Bitmap(std::string path);
    ~Bitmap();

};

#endif //SDLTESTCLION_BITMAP_H
