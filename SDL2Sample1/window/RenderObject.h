//
// Created by chris_000 on 6/19/2015.
//

#ifndef SDLTESTCLION_RENDEROBJECT_H
#define SDLTESTCLION_RENDEROBJECT_H


#include <SDL2/SDL_render.h>

class RenderObject {
private:

public:
     virtual void render(SDL_Renderer* renderer) =0;
};


#endif //SDLTESTCLION_RENDEROBJECT_H
