//
//  initializer.cpp
//  SDL tutorial
//
//  Created by Michael Megrath on 6/12/19.
//  Copyright © 2019 Michael Megrath. All rights reserved.
//

#include <stdio.h>
#include "initializer.h"
using namespace std;

InitializeIdyllic::InitializeIdyllic(){
    makeWindow(); //Handle return value
}


InitializeIdyllic::InitializeIdyllic(int width,int height, char* name){
    changeWindow(width, height);
    strcpy(window_name, name);
    InitializeIdyllic();
}


InitializeIdyllic::~InitializeIdyllic(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int InitializeIdyllic::makeWindow(){
    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_ALLOW_HIGHDPI);
    if(window == NULL){
        cout<<"Could not create a window"<<endl<<SDL_GetError()<<endl;
        return 0;
    }
    
    return 1;
}

void InitializeIdyllic::changeWindow(int width, int height){
    window_width = width;
    window_height = height;
    return;
}

void InitializeIdyllic::setFps(int newFps){
    fps = newFps;
    return;
}

void InitializeIdyllic::capFps(Uint32 starting_tick){
    if( (1000/fps) > SDL_GetTicks() - starting_tick ){
        SDL_Delay(1000/fps - (SDL_GetTicks()-starting_tick));
    }
}



