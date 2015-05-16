//
// Created by Chris on 4/26/2015.
//

#ifndef CCS_MAINWINDOW_H
#define CCS_MAINWINDOW_H

#include "../utility/common.h"

class MainWindow{

//Vars
private:
    getLog("MainWindow")
    SDL_Window *mainWindow;
    SDL_Renderer *mainWindowRenderer;
    SDL_Surface *mainWindowSurface;
    bool windowInitialized;


//Methods
private:
    void initWindow(const char* title);
    void initRenderer();

public:
    MainWindow(const char* title = "Window");
    ~MainWindow();



    SDL_Window* getWindow()  { return this->mainWindow;}
    SDL_Renderer* getRenderer()  {return this->mainWindowRenderer;}
    SDL_Surface* getSurface() {return this->mainWindowSurface;};
    bool isInitialized() const {return this->windowInitialized;}

    //Resolution
    void getResolution(int* w, int* h);
    void setResolution(const int w, const int h);
    void setFullscreen(const Uint32 flag);

};
#endif //SDLTESTCLION_MAINWINDOW_H
