//
// Created by chris_000 on 6/14/2015.
//

#include "TextureLoader.h"


TextureLoader::TextureLoader(const std::string file, const std::string path, SDL_Renderer* renderer){
    success = true;
    logger.debug("Creating texture from file: %s%s", path.c_str(), file.c_str());
    ImageLoader image(file, path);
    if(image.imageLoaded()){
        loadedTexture = SDL_CreateTextureFromSurface(renderer, image.getBitmap());
        if(loadedTexture == nullptr){
            logger.error("Failed to create texture %s%s. Error: %s", path.c_str(), file.c_str(), SDL_GetError());
            success = false;
        }
    }
    else{ //We couldn't load the texture because image loading failed
        logger.error("Texture Failed to load because image file %s%s couldn't be loaded", path.c_str(), file.c_str());
        success = false;
    }
}

TextureLoader::~TextureLoader(){
    logger.debug("Destroying texture");
    SDL_DestroyTexture(loadedTexture);
}

bool TextureLoader::textureLoaded() {return success; }

SDL_Texture* TextureLoader::getTexture(){ return loadedTexture; }