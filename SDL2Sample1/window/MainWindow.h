//
// Created by Chris on 4/26/2015.
//

#ifndef SDLTESTCLION_MAINWINDOW_H
#define SDLTESTCLION_MAINWINDOW_H

#include "../utility/common.h"

class MainWindow{
    //Vars
private:
    SDL_Window *mainWindow;
    SDL_Renderer *renderer;
    SDL_Surface *bmp;
    SDL_Texture *texture;
    bool isInitialized;

    //Methods

private:
    void initWindow();
    void initRenderer();
    void loadBitmap();
    void drawBitmap();
    void drawLoop();
    void initVideo();

public:
    MainWindow();
    ~MainWindow();



};


#endif //SDLTESTCLION_MAINWINDOW_H
