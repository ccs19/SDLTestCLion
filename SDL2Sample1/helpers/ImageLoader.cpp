//
// Created by christopher on 5/14/15.
//

#include "ImageLoader.h"

ImageLoader::ImageLoader(std::string file, std::string path){
    loadImage(file, path);
    if(success){
        optimizedSurface = loadedSurface;
    }
}

ImageLoader::ImageLoader(std::string file, std::string path, SDL_PixelFormat* pixelFormat) {
    loadImage(file,path);
    if(success){
        optimizedSurface = SDL_ConvertSurface(loadedSurface, pixelFormat, 0);
        if(optimizedSurface == nullptr){ //If we didn't optimize surface
            logger.error("Failed to optimize image. SDL Error: %s", SDL_GetError());
            optimizedSurface = loadedSurface; //Use original surface.
        }
        else{//Surface is successfully optimized. We can free original.
            SDL_FreeSurface(loadedSurface);
        }
    }
}

ImageLoader::~ImageLoader() {
    if(optimizedSurface != nullptr)
        SDL_FreeSurface(optimizedSurface);
    logger.debug("ImageLoader destroyed");
}

void ImageLoader::loadImage(std::string file, std::string path) {
    std::string fullPath = path + file;
    this->loadedSurface = IMG_Load(fullPath.c_str());
    success = true;
    if(this->loadedSurface == nullptr){
        logger.error("Failed to load image. SDL Error: %s", IMG_GetError());
        success = false;
    }
}

SDL_Surface* ImageLoader::getBitmap() {return optimizedSurface;}

bool ImageLoader::imageLoaded() {return success;}

