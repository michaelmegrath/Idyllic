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


        int makeWindow();
        void changeWindow(int width, int height);


        void setFps(int newFps);
        void capFps();


        int checkEvent();


        void setScreen();
        int updateScreen();
        int drawObject();
        int createObject();


        SDL_Window* window;

    private:
        Screen screen;
        EventHandler windowEvents;
        Uint32 starting_tick;
        int fps;
        int window_width;
        int window_height;
        char window_name[32];


};
