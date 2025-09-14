CC = gcc
NAME = main

main: main.o
	$(CC) -o main main.o

main.o: $(NAME).c
	$(CC) -c -o main.o $(NAME).c

clean:
	rm main *.o