#include "brain.h"
Brain::Brain(int size){
  step = 0;
  this->size = size;
  directions = new double* [size];
  for(int i = 0; i<size;i++){
    directions[i] = new double[2];
  }
  randomize();

}

Brain& Brain::operator=(const Brain &copy){
  step = 0;
  size = copy.size;
  directions = new double* [size];
  for(int i = 0; i<size;i++){
    directions[i] = new double[2];
    directions[i][0] = copy.directions[i][0];
    directions[i][1] = copy.directions[i][1];
  }
  return *this;
}

Brain::Brain(const Brain& clone){
  step = 0;
  size = clone.size;
  directions = new double* [size];
  for(int i = 0; i<size;i++){
    directions[i] = new double[2];
    directions[i][0] = clone.directions[i][0];
    directions[i][1] = clone.directions[i][1];
  }
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
  for(int i = 0;i<size;i++){//Convert to const
    double angle = randmm(0.0,(2*PI));
    if(!angle)
      angle = randmm(0.0,(2*PI));
    directions[i][0] = cos(angle);
    directions[i][1] = sin(angle);
  }
}



void Brain::mutate(){
  float mutationRate = .01;
  for(int i = 0; i<size;i++){
    float rand = randmm(0.0,1.0);
    if(mutationRate > rand){
      float randomAngle = randmm(0.0,2*PI);
      directions[i][0] = cos(randomAngle);
      directions[i][1] = sin(randomAngle);
    }
  }
}
