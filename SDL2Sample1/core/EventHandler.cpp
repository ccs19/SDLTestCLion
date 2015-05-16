//
// Created by christopher on 5/15/15.
//

#include <thread>
#include "GameLoop.h"

using namespace log4cxx;

#include "GameLoop.h"
#include "EventHandler.h"

EventHandler::EventHandler(GameLoop* loop) {
    LOG4CXX_DEBUG(logger, "Initializing EventHandler");
    gameLoop = loop;
    eventThread(startLoop());
}


EventHandler::~EventHandler(){}

void EventHandler::destroyHandler(){
    quit = true;
}

void EventHandler::startLoop(){
    LOG4CXX_DEBUG(logger, "EventHandler loop startec");

    SDL_Event event;
    int result;
    while(SDL_PollEvent(&event) != 0){
        result = handleEvent(event);
        if(result == 1) break;
    }
    LOG4CXX_DEBUG(logger,"Exited EventHandler");
}

int EventHandler::handleEvent(SDL_Event& event){
    if(event.type == SDL_QUIT){
        gameLoop->quitGame(true);
        return 1;
    }
    else{

    }
}



