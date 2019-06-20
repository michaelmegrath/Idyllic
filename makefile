CXX = g++
CXXFLAGS = -c -Wall
LDLIBS = -l SDL2-2.0.0


Idyllic: eventHandler.o initializer.o main.o screen.o
	$(CXX)  -o Idyllic eventHandler.o initializer.o screen.o main.o $(LDLIBS)


main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp


eventHandler.o: eventHandler.cpp eventHandler.h
	$(CXX) $(CXXFLAGS) eventHandler.cpp


initializer.o: initializer.cpp initializer.h
	$(CXX) $(CXXFLAGS) initializer.cpp

screen.o: screen.cpp screen.h
	$(CXX) $(CXXFLAGS) screen.cpp


clean:
	rm *.o Idyllic
