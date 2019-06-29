#include <SDL2/SDL.h>
#include <iostream>

class Object{
  public:
    Object();
    Object(const Object& old_obj);
    ~Object();
    void load(SDL_Renderer* renderer,
                      int x, int y, int w, int h);
    void display(SDL_Renderer* renderer);

  protected:
    int pos_x;
    int pos_y;
    SDL_Rect obj;

};
