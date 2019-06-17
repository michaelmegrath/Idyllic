CXX = g++
CXXFLAGS = -c -Wall
LDLIBS = -l SDL2-2.0.0


Idyllic: eventHandler.o initializer.o main.o
	$(CXX)  -o Idyllic eventHandler.o initializer.o main.o $(LDLIBS)


main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp


eventHandler.o: eventHandler.cpp eventHandler.h
	$(CXX) $(CXXFLAGS) eventHandler.cpp


initializer.o: initializer.cpp initializer.h
	$(CXX) $(CXXFLAGS) initializer.cpp


clean:
	rm *.o Idyllic
