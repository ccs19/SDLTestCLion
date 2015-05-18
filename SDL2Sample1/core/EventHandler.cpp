//
// Created by christopher on 5/15/15.
//



#include "GameLoop.h"
#include "EventHandler.h"

EventHandler::EventHandler(GameLoop* loop) {
    logger.debug("Initializing EventHandler");
    gameLoop = loop;
    //t = std::thread(&EventHandler::print, *this);
    t = new std::thread(&EventHandler::startLoop, *this);
}


EventHandler::~EventHandler(){

}

void EventHandler::print(){
    logger.debug("OMG OMG OMG facepalm");
}

void EventHandler::destroyHandler(){
    t->join();
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



