CC = gcc
CFLAGS = -Wall -Wextra

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

clean:
	rm main *.o