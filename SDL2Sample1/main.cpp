//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "window/MainWindow.h"
#include "helpers/BitmapLoader.h"
#include "core/GameLoop.h"


log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("main"));

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    LOG4CXX_DEBUG(logger, "message");
//    new GameLoop();

    return 0;
}