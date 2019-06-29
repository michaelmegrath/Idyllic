//
//  initializer.h
//  SDL tutorial
//
//  Created by Michael Megrath on 6/12/19.
//  Copyright © 2019 Michael Megrath. All rights reserved.
//
#include <SDL2/SDL.h>
#include "eventHandler.h"
#include "screen.h"





class InitializeIdyllic {

    public:
        InitializeIdyllic();
        ~InitializeIdyllic();


        int initWindow();
        void resizeWindow(int width, int height);


        void setFps(int newFps);
        void capFps();


        int checkEvent();


        void initScreen();
        void refresh();


        int createObjects();



    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        Screen screen;
        EventHandler windowEvents;
        Uint32 starting_tick;
        int fps;
        int window_width;
        int window_height;
        char window_name[32];


};
