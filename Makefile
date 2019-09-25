CC = gcc
CFLAGS = -g -Wall -ansi -std=c99

rabinMiller: rabinMiller.c
	$(CC) $(CFLAGS) -o rabinMiller rabinMiller.c

clean:
	rm -f rabinMiller
