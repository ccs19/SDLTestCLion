//
// Created by christopher on 5/14/15.
//

#include "BitmapLoader.h"

BitmapLoader::BitmapLoader(std::string file, std::string path){
    std::string fullPath = path + file;
    this->bmp = SDL_LoadBMP(fullPath.c_str());
    if(this->bmp == nullptr){
        logger.error("Failed to load bitmap %s", SDL_GetError());
    }
}

BitmapLoader::~BitmapLoader() {
    SDL_FreeSurface(bmp);
    logger.debug("Destroying BitmapLoader");
}



