CXX = g++
CXXFLAGS = -c -Wall
LDLIBS = -l SDL2-2.0.0
OBJECTS = eventHandler.o initializer.o main.o screen.o object.o

Idyllic: $(OBJECTS)
	$(CXX)  -o Idyllic $(OBJECTS) $(LDLIBS)


main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp


eventHandler.o: eventHandler.cpp eventHandler.h
	$(CXX) $(CXXFLAGS) eventHandler.cpp


initializer.o: initializer.cpp initializer.h
	$(CXX) $(CXXFLAGS) initializer.cpp

screen.o: screen.cpp screen.h
	$(CXX) $(CXXFLAGS) screen.cpp

object.o: object.cpp object.h
	$(CXX) $(CXXFLAGS) object.cpp



clean:
	rm *.o Idyllic
