//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "window/MainWindow.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    MainWindow *mainWindow = new MainWindow();
    return 0;
}