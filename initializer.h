//
//  initializer.h
//  SDL tutorial
//
//  Created by Michael Megrath on 6/12/19.
//  Copyright © 2019 Michael Megrath. All rights reserved.
//
#include <iostream>
#include <SDL2/SDL.h>

#ifndef initializer_h
#define initializer_h


#endif /* initializer_h */




class InitializeIdyllic {

    public:
        InitializeIdyllic();
        InitializeIdyllic(int width, int height, char* name);
        ~InitializeIdyllic();
        int makeWindow();
        void changeWindow(int width, int height);
    
        void setFps(int newFps);
        void capFps(Uint32 starting_tick);
    
        SDL_Window* window = NULL;
        SDL_Event windowEvent;

    private:
        int fps = 30;
        int window_width = 800;
        int window_height = 600;
        char window_name[32] = "Idyllic Instance";

};


