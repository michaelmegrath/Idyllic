//
//  initializer.h
//  SDL tutorial
//
//  Created by Michael Megrath on 6/12/19.
//  Copyright © 2019 Michael Megrath. All rights reserved.
//
#include <iostream>
#include <SDL2/SDL.h>







class InitializeIdyllic {

    public:
        InitializeIdyllic();
        InitializeIdyllic(int width, int height, char* name);
        ~InitializeIdyllic();
        int makeWindow();
        void changeWindow(int width, int height);

        void setFps(int newFps);
        void capFps(Uint32 starting_tick);

        SDL_Window* window;
        SDL_Event windowEvent;

    private:
        static int fps;
        static int window_width;
        static int window_height;
        static char window_name[32];


};
