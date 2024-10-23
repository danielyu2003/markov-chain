CC = gcc
CFLAGS = -Wall -Wextra

INC = inc/
SRC = src/markov.c

.PHONY: build clean

build:
	$(CC) $(CFLAGS) $(SRC) -I$(INC) -o markov

clean:
	rm -f markov