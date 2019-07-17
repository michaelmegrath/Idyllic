#include "population.h"

Population::Population(int size,SDL_Renderer* renderer){
  DotList.resize(size);
  this->size = size;
  this->renderer = renderer;
  goal = new Zone(400,500,10,10,1);
  goal -> display(renderer);

}

void Population::show(){
  goal -> display(renderer);
  for(int i = 0;i<size;i++){
    DotList[i].display(renderer);
  }
}

void Population::update(){
  for(int i = 0;i<size;i++){
    DotList[i].update();
    if(goal -> collision(DotList[i].obj)==1){
      DotList[i].toggleGoal();
    }
  }
}
