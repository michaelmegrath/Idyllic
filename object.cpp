#include "object.h"

int Object::setWindow(SDL_Window* window){
  screen = window;
  return 1;
}
