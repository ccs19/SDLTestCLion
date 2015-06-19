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
    //TextureLoader texture("hello_world.bmp", ResPath::getBitmapPath(), mainWindow.getRenderer());
    SDL_Event event;
    int screen_x, screen_y;
    mainWindow.getResolution(&screen_x, &screen_y);

     while(!quit){
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }


         SDL_SetRenderDrawColor(WindowGlobals::getRenderer(), 0xff, 0xff, 0xff, 0xff);
         SDL_RenderClear(WindowGlobals::getRenderer());
         SDL_Rect fillRect = {screen_x/4, screen_y/4, screen_x/2, screen_y/2};
         SDL_SetRenderDrawColor(WindowGlobals::getRenderer(), 0xff, 0, 0, 0xff);
         SDL_RenderFillRect(WindowGlobals::getRenderer(), &fillRect);
         SDL_RenderPresent(WindowGlobals::getRenderer());

        /**SDL_RenderClear(mainWindow.getRenderer());
        SDL_RenderCopy(mainWindow.getRenderer(), texture.getTexture(), NULL, NULL);
        SDL_RenderPresent(mainWindow.getRenderer());**/

        /**SDL_BlitSurface(bmp.getSurface(), NULL, mainWindow.getSurface(), NULL);
        SDL_UpdateWindowSurface(mainWindow.getWindow());**/

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