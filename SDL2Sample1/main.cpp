//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "core/GameLoop.h"
#include "log4cpp/PropertyConfigurator.hh"
#include <thread>

int threadTest(GameLoop* loop){
    std::cout << "This is a thread";
    SDL_Delay(5000);
    loop->quitGame(true);
}

int main(int argc, char* args[])
{
    log4cpp::PropertyConfigurator::configure(LOGGER_PROPERTIES);
    getLog("main");
    logger.debug("Do it wekred?");
    GameLoop* loop;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    loop = new GameLoop();

    logger.debug("Leaving main");
    return 0;
}


