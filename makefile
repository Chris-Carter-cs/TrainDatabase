CC=gcc
CFLAGS=-I.

shell:
	$(CC) shell.c sqlite3.c -lpthread -ldl -lm -o sqlite3

train: Rail.o sqlite3.o
	$(CC) -o train sqlite3.o Rail.o