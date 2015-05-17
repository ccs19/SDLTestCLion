//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "core/GameLoop.h"
#include "log4cpp/PropertyConfigurator.hh"

int main(int argc, char* args[])
{
    //Init logger
    int i = 0;
    log4cpp::PropertyConfigurator::configure(LOGGER_PROPERTIES);
    getLog("main");
    logger.debug("Do it wekred?");


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    GameLoop* loop = new GameLoop();
    return 0;
}