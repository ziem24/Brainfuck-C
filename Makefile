CC = gcc
CFILES = interpreter.c
OBJECTS = interpreter.o

main: $(OBJECTS)
	gcc -o main $(OBJECTS)

interpreter.o: $(CFILES)
	gcc -c -o $(OBJECTS) $(CFILES)

clean:
	rm main $(OBJECTS)