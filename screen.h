#include <SDL2/SDL.h>
#include <vector>
#include "object.h"

class Screen {
    public:
      Screen();
      ~Screen();
      int setRender(SDL_Window* window);
      void createObjects();


    private:
      std::vector <Object*> objectList;
      SDL_Renderer* renderer;
      SDL_Window* window;
      int starting_x;
      int starting_y;
      int object_width;
      int object_height;
};
