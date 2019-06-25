#include "initializer.h"




int main(){
    InitializeIdyllic engine;
    bool running = true;
    while(running){
        int event = engine.checkEvent();
        if(event == 0){
            //std::cout<<"Ending window"<<std::endl;
            engine.~InitializeIdyllic();
            //std::cout<<"Ended Window"<<std::endl;
            running = false;
            break;
        }
        else if(event == -1){}
        else{}
        engine.capFps();
    }
    engine.~InitializeIdyllic();
    return 1;
}
