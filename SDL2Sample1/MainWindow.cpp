//
// Created by Chris on 4/26/2015.
//

#include "headers/MainWindow.h"
#include "ResPath.h"


MainWindow::MainWindow(){
    initWindow();
    initRenderer();
    //initVideo();
    loadBitmap();
    drawBitmap();
    drawLoop();
}

MainWindow::~MainWindow(){
    //if (mainWindow != nullptr){
    //    delete mainWindow;
    //}
}

/**
void MainWindow::initVideo(){
    int driverNumber = SDL_GetNumVideoDrivers();
    for(int i = 0; i < driverNumber; i++) {
        const char *videoDriver = SDL_GetVideoDriver(i);
        if(strcmp("windows", videoDriver)== 0){
            driverNumber = i;
        }
    }
    if(SDL_VideoInit(SDL_GetVideoDriver(driverNumber)) != 0){
        std::cout << "Failed to initialize video " << SDL_GetError();
    }

}**/


void MainWindow::initWindow(){
    mainWindow = SDL_CreateWindow("Hello world!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (nullptr == mainWindow){
        std::cout << "SDL_Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        isInitialized = false;
    }
    else isInitialized = true;
}

void MainWindow::initRenderer(){
    renderer = SDL_CreateRenderer(mainWindow, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (nullptr == renderer){
        isInitialized = false;
        SDL_DestroyWindow(mainWindow);
    }


}

void MainWindow::loadBitmap(){

    std::string imagePath = res_path::getResPath() + "hello.bmp";
    std::cout << "Image Path" << imagePath;
    bmp = SDL_LoadBMP(imagePath.c_str());
    if (nullptr == bmp){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(mainWindow);
        std::cout << "Error loading bitmap " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

void MainWindow::drawBitmap(){
    texture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (texture == nullptr){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(mainWindow);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}


void MainWindow::drawLoop(){
    //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    for (int i = 0; i < 3; ++i){
        //First clear the renderer
        SDL_RenderClear(renderer);
        //Draw the texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        //Update the screen
        SDL_RenderPresent(renderer);
        //Take a quick break after all that hard work
        SDL_Delay(1000);
    }
}

