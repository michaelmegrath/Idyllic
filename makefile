CXX = g++
CXXFLAGS = -Wall

Idyllic: eventHandler.o initializer.o main.o
	$(CXX)  -o Idyllic eventHandler.o initializer.o main.o -l SDL2-2.0.0


main.o: main.cpp
	$(CXX) -c main.cpp


eventHandler.o: eventHandler.cpp eventHandler.h
	$(CXX) -c eventHandler.cpp


initializer.o: initializer.cpp initializer.h
	$(CXX) -c initializer.cpp


clean:
	rm *.o
