#include "brain.h"
Brain::Brain(int size){
  step = 0;
  directions = new double* [size];
  for(int i = 0; i<size;i++){
    directions[i] = new double[2];
  }
  randomize();
}

float Brain::randmm(float min, float max)
{
     static int first = -1;
     if((first = (first<0)))
         srand(time(NULL)+getpid());
     if(min>=max){
         std::cout << "ERROR BRAIN 16" << '\n';
         return errno=EDOM, NAN;
     }
     return min + (float)rand() / ((float)RAND_MAX / (max - min));
}

void Brain::randomize(){
  for(int i = 0;i<sizeof(directions);i++){
    double angle = randmm(0.0,(2*PI));
    if(!angle)
      angle = randmm(0.0,(2*PI));
    directions[i][0] = cos(angle);
    directions[i][1] = sin(angle);
  }



}
