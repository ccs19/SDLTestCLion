//
// Created by Chris on 4/26/2015.
//

#include "MainWindow.h"

getLog("MainWindow")
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
    IMG_Quit();
    SDL_Quit();
    mainWindow = nullptr;
    mainWindowRenderer = nullptr;
    mainWindowSurface = nullptr;
    windowInitialized = false;
    logger.debug("MainWindow destroyed");
}

void MainWindow::initWindow(const char* title){
    logger.debug("Initializing MainWindow");
    mainWindow = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (nullptr == this->mainWindow){
        SDL_Quit();
        this->windowInitialized = false;
        logger.error("Failed to initialize window. SDL Error: %s", SDL_GetError());
    }
    else this->windowInitialized = true;
}

void MainWindow::initRenderer(){
    logger.debug("Initializing MainWindow Renderer");
    mainWindowRenderer = SDL_CreateRenderer(this->mainWindow, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (nullptr == mainWindowRenderer){
        this->windowInitialized = false;
        SDL_DestroyWindow(mainWindow);
        logger.error("Failed to initialize renderer. SDL Error: %s", SDL_GetError());
    }
}

void MainWindow::setResolution(const int width, const int height){
    logger.debug("Changing resolution");
    if(width <= 0 || height <= 0){
        logger.error("Unable to change resolution %dx%d. Error: Invalid values" ,width ,height);
        return;
    }
    SDL_SetWindowSize(this->mainWindow, width, height);
    if(nullptr == this->mainWindow){
        windowInitialized = false;
        logger.error("Failed to change resolution to %dx%d. SDL Error: %s", width, height, SDL_GetError());
    }
}

/**
 * Puts current resolution in int pointers.
 */
void MainWindow::getResolution(int* width, int* height) {
    SDL_GetWindowSize(this->mainWindow, width, height);
}


/**
 * 0 - Windowed
 * SDL_WINDOW_FULLSCREEN - True full screen
 * SDL_WINDOW_FULLSCREEN_DESKTOP - Full screen window
 */
void MainWindow::setFullscreen(const Uint32 flag) { SDL_SetWindowFullscreen(this->mainWindow, flag);
}

SDL_Renderer* MainWindow::getRenderer(){return mainWindowRenderer;}

SDL_Window* MainWindow::getWindow(){return mainWindow;}

bool MainWindow::isInitialized(){return windowInitialized;}

SDL_Surface* MainWindow::getSurface(){return mainWindowSurface;}




