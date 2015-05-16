//
// Created by christopher on 5/15/15.
//


#include "GameLoop.h"

using namespace log4cxx;

 GameLoop::GameLoop(){
     LOG4CXX_DEBUG(logger, "Entering GameLoop")


     bool quit = false;
     SDL_Event e;
     mainWindow = new MainWindow();
     bmp = new BitmapLoader("hello_world.bmp");

     while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_BlitSurface(bmp->getBitmap(), NULL, mainWindow->getSurface(), NULL);
        SDL_UpdateWindowSurface(mainWindow->getWindow());
     }


     LOG4CXX_DEBUG(logger, "Exited GameLoop")
}

void inline GameLoop::quitGame(bool quitGame) {
    quitLock.lock();
    quit = quitGame;
    quitLock.unlock();
}