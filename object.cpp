#include "object.h"

//OBJECT CLASS----------------------------------------------------

//Constructor------------------------------
Object::Object(){

}//----------------------------------------

//Destructor-------------------------------
Object::~Object(){

}//----------------------------------------

//Copy Constructor-------------------------
Object::Object(const Object& old_obj){
  obj = old_obj.obj;

}//----------------------------------------

//Display Object---------------------------
void Object::display(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer,0,255,0,255);
  SDL_RenderFillRect(renderer,&obj);
}//----------------------------------------

int Object::distance(Object* other_obj){
  int x_distance = abs(obj.x - other_obj->obj.x);
  int y_distance = abs(obj.y - other_obj->obj.y);
  return sqrt((x_distance*x_distance)+(y_distance*y_distance));
}



//------------------------------------------------------------------


Dot::Dot(){
  obj.x = 400; obj.y = 50;
  obj.w = 5; obj.h = 5;
  vel[0] = 0; vel[1] = 0;
  acc[0] = 0; acc[1] = 0;
  brain = new Brain(400);
  dead = false;
  reachedGoal = false;
  fitness = 0;
}

Dot::~Dot(){

}

Dot::Dot(const Dot& old_obj){
  obj = old_obj.obj;
  vel[0] = 0; vel[1] = 0;
  acc[0] = 0; acc[1] = 0;
  brain = old_obj.brain; ///THIS MAY COLLAPSE THE MATRIX
  dead = false;
  reachedGoal = false;
  goal = old_obj.goal;
  deathBlocks = old_obj.deathBlocks;
  fitness = 0;
  return;
}

Dot& Dot::operator=(const Dot &copy){
  obj = copy.obj;
  vel[0] = 0; vel[1] = 0;
  acc[0] = 0; acc[1] = 0;
  brain = copy.brain; ///THIS MAY COLLAPSE THE MATRIX
  dead = false;
  reachedGoal = false;
  goal = copy.goal;
  deathBlocks = copy.deathBlocks;
  fitness = 0;
  return *this;
}

void Dot::limit(float (&velo)[2],int limit){
  float sqr_mag = (velo[0] * velo[0]) + (velo[1] * velo[1]);
  if(sqr_mag>(limit*limit)){
    if(sqr_mag!=0 && sqr_mag!=1){
      velo[0] = velo[0]/sqr_mag;
      velo[1] = velo[1]/sqr_mag;
      velo[0] = velo[0]*limit;
      velo[1] = velo[1]*limit;
    }
  }
}

void Dot::move(){
  if(brain->step < 400){
    acc[0] = brain->directions[brain->step][0];
    acc[1] = brain->directions[brain->step][1];
    brain->step++;
  }
  else{
    dead = true;
  }
  vel[0] += acc[0]; vel[1] += acc[1];
  limit(vel,5);
  obj.x += vel[0]; obj.y += vel[1];
}


void Dot::update(){
  if(!dead && !reachedGoal){
    move();
    if(obj.x<2 || obj.y<2 || obj.x>798 || obj.y>598){ //Update with constants
      dead = true;
    }
    else if(goal->collision(obj)==1){
      reachedGoal = true;
    }
  }
}


void Dot::setGoal(Zone* mainGoal){
  goal = mainGoal;
}

float Dot::calculateFitness(){
  if(reachedGoal){
    fitness = 10000/(brain->step * brain->step);
  }
  else{
    float distance = this->distance(goal);
    fitness = 1 / (distance * distance);
  }
  return fitness;
}


bool Dot::active(){
  if(dead || reachedGoal){
    return false;
  }
  else{
    return true;
  }
}

void Dot::mutate(){
  brain->mutate();
}

void Dot::makeChild(Dot* child){
  child = new Dot();
  child->brain = brain;
}


///------------------------------------------

Zone::Zone(int x,int y,int w, int h,int iden){
  obj.x = x; obj.y = y;
  obj.w = w; obj.h = h;
  identity = iden;
}

int Zone::collision(const SDL_Rect& dot){
  if(SDL_HasIntersection(&dot,&obj)){
    return identity;
  }
  return 0;
}
void Zone::display(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer,255,255,0,255);
  SDL_RenderFillRect(renderer,&obj);
}
