//#include "headers/MainWindow.h"

#include "utility/common.h"
#include "window/MainWindow.h"
#include "helpers/BitmapLoader.h"
#include "core/GameLoop.h"



int main(int argc, char* args[])
{
    log4cxx::PatternLayoutPtr myLayoutPtr = new log4cxx::PatternLayout("%r [%t] %-5p %c- %m%n %x");
//%x means to print context info stored in NDC
    log4cxx::ConsoleAppenderPtr myAppenderPtr = new log4cxx::ConsoleAppender(myLayoutPtr);
    log4cxx::BasicConfigurator::configure(myAppenderPtr);
    log4cxx::LoggerPtr rootLogger = log4cxx::Logger::getRootLogger();


    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    log4cxx::NDC::push(("context\n"));
    LOG4CXX_DEBUG(rootLogger,"Debug message test");
    log4cxx::NDC::pop();
//    new GameLoop();

    return 0;
}