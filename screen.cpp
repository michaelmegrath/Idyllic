
#include "screen.h"


Screen::Screen(){

}

Screen::~Screen(){

}

int Screen::setRender(SDL_Renderer* renderer){
  this->renderer = renderer;
  return 1;
}

void Screen::drawBackground(){
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

int Screen::createObjects(){
  int size = 50;
  DotList.resize(size);
  return size;
}



void Screen::drawObjects(){
  for(int i = 0;i<DotList.size();i++){
    DotList[i].update();
    DotList[i].display(renderer);
  }
}
