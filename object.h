#include <SDL2/SDL.h>
#include <iostream>

class Object{
  public:
    virtual void load(SDL_Renderer* renderer,
                      int x, int y, int w, int h) = 0;
    virtual void display(SDL_Renderer* renderer) = 0;
  protected:
    int pos_x;
    int pos_y;
};


class DrawnObject: public Object  { // Create Copy constructor
  public:
    DrawnObject();
    DrawnObject(const DrawnObject& old_obj);
    ~DrawnObject();
    void load(SDL_Renderer* renderer,
              int x, int y, int w, int h);
    void display(SDL_Renderer* renderer);
  private:
    SDL_Rect obj;
};

class SpriteObject: public Object {
  public:
    SpriteObject();
    ~SpriteObject();
};
