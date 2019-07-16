#include "population.h"

Population::Population(int size,SDL_Renderer* renderer){
  DotList.resize(size);
  this->size = size;
  this->renderer = renderer;

}

void Population::show(){
  for(int i = 0;i<size;i++){
    DotList[i].display(renderer);
  }
}

void Population::update(){
  for(int i = 0;i<size;i++){
    DotList[i].update();
  }
}
