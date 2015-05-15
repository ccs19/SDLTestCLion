//
// Created by Chris on 4/26/2015.
//

#include "MainWindow.h"
#include "../utility/ResPath.h"


MainWindow::MainWindow(const char* title){
    initWindow(title);
    initRenderer();
}

MainWindow::~MainWindow(){
    //if (mainWindow != nullptr){
    //    delete mainWindow;
    //}
}

void MainWindow::initWindow(const char* title){
    mainWindow = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (nullptr == mainWindow){
        std::cout << "SDL_Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        windowInitialized = false;
    }
    else windowInitialized = true;
}

void MainWindow::initRenderer(){
    renderer = SDL_CreateRenderer(mainWindow, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (nullptr == renderer){
        windowInitialized = false;
        SDL_DestroyWindow(mainWindow);
    }
}

SDL_Window* MainWindow::getWindow() const { return this->mainWindow; }


