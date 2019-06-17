#include "initializer.h"




int main(){
    InitializeIdyllic engine;
    bool running = true;
    while(running){
        int event = engine.checkEvent();
        if(event == -1){}
        else if(event == 0){
            running = false;
            engine.~InitializeIdyllic();
            break;
        }
        else{}
        engine.capFps();
    }
    engine.~InitializeIdyllic();
    return 1;
}
