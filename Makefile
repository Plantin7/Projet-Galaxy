CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
LDFLAGS= -lMLV -lm -lSDL
DEPS=in_out.c bodies.c graphic.c 
OBJ=in_out.o bodies.o graphic.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

galaxyA: galaxyA.o $(OBJ) $(SRC)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) galaxyA galaxyA.o in_out.o bodies.o graphic.o 