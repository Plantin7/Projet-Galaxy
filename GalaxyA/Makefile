CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
LDFLAGS= -lMLV -lm -lSDL
DEPS=in_out.c bodies.c graphic.c 
OBJ=$(OBJPATH)bodies.o $(OBJPATH)graphic.o $(OBJPATH)in_out.o $(OBJPATH)galaxyA.o

OBJPATH=./obj/
SRCPATH=./src/

all: galaxyA

$(OBJPATH)bodies.o: $(SRCPATH)bodies.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)graphic.o: $(SRCPATH)graphic.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)in_out.o: $(SRCPATH)in_out.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)galaxyA.o: $(SRCPATH)galaxyA.c
	$(CC) -o $@ -c $< $(CFLAGS)

galaxyA: $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) galaxyA