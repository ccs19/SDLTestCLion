//
// Created by christopher on 5/15/15.
//

#include <thread>
#include "GameLoop.h"

using namespace log4cxx;

#include "GameLoop.h"
#include "EventHandler.h"

 GameLoop::GameLoop(){
     LOG4CXX_DEBUG(logger, "Initializing GameLoop")

     bool quit = false;
     SDL_Event e;
     mainWindow = new MainWindow();
     bmp = new BitmapLoader("hello_world.bmp");
     EventHandler* eventHandler = new EventHandler(this);

     while(!quit){
        SDL_BlitSurface(bmp->getBitmap(), NULL, mainWindow->getSurface(), NULL);
        SDL_UpdateWindowSurface(mainWindow->getWindow());
     }
     LOG4CXX_DEBUG(logger, "Exited GameLoop")
};

void GameLoop::quitGame(bool quitGame) {
    quitLock.lock();
    quit = quitGame;
    quitLock.unlock();
}

bool GameLoop::isLoopRunning(){return quit;}