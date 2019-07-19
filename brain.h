#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <unistd.h>

#define PI 3.14159265358979323846

class Brain{
  public:
    Brain(int size);
    Brain();
    Brain(const Brain& clone);
    ~Brain();
    void randomize();
    float randmm(float min, float max);
    void mutate();


    double** directions;
    int step;
    int size;

  private:
};
