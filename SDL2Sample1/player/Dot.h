//
// Created by chris_000 on 6/19/2015.
//

#ifndef SDLTESTCLION_DOT_H
#define SDLTESTCLION_DOT_H

#include "../utility/common.h"
#include "../helpers/TextureLoader.h"
#include "../window/RenderObject.h"

class Dot : public RenderObject {
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    //Initializes the variables
    Dot();
    ~Dot();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //Moves the dot
    void move();


private:
    //Logger
    getLog("Dot");

    TextureLoader* dot;
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;

    //Control constants
    enum direction{
        up = SDLK_w,
        down = SDLK_s,
        left = SDLK_a,
        right = SDLK_d
    };

};


#endif //SDLTESTCLION_DOT_H
