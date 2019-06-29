#include "eventHandler.h"


EventHandler::EventHandler(){
}

EventHandler::~EventHandler(){
}


int EventHandler::getEvent(){
    if(SDL_PollEvent(&windowEvent))
      return 1;
    else
      return 0;
}

int EventHandler::returnEvent(){
    if(SDL_QUIT == windowEvent.type){
        return 0;
    }
    else
      return -1;
}
