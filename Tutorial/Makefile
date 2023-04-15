CC = gcc
CFLAGS = -lncurses -lm
SOURCES = *.c

all: Rogue run clean

Rogue: 
		$(CC) $(SOURCES) $(CFLAGS) -o Rogue

run:
		./Rogue

clean:
		rm Rogue