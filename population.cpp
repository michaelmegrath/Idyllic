#include "population.h"

Population::Population(int size,SDL_Renderer* renderer){
  this->size = size;
  this->renderer = renderer;
  goal = new Zone(400,100,10,10,1);
  goal -> display(renderer);
  //DeathZone
  DotList.resize(size);
  for(int i = 0;i<size;i++){
    DotList[i].setGoal(goal);
  }
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

  }
}


void Population::calculateFitness(){
  float highest = 0;
  for(int i = 0;i<size;i++){
    float temp = DotList[i].calculateFitness();
    if(temp>highest){
      highest = temp;
    }
    fitnessSum += temp;
  }
  std::cout << "Highest score: "<<highest << '\n';
}

bool Population::allDotsDead(){
  for(int i = 0;i<size;i++){
    if(DotList[i].active()){
      return false;
    }
  }
  return true;
}


void Population::naturalSelection(){
  std::vector <Dot> newDots;
  newDots.resize(size);
  for(int i = 0;i<size;i++){
    
  }


}


void Population::mutateChildren(){
  for(int i = 0;i<size;i++){
    DotList[i].mutate();
  }
}
