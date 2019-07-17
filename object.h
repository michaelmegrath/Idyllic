#include <SDL2/SDL.h>
#include "brain.h"

class Zone;

class Object{
  public:
    Object();
    Object(const Object& old_obj);
    ~Object();
    void display(SDL_Renderer* renderer);
    int distance(Object* other_obj);

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
    void setGoal(Zone* mainGoal);
    float calculateFitness();
    bool active();

  private:
    float vel[2];
    float acc[2];
    Brain* brain;
    bool dead;
    bool reachedGoal;
    Zone* goal;
    Zone* deathBlocks;
    float fitness;
};


class Zone : public Object{
  public:
    Zone(int x,int y,int w,int h,int iden);
    int collision(const SDL_Rect& dot);
    void display(SDL_Renderer* renderer);

  private:
    int identity;
};
