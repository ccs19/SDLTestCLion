//
// Created by christopher on 5/15/15.
//

#ifndef SDLTESTCLION_GAMELOOP_H
#define SDLTESTCLION_GAMELOOP_H

#include "../utility/common.h"
#include "../window/MainWindow.h"
#include "../helpers/BitmapLoader.h"
#include <mutex>

class GameLoop {

private:
    MainWindow* mainWindow;
    BitmapLoader* bmp;
    bool quit;
    std::mutex quitLock;


public:
    GameLoop();

    //Setter to quit game
    void quitGame(bool quitGame);
};


#endif //SDLTESTCLION_GAMELOOP_H
