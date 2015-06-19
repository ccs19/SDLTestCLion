//
// Created by christopher on 5/13/15.
//

#ifndef CCS_COMMON_H
#define CCS_COMMON_H

/**Common libs**/
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
/***************/

/**My classes**/
#include "ResPath.h"
#include "../settings/GameConfig.h"
/***************/

/**Logging libs**/
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
/****************/

#include <thread>

/**Log define**/
#define getLog(name) log4cpp::Category& logger = log4cpp::Category::getInstance(std::string(name));

/**keyboard enums**/
//Key press surfaces constants

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};



/*******************/

#endif //CCS_COMMON_H
