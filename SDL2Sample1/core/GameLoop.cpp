//
// Created by christopher on 5/15/15.
//

#include "GameLoop.h"


 GameLoop::GameLoop(){
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
}

void GameLoop::quitGame(bool quitGame) {
    quit = quitGame;
}