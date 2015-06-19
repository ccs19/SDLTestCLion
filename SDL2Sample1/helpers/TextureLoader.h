//
// Created by chris_000 on 6/14/2015.
//

#ifndef SDLTESTCLION_TEXTURELOADER_H
#define SDLTESTCLION_TEXTURELOADER_H


#include "../utility/common.h"
#include "ImageLoader.h"
#include "../window/RenderObject.h"

class TextureLoader : public RenderObject{

private:
    getLog("TextureLoader")
    SDL_Texture *loadedTexture;
    bool success = false;
    void loadTexture(std::string file, std::string path);


public:
    TextureLoader(std::string file, std::string path);
    ~TextureLoader();
    bool textureLoaded();
    SDL_Texture* getTexture();
    void render(SDL_Renderer* renderer);
};


#endif //SDLTESTCLION_TEXTURELOADER_H
