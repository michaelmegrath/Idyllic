#include <SDL2/SDL.h>
#include <vector>
#include "population.h"

class Screen {
    public:
      Screen();
      ~Screen();
      int setRender(SDL_Renderer* renderer);
      void drawBackground();
      void drawObjects();
      int createObjects();



    private:
      Population* dotPop;
      SDL_Renderer* renderer;
      bool showStats;

};
