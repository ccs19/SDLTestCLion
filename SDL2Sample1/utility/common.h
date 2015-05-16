//
// Created by christopher on 5/13/15.
//

#ifndef SDLTESTCLION_COMMON_H
#define SDLTESTCLION_COMMON_H

/**Common libs**/
#include <iostream>
#include <SDL2/SDL.h>
#include "ResPath.h"
/***************/

/**Logging libs**/
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/ndc.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>
/****************/

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

#endif //SDLTESTCLION_COMMON_H
