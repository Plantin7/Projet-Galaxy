CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
LDFLAGS= -lMLV -lm -lSDL
OBJ=$(OBJPATH)bodies.o $(OBJPATH)graphic.o $(OBJPATH)quadtree.o $(OBJPATH)in_out.o $(OBJPATH)galaxyB.o

OBJPATH=./obj/
SRCPATH=./src/

all: galaxyB

$(OBJPATH)bodies.o: $(SRCPATH)bodies.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)graphic.o: $(SRCPATH)graphic.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)in_out.o: $(SRCPATH)in_out.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)quadtree.o: $(SRCPATH)quadtree.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJPATH)galaxyB.o: $(SRCPATH)galaxyB.c
	$(CC) -o $@ -c $< $(CFLAGS)

galaxyB: $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) galaxyB