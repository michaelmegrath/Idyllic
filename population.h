#include "object.h"

class Population{
  public:
    Population(int size,SDL_Renderer* renderer);
    void show();
    void update();

  private:
    std::vector <Dot> DotList;
    Zone* goal;
    int size;
    SDL_Renderer* renderer;
};
