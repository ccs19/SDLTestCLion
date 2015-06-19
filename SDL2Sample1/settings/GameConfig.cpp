//
// Created by chris_000 on 6/19/2015.
//

#include "GameConfig.h"


namespace GameConfig{

    //getLog("GameConfig")
    static int screenWidth = 640;
    static int screenHeight = 480;

    void setScreenWidth(int width){screenWidth = width;}

    void setScreenHeight(int height){screenHeight = height;}

    int getScreenWidth(){return screenWidth;}

    int getScreenHeight(){return screenHeight;}

}