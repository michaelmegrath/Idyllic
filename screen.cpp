
#include "screen.h"


Screen::Screen(){

}

Screen::~Screen(){

}

int Screen::setRender(SDL_Renderer* renderer){
  this->renderer = renderer;
  std::cout << renderer << '\n';
  return 1;
}

void Screen::drawBackground(){
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

int Screen::createObjects(){
  int size = 50;
  dotPop = new Population(size,renderer);
  return size;
}



void Screen::drawObjects(){
  dotPop->show();
  dotPop->update();
}
