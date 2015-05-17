//
// Created by Chris on 4/26/2015.
//

#include "MainWindow.h"


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
        SDL_Quit();
        windowInitialized = false;
        LOG4CXX_ERROR(logger, "Failed to initialize window" << SDL_GetError())
    }
    else windowInitialized = true;
}

void MainWindow::initRenderer(){
    mainWindowRenderer = SDL_CreateRenderer(mainWindow, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (nullptr == mainWindowRenderer){
        windowInitialized = false;
        SDL_DestroyWindow(mainWindow);
        //LOG4CXX_ERROR(logger, "Failed to initialize renderer" << SDL_GetError())
    }
}

void MainWindow::setResolution(const int width, const int height){
    if(width <= 0 || height <= 0){
        //LOG4CXX_ERROR(logger, "Unable to change resolution " << width << " " << height)
        return;
    }
    SDL_SetWindowSize(this->mainWindow, width, height);
    if(nullptr == this->mainWindow){
        windowInitialized = false;
        //LOG4CXX_ERROR(logger, "Failed to change resolution " << SDL_GetError());
    }
}

void MainWindow::getResolution(int* width, int* height) {
    SDL_GetWindowSize(this->mainWindow, width, height);
}

/**
 * 0 - Windowed
 * SDL_WINDOW_FULLSCREEN - True full screen
 * SDL_WINDOW_FULLSCREEN_DESKTOP - Full screen window
 */
void MainWindow::setFullscreen(const Uint32 flag) {
    SDL_SetWindowFullscreen(this->mainWindow, flag);
}




