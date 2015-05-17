//
// Created by christopher on 5/15/15.
//

#include <thread>
#include "GameLoop.h"
#include "EventHandler.h"



 GameLoop::GameLoop(){
     logger.debug("Initializing GameLoop");

     bool quit = false;
     mainWindow = new MainWindow("Super Mega Failure");
     bmp = new BitmapLoader("hello_world.bmp");
     EventHandler* eventHandler = new EventHandler(this);

     while(!quit){
        SDL_BlitSurface(bmp->getBitmap(), NULL, mainWindow->getSurface(), NULL);
        SDL_UpdateWindowSurface(mainWindow->getWindow());
     }
     logger.debug("Exited GameLoop");
};

void GameLoop::quitGame(bool quitGame) {
    quitLock.lock();
    quit = quitGame;
    quitLock.unlock();
}

bool GameLoop::isLoopRunning(){return quit;}