CC = gcc
NAME = main

main: $(NAME).c
	$(CC) -o main $(NAME).c

clean:
	rm main *_interpreter