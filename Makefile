# Find the meaning of the variables here: http://www.gnu.org/software/make/manual/make.html#Writing-Recipes-with-Directory-Search
CC=gcc
CFLAGS=-Ista -fdiagnostics-color=always -Wall -std=c11 $(shell sdl2-config --cflags)
LIBS=-lm -lSDL2_gfx -lSDL2_ttf $(shell sdl2-config --libs)

DRAWINGS=$(shell ls *.c | sed 's/\.c$$//')
SHOTS=$(shell ls *.c | sed 's/\.c$$/.shots.gif/')

all: project

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(DRAWINGS): %: %.o sta/drawing.o sta/input.o sta/misc.o sta/sketchbook.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.SILENT:
.PHONY: clean
clean:
	rm -f *.o sta/*.o $(DRAWINGS)
	rm -f shots/*.bmp

.PHONY: $(SHOTS)
$(SHOTS): %.shots.gif: %
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	rm -f shots/*.bmp
	./$^ -s
	echo "combining shots (this can take a while)..."
	convert -delay 4 -loop 0 shots/*.bmp $@ # this needs image magick installed
	echo "result written to $@"
	rm -f shots/*.bmp
