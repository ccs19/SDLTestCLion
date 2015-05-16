//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "window/MainWindow.h"
#include "helpers/BitmapLoader.h"
#include "core/GameLoop.h"


using namespace log4cxx;

int main(int argc, char* args[])
{
    PatternLayoutPtr myLayoutPtr = new PatternLayout("%r [%t] %-5p %c - %m%n");
    ConsoleAppenderPtr myAppenderPtr = new ConsoleAppender(myLayoutPtr);
    BasicConfigurator::configure(myAppenderPtr);
    LoggerPtr logger = Logger::getLogger("main");


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    LOG4CXX_DEBUG(logger,"Debug message test");
    GameLoop* loop = new GameLoop();
    delete(loop);
    return 0;
}