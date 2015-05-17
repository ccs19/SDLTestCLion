//
// Created by christopher on 5/15/15.
//

#ifndef CCS_GAMELOOP_H
#define CCS_GAMELOOP_H

#include "../utility/common.h"
#include "../window/MainWindow.h"
#include "../helpers/BitmapLoader.h"
#include <mutex>

class MainWindow;
class GameLoop {

private:
    getLog("GameLoop")
    MainWindow* mainWindow;
    BitmapLoader* bmp;
    bool quit;
    std::mutex quitLock;

public:
    GameLoop();

    //Setter to quit game
    void quitGame(bool quitGame);
    bool isLoopRunning();
};




#endif //SDLTESTCLION_GAMELOOP_H
