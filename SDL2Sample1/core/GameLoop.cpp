//
// Created by christopher on 5/15/15.
//

#include <thread>
#include "GameLoop.h"
#include "EventHandler.h"
#include "../helpers/ImageLoader.h"
#include "../helpers/TextureLoader.h"


GameLoop::GameLoop(){
     logger.debug("Initializing GameLoop");
     quit = false;
     MainWindow mainWindow("Super Mega Failure");
     SDL_Color color{0xff, 0xff, 0xff, 0xff};
     mainWindow.initRenderer(&color);
    //ImageLoader bmp("hello_world.bmp", ResPath::getBitmapPath(), mainWindow.getSurface()->format);
    TextureLoader texture("hello_world.bmp", ResPath::getBitmapPath());
    mainWindow.addRenderObject(&texture);
    SDL_Event event;
    int x = 0;

     while(!quit){
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        mainWindow.renderScreen();
         x++;
         if(x % 5 == 0){
             mainWindow.removeRenderObject(&texture);
         }
         if(x % 10 == 0){
             mainWindow.addRenderObject(&texture);
             mainWindow.removeRenderObject(nullptr);
             mainWindow.addRenderObject(nullptr);
         }
         SDL_Delay(1000);
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