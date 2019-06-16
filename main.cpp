#include <SDL2/SDL.h>
#include "initializer.h"





int main(){
    SDL_Init(SDL_INIT_EVERYTHING); //Put in Initalizer

    InitializeIdyllic engine;
    SDL_Event windowEvent;


    Uint32 starting_tick; // Put in Initalizer
    bool running = true;
    while(running){
        starting_tick = SDL_GetTicks(); // Put in Initalizer
        if(SDL_PollEvent(&windowEvent)){ // Put in EventHandler
            if(SDL_QUIT == windowEvent.type){
                running = false;
                break;
            }
        }
        engine.capFps(starting_tick);

    }
    engine.~InitializeIdyllic();
    return 1;
}
