//
// Created by christopher on 5/15/15.
//

#ifndef SDLTESTCLION_GAMELOOP_H
#define SDLTESTCLION_GAMELOOP_H

#include "../utility/common.h"
#include "../window/MainWindow.h"
#include "../helpers/BitmapLoader.h"


class GameLoop {

private:
    MainWindow* mainWindow;
    BitmapLoader* bmp;
    bool quit;


public:
    GameLoop();
    void quitGame(bool quitGame);

};


#endif //SDLTESTCLION_GAMELOOP_H
