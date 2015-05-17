//
// Created by christopher on 5/13/15.
//

#ifndef CCS_COMMON_H
#define CCS_COMMON_H

/**Common libs**/
#include <iostream>
#include <SDL2/SDL.h>
#include "ResPath.h"
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

/**Log define**/
//#define getLog(name) log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(name);

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
