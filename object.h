#include <SDL2/SDL.h>


class Object{
  public:
    int setWindow(SDL_Window* window);
    virtual void load() = 0;
    virtual void display() = 0;
  private:
    int pos_x;
    int pos_y;
    SDL_Window* screen;

};


class DrawnObject: public Object  {
  public:
    DrawnObject();
    ~DrawnObject();
    void load();
    void display();
  private:
    int width;
    int height;
};

class SpriteObject: public Object {
  public:
    SpriteObject();
    ~SpriteObject();
};
