//
// Created by christopher on 5/14/15.
//

#ifndef SDLTESTCLION_IMAGELOADER_H
#define SDLTESTCLION_IMAGELOADER_H
#include "../utility/common.h"
class ImageLoader{
private:
    getLog("ImageLoader")
    SDL_Surface *loadedSurface;
    SDL_Surface *optimizedSurface;
    bool success;

    void loadImage(std::string file, std::string path);

public:
    /**
     * Object encapsulating an SDL bitmap.
     * @param file Bitmap file name
     * @param path Path to bitmap
     */
    ImageLoader(std::string file,  std::string path, SDL_PixelFormat* pixelFormat);
    ImageLoader(std::string file, std::string path);
    ~ImageLoader();
    SDL_Surface* getSurface();
    bool imageLoaded();

};

#endif //SDLTESTCLION_BITMAP_H
