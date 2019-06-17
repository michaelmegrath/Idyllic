#include <iostream>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>



class EventHandler {

  public:
    EventHandler();
    ~EventHandler();

    int getEvent();
    int returnEvent();
  private:
    SDL_Event windowEvent;
};
