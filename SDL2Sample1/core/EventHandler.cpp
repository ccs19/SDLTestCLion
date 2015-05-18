//
// Created by christopher on 5/15/15.
//

//#include <mingw.thread.h>
#include <functional>
#include <mingw.thread.h>

#include "GameLoop.h"

#include "GameLoop.h"
#include "EventHandler.h"
EventHandler::EventHandler(GameLoop* loop) {
    logger.debug("Initializing EventHandler");
    gameLoop = loop;
    //std::thread t{startLoop};
}


EventHandler::~EventHandler(){}

void EventHandler::destroyHandler(){
    quit = true;
}

void EventHandler::startLoop(){
    logger.debug("EventHandler loop started");

    SDL_Event event;
    int result;
    while(SDL_PollEvent(&event) != 0){
        result = handleEvent(event);
        if(result == 1) break;
    }
    logger.debug("Exited EventHandler");
}

int EventHandler::handleEvent(SDL_Event& event){
    if(event.type == SDL_QUIT){
        gameLoop->quitGame(true);
        return 1;
    }
    else{
        return 0;
    }
}



