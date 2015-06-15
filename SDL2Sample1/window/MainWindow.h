//
// Created by Chris on 4/26/2015.
//

#ifndef CCS_MAINWINDOW_H
#define CCS_MAINWINDOW_H

#include "../utility/common.h"
#include "../core/GameLoop.h"


class GameLoop;
class MainWindow{

//Vars
private:
    SDL_Window *mainWindow;
    SDL_Renderer *mainWindowRenderer;
    SDL_Surface *mainWindowSurface;
    bool windowInitialized;

    void initWindow(const char* title);


public:
    MainWindow(const char* title);
    ~MainWindow();

    void initRenderer(SDL_Color* color);
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    SDL_Surface* getSurface();
    bool isInitialized();

    //Resolution
    void getResolution(int* w, int* h);
    void setResolution(const int w, const int h);
    void setFullscreen(const Uint32 flag);

};
#endif //SDLTESTCLION_MAINWINDOW_H
