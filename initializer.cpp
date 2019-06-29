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
    fps = 30;//Make Constant
    window_width = 800;//Make constant
    window_height = 600;//Make Constant
    strcpy(window_name, "Idyllic Instance");
    window = NULL;
    makeWindow(); //Handle return value
}//--------------------------------------------


//Destructor------------------------------------
InitializeIdyllic::~InitializeIdyllic(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}//---------------------------------------------




//Make Window-----------------------------------
int InitializeIdyllic::makeWindow(){

    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
    if(window == NULL){
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

void InitializeIdyllic::setScreen(){
    screen.setRender(window);
    screen.createObjects();
}







int InitializeIdyllic::checkEvent(){
    if(windowEvents.getEvent())
      return windowEvents.returnEvent();//Check Documentation for return codes
    else
      return -1;
}
