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
    bool isInitialized;

    //Methods

private:
    void initWindow(const char* title);
    void initRenderer();
    void drawLoop();

public:
    MainWindow(const char* title = "Window");
    ~MainWindow();
    SDL_Window* getWindow();



};


#endif //SDLTESTCLION_MAINWINDOW_H
