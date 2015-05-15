//
// Created by Chris on 4/26/2015.
//

#include "MainWindow.h"
#include "../utility/ResPath.h"


MainWindow::MainWindow(const char* title){
    initWindow(title);
    initRenderer();
    //Must call GetWindowSurface AFTER renderer is initialized.
    mainWindowSurface = SDL_GetWindowSurface(mainWindow);
}

MainWindow::~MainWindow(){
    SDL_DestroyWindow(mainWindow);
    SDL_DestroyRenderer(mainWindowRenderer);
    SDL_FreeSurface(mainWindowSurface);
    mainWindow = nullptr;
    mainWindowRenderer = nullptr;
    mainWindowSurface = nullptr;
    windowInitialized = false;
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
    mainWindowRenderer = SDL_CreateRenderer(mainWindow, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (nullptr == mainWindowRenderer){
        windowInitialized = false;
        SDL_DestroyWindow(mainWindow);
    }
}

void MainWindow::setResolution(const int width, const int height){
    if(width <= 0 || height <= 0){
        std::cout << "Width or height not valid when setting MainWindow resolution" << std::endl;
        return;
    }
    SDL_SetWindowSize(this->mainWindow, width, height);
    if(nullptr == this->mainWindow){
        windowInitialized = false;
        std::cout << "Something bad happened. Failed to set resolution " << SDL_GetError() << std::endl;
    }
}

void MainWindow::getResolution(int* width, int* height) {
    SDL_GetWindowSize(this->mainWindow, width, height);
}

void MainWindow::setFullscreen(bool isFullscreen) {

}




