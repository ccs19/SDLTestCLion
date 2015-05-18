//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "core/GameLoop.h"
#include "log4cpp/PropertyConfigurator.hh"
#include <boost/any.hpp>


void testBoost(){
    boost::any a(5);
    a = 7.67;
    std::cout<<boost::any_cast<double>(a)<<std::endl;
}


int main(int argc, char* args[])
{


    testBoost();
    //Init logger
    log4cpp::PropertyConfigurator::configure(LOGGER_PROPERTIES);
    getLog("main");
    logger.debug("Do it wekred?");


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    GameLoop* loop = new GameLoop();
    loop->isLoopRunning();
    return 0;
}