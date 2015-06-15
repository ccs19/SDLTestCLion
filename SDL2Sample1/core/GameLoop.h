//
// Created by christopher on 5/15/15.
//

#ifndef CCS_GAMELOOP_H
#define CCS_GAMELOOP_H

#include "../utility/common.h"
#include "../window/MainWindow.h"
#include <mutex>

class MainWindow;
class GameLoop {

private:
    getLog("GameLoop")
    bool quit;


    ~GameLoop();
    void handleEvent(const SDL_Event &event);


public:
    GameLoop();


    //Setter to quit game
    void quitGame(bool quitGame);
    bool isLoopRunning();
};




#endif //SDLTESTCLION_GAMELOOP_H
