#include <SDL2/SDL.h>
#include "object.h"

class Screen {
    public:
      Screen();
      ~Screen();
      int setRender(SDL_Window* window);


    private:
      //Object objectList[];
      SDL_Renderer* renderer;
      SDL_Window* window;

};
