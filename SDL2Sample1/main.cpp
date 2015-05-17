//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "core/GameLoop.h"


int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    GameLoop* loop = new GameLoop();
    return 0;
}