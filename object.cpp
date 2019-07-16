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

//------------------------------------------------------------------


Dot::Dot(){
  obj.x = 400; obj.y = 50;
  obj.w = 5; obj.h = 5;
  vel[0] = 0; vel[1] = 0;
  acc[0] = 0; acc[1] = 0;
  brain = new Brain(400);
  dead = false;
}

Dot::~Dot(){

}

Dot::Dot(const Dot& old_obj){

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
  if(!dead){
    move();
    if(obj.x<2 || obj.y<2 || obj.x>798 || obj.y>598){ //Update with constants
      dead = true;
    }
  }
}
