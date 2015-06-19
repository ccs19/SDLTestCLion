//
// Created by chris_000 on 6/19/2015.
//

#include "Dot.h"


Dot::Dot(){
    logger.debug("Creating Dot");
    mPosX = mPosY = mVelX = mVelY = 0; //Init speed and screen offsets
    dot = new TextureLoader("dot.bmp", ResPath::getBitmapPath());
}

Dot::~Dot(){

}

void Dot::handleEvent(SDL_Event &e){
    //if key pressed down
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case direction::up:
                mVelY -= DOT_VEL;
                break;
            case direction::down:
                mVelY += DOT_VEL;
                break;
            case direction::left:
                mVelX -= DOT_VEL;
                break;
            case direction::right:
                mVelX += DOT_VEL;
                break;
        }
    }
    else if(e.type == SDL_KEYUP && e.key.repeat == 0){
        switch( e.key.keysym.sym )
        {
            case direction::up:
                mVelY += DOT_VEL;
                break;
            case direction::down:
                mVelY -= DOT_VEL;
                break;
            case direction::left:
                mVelX += DOT_VEL;
                break;
            case direction::right:
                mVelX -= DOT_VEL;
                break;
        }
    }
}

//void Dot::render() {
  //  dot.getTexture();
//}

void Dot::move() {
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > GameConfig::getScreenWidth() ) )
    {
        //Move back
        mPosX -= mVelX;
    }
    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > GameConfig::getScreenHeight() ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}
