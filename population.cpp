#include "population.h"

Population::Population(int size,SDL_Renderer* renderer){
  generation = 1;
  this->size = size;
  this->renderer = renderer;
  goal = new Zone(400,300,10,10,1);
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
  std::cout << "Generation: " << generation << '\n';
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
    Dot* parent;
    selectParent(parent);
    parent->makeChild(&newDots[i]);
  }
  DotList.swap(newDots);
  generation += 1;
}

void Population::selectParent(Dot* thing){
  float rand = randmm(0,fitnessSum);
  float runningSum = 0;
  for(int i = 0;i<size;i++){
    runningSum += DotList[i].calculateFitness();
    if(runningSum > rand){
      thing = &DotList[i];
      return;
    }
  }
  return;
}


void Population::mutateChildren(){
  for(int i = 0;i<size;i++){
    DotList[i].mutate();
  }
}

float Population::randmm(float min, float max)
{
     static int first = -1;
     if((first = (first<0)))
         srand(time(NULL)+getpid());
     if(min>=max){
         std::cout << "ERROR BRAIN 16" << '\n';
         return errno=EDOM, NAN;
     }
     return min + (float)rand() / ((float)RAND_MAX / (max - min));
}
