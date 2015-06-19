//
// Created by Chris on 4/26/2015.
//

#include "MainWindow.h"

getLog("MainWindow")
MainWindow::MainWindow(const char* title){
    initWindow(title);
    this->mainWindowRenderer = nullptr;
    mainWindowSurface = SDL_GetWindowSurface(mainWindow);
}

MainWindow::~MainWindow(){
    SDL_DestroyWindow(mainWindow);
    if(mainWindowRenderer != nullptr)SDL_DestroyRenderer(mainWindowRenderer);
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
    mainWindow = SDL_CreateWindow(title, 100, 100, GameConfig::getScreenWidth(),
            GameConfig::getScreenHeight(), SDL_WINDOW_SHOWN);
    if (nullptr == this->mainWindow){
        SDL_Quit();
        this->windowInitialized = false;
        logger.error("Failed to initialize window. SDL Error: %s", SDL_GetError());
    }
    else this->windowInitialized = true;
}

/**
 * Initialize renderer with a specific color
 */
void MainWindow::initRenderer(SDL_Color* color){
    logger.debug("Initializing MainWindow Renderer");
    mainWindowRenderer = SDL_CreateRenderer(this->mainWindow, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (nullptr == mainWindowRenderer){
        this->windowInitialized = false;
        SDL_DestroyWindow(mainWindow);
        logger.error("Failed to initialize renderer. SDL Error: %s", SDL_GetError());
    }
    else{//Else we've successfully created the renderer
        //Draw color
        //Renderer, R, G, B, A
        SDL_SetRenderDrawColor(this->mainWindowRenderer, color->r, color->g, color->b, color->a);
        WindowGlobals::setRenderer(mainWindowRenderer);
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
 * Note: This function accepts pointers, but memory must already be allocated.
 */
void MainWindow::getResolution(int* width, int* height) {
    logger.debug("Getting window size");
    SDL_GetWindowSize(this->mainWindow, width, height);
    logger.debug("Returning window size %dx%d", *width, *height);
}


/**
 * 0 - Windowed
 * SDL_WINDOW_FULLSCREEN - True full screen
 * SDL_WINDOW_FULLSCREEN_DESKTOP - Full screen window
 */
void MainWindow::setFullscreen(const Uint32 flag) { SDL_SetWindowFullscreen(this->mainWindow, flag);}

SDL_Window* MainWindow::getWindow(){return mainWindow;}

bool MainWindow::isInitialized(){return windowInitialized;}

SDL_Surface* MainWindow::getSurface(){return mainWindowSurface;}


/**
 * Main window globals. Things we may need all over the program, e.g. the Renderer is used
 * to initialize several SDL objects including SDL_Textures.
 */
namespace WindowGlobals{
    SDL_Renderer* mainWindowRenderer;

    SDL_Renderer* getRenderer(){return mainWindowRenderer;}
    void setRenderer(SDL_Renderer* renderer){mainWindowRenderer = renderer;}
}




