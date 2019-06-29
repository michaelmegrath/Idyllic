#include "initializer.h"




int main(){
    InitializeIdyllic engine;
    engine.setScreen();
    bool running = true;

    while(running){
        int event = engine.checkEvent();
        if(event == 0){

            running = false;
            break;
        }
        else if(event == -1){}
        else{}
        engine.capFps();
    }
    return 1;
}
