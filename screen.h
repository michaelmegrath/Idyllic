#include <SDL2/SDL.h>
#include <vector>
#include "object.h"

class Screen {
    public:
      Screen();
      ~Screen();
      int setRender(SDL_Renderer* renderer);
      void drawBackground();
      void drawObjects();
      int createObjects();



    private:
      std::vector <Dot> DotList;
      SDL_Renderer* renderer;

};
