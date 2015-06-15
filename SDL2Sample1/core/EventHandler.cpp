//
// Created by christopher on 5/15/15.
//



#include "GameLoop.h"
#include "EventHandler.h"

EventHandler::EventHandler(GameLoop* loop) {
    logger.debug("Initializing EventHandler");
    gameLoop = loop;
    //t = std::thread(&EventHandler::print, *this);
   // t = new std::thread(&EventHandler::startLoop, *this);
}


EventHandler::~EventHandler(){

}

void EventHandler::print(){
    logger.debug("OMG OMG OMG facepalm");
}

void EventHandler::destroyHandler(){
    t->join();
}





