#include <SDL2/SDL.h>
#include "brain.h"


class Object{
  public:
    Object();
    Object(const Object& old_obj);
    ~Object();
    void display(SDL_Renderer* renderer);
    SDL_Rect obj;

  protected:

};



class Dot : public Object{
  public:
    Dot();
    Dot(const Dot& old_obj);
    ~Dot();
    void move();
    void limit(float (&velo)[2],int limit);
    void update();
    void toggleGoal();

  private:
    float vel[2];
    float acc[2];
    Brain* brain;
    bool dead;
    bool reachedGoal;
};


class Zone : public Object{
  public:
    Zone(int x,int y,int w,int h,int iden);
    int collision(const SDL_Rect& dot);
    void display(SDL_Renderer* renderer);

  private:
    int identity;
};
