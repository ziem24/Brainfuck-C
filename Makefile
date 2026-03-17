CC = gcc
CFLAGS = -Wall -Wextra
NAME = main.c

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: $(NAME)
	$(CC) $(CFLAGS) -c -o main.o $(NAME)

clean:
	rm main *.o