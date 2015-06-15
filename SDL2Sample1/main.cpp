//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "core/GameLoop.h"
#include "log4cpp/PropertyConfigurator.hh"
#include <thread>



int main(int argc, char* args[])
{
    log4cpp::PropertyConfigurator::configure(LOGGER_PROPERTIES);
    getLog("main");
    GameLoop* loop;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        logger.error("SDL Failed to initialize. SDL Error: %s", SDL_GetError());
        return 1;
    }
    loop = new GameLoop();

    logger.debug("Exiting main");
    return 0;
}


