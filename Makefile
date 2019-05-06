CC=gcc
CFLAGS=-Wall -ansi -MLV
LDFLAGS= -lMLV -lm -lSDL
DEPS=
OBJ=

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

twobodies: twobodies.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) twobodies twobodies.o