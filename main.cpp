#include "initializer.h"




int main(){
    InitializeIdyllic engine;
    bool running = true;

    while(running){
        int event = engine.checkEvent();
        if(event == 0){

            running = false;
            break;
        }
        else if(event == -1){}
        else{}
        engine.refresh();
        engine.capFps();
    }
    return 1;
}
