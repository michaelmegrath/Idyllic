#include "screen.h"


Screen::Screen(){

}

Screen::~Screen(){

}

int Screen::setRender(SDL_Window* window){
  this->window = window;
  renderer = SDL_CreateRenderer(window,-1,0);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  return 1;
}
