
#include "screen.h"


Screen::Screen(){
  starting_x = 400;//Fill in with constant and logic
  starting_y = 50;//Fill in with constant and logic
  object_width = 5;
  object_height = 5;
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

void Screen::createObjects(){
  objectList.resize(30);
  objectList[objectList.size()-1].load(renderer,
                                       starting_x, starting_y,
                                       object_width, object_height);

  objectList[objectList.size()-1].display(renderer);
}
