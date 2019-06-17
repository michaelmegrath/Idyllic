CC = g++


Idyllic: eventHandler.o initializer.o main.o
	$(CC) eventHandler.o initializer.o main.o -o Idyllic -l SDL2-2.0.0


main.o: main.cpp
	$(CC) -c main.cpp


eventHandler.o: eventHandler.cpp eventHandler.h
	$(CC) -c eventHandler.cpp


initializer.o: initializer.cpp initializer.h
	$(CC) -c initializer.cpp


clean:
	rm *.o
