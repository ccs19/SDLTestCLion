//
// Created by chris_000 on 6/19/2015.
//

#ifndef SDLTESTCLION_CONFIG_SETTINGS_H
#define SDLTESTCLION_CONFIG_SETTINGS_H
#include "../utility/common.h"
namespace GameConfig {
        //NOTE: This class does no actual changing of screen width and height
        //It's just a central point for settings.
        void setScreenWidth(const int width);

        void setScreenHeight(const int height);

        int getScreenWidth();

        int getScreenHeight();
}


#endif //SDLTESTCLION_CONFIG_SETTINGS_H
