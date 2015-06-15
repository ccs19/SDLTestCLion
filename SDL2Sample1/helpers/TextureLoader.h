//
// Created by chris_000 on 6/14/2015.
//

#ifndef SDLTESTCLION_TEXTURELOADER_H
#define SDLTESTCLION_TEXTURELOADER_H


#include "../utility/common.h"

class TextureLoader {

private:
    getLog("TextureLoader")
    SDL_Texture *loadedTexture;
    bool success;
    void loadTexture(std::string file, std::string path);
    ~TextureLoader();

public:
    TextureLoader(std::string file, std::string path);
    bool textureLoaded();

};


#endif //SDLTESTCLION_TEXTURELOADER_H
