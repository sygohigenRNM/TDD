CC=gcc
CFLAGS=-I.

all: main test

main: src/main.c
	$(CC) $(CFLAGS) -o main src/main.c

test: tests/test_main.c
	$(CC) $(CFLAGS) -o test_main tests/test_main.c

clean:
	rm -f main test_main
