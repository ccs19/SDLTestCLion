//
// Created by christopher on 5/15/15.
//

#ifndef CCS_EVENT_HANDLER
#define CCS_EVENT_HANDLER

#include "../utility/common.h"
#include "GameLoop.h"



class EventHandler {
/**vars**/
private:
    getLog("EventHandler")
    bool quit;
    GameLoop* gameLoop;
    std::thread* t;

public:


    /**Methods**/
private:
    void print();

public:
    EventHandler(GameLoop* loop);
    ~EventHandler();
    void destroyHandler();
    void startLoop();
    int handleEvent(SDL_Event& event);

};



#endif //CCS_EVENT_HANDLER
