#include "object.h"


DrawnObject::DrawnObject(){

}

DrawnObject::~DrawnObject(){

}

DrawnObject::DrawnObject(const DrawnObject& old_obj){
  pos_x = old_obj.pos_x;
  pos_y = old_obj.pos_y;
  obj = old_obj.obj;
}


void DrawnObject::load(SDL_Renderer* renderer,
                       int x, int y, int w,int h){

  obj.x = x; obj.y = y;
  obj.w = w; obj.h = h;

}

void DrawnObject::display(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer,0,255,0,255);

  //std::cout<<obj.x<<std::endl;
  SDL_RenderFillRect(renderer,&obj);
  //SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}
