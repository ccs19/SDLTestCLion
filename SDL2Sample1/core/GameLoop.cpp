//
// Created by christopher on 5/15/15.
//

#include <thread>
#include "GameLoop.h"
#include "EventHandler.h"
#include "../helpers/ImageLoader.h"


GameLoop::GameLoop(){
     logger.debug("Initializing GameLoop");
     quit = false;
     MainWindow mainWindow("Super Mega Failure");
     ImageLoader bmp("hello_world.bmp", ResPath::getBitmapPath(), mainWindow.getSurface()->format);
     SDL_Event event;

     while(!quit){
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_BlitSurface(bmp.getSurface(), NULL, mainWindow.getSurface(), NULL);
        SDL_UpdateWindowSurface(mainWindow.getWindow());

     }

     logger.debug("Exited GameLoop");
}



void GameLoop::handleEvent(const SDL_Event &event){
    switch(event.type){
        case SDL_QUIT:
            logger.debug("Exiting GameLoop");
            this->quit = true;
            return;
        default:
            return;
    }
}

GameLoop::~GameLoop(){
}

bool GameLoop::isLoopRunning(){return quit;}