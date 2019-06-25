#include <SDL2/SDL.h>


class Object{
  public:
    Object();
    ~Object();
    virtual void load() = 0;
    virtual void display() = 0;
  private:
    int pos_x;
    int pos_y;
};


class DrawnObject: public Object  {
  public:
    DrawnObject();
    ~DrawnObject();
}

class SpriteObject: public Object {
  public:
    SpriteObject();
    ~SpriteObject():
}
