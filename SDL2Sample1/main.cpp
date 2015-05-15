//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "window/MainWindow.h"
#include "helpers/BitmapLoader.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    MainWindow* mainWindow = new MainWindow();
    BitmapLoader* bmp = new BitmapLoader("hello_world.bmp");

    for(int i = 5; i < 10; i++){
        SDL_BlitSurface(bmp->getBitmap(), NULL, mainWindow->getSurface(), NULL);
        SDL_UpdateWindowSurface(mainWindow->getWindow());
        SDL_Delay(1000);
    }

    return 0;
}