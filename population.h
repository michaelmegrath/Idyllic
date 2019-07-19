#include "object.h"

class Population{
  public:
    Population(int size,SDL_Renderer* renderer);
    void show();
    void update();
    void calculateFitness();
    bool allDotsDead();
    void naturalSelection();
    void mutateChildren();

  private:
    std::vector <Dot> DotList;
    Zone* goal;
    int size;
    SDL_Renderer* renderer;
    float fitnessSum;
};
