#include <SDL2/SDL.h>
#include "brain.h"


class Object{
  public:
    Object();
    Object(const Object& old_obj);
    ~Object();
    void display(SDL_Renderer* renderer);

  protected:
    SDL_Rect obj;

};



class Dot : public Object{
  public:
    Dot();
    Dot(const Dot& old_obj);
    ~Dot();
    void move();
    void limit(float (&velo)[2],int limit);
    void update();

  private:
    float vel[2];
    float acc[2];
    Brain* brain;
    bool dead;
};


class Zone : public Object{

};
