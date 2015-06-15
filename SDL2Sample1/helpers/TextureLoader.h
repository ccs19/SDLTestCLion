//
// Created by chris_000 on 6/14/2015.
//

#ifndef SDLTESTCLION_TEXTURELOADER_H
#define SDLTESTCLION_TEXTURELOADER_H


#include "../utility/common.h"
#include "ImageLoader.h"

class TextureLoader {

private:
    getLog("TextureLoader")
    SDL_Texture *loadedTexture;
    bool success = true;
    void loadTexture(std::string file, std::string path);
    ~TextureLoader();

public:
    TextureLoader(std::string file, std::string path, SDL_Renderer* renderer);
    bool textureLoaded();
    SDL_Texture* getTexture();
};


#endif //SDLTESTCLION_TEXTURELOADER_H
