//
//  initializer.cpp
//  SDL tutorial
//
//  Created by Michael Megrath on 6/12/19.
//  Copyright © 2019 Michael Megrath. All rights reserved.
//


#include "initializer.h"



//Constructor---------------------------------
InitializeIdyllic::InitializeIdyllic(){
    SDL_Init(SDL_INIT_EVERYTHING);
    fps = 30;
    window_width = 800;
    window_height = 600;
    strcpy(window_name, "Idyllic Instance");
    window = NULL;
    makeWindow(); //Handle return value

}//--------------------------------------------


//Destructor------------------------------------
InitializeIdyllic::~InitializeIdyllic(){
    windowEvents.~EventHandler();
    screen.~Screen();
    SDL_DestroyWindow(window);
    SDL_Quit();
}//---------------------------------------------




//Make Window-----------------------------------
int InitializeIdyllic::makeWindow(){
    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_ALLOW_HIGHDPI);
    if(window == NULL){
        std::cout<<"Could not create a window"<<std::endl<<SDL_GetError()<<std::endl;
        return 0;
    }

    return 1;
}//-----------------------------------------------


//Change Window size-------------------------------
void InitializeIdyllic::changeWindow(int width, int height){
    window_width = width;
    window_height = height;
    return;
}//------------------------------------------------






void InitializeIdyllic::setFps(int newFps){
    fps = newFps;
    return;
}

void InitializeIdyllic::capFps(){
    if( (1000/fps) > SDL_GetTicks() - starting_tick ){
        SDL_Delay(1000/fps - (SDL_GetTicks()-starting_tick));
    }
    starting_tick = SDL_GetTicks();
}



int InitializeIdyllic::checkEvent(){
    if(windowEvents.getEvent())
      return windowEvents.returnEvent();//Check Documentation for return codes
    else
      return -1;
}
