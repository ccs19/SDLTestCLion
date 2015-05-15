//
// Created by Chris on 4/26/2015.
//

#include "MainWindow.h"
#include "../utility/ResPath.h"


MainWindow::MainWindow(char* title){
    initWindow(title);
    initRenderer();
    //initVideo();
    drawLoop();
}

MainWindow::~MainWindow(){
    //if (mainWindow != nullptr){
    //    delete mainWindow;
    //}
}

void MainWindow::initWindow(char* title){
    mainWindow = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
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


void MainWindow::drawLoop(){
    //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    while(true){
        //Get window surface
        auto screenSurface = SDL_GetWindowSurface( this->mainWindow );

        //Fill the surface white
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

        //Update the surface
        SDL_UpdateWindowSurface( this->mainWindow );
        SDL_Delay(5000);
    }
}

