CC=        g++
CFLAGS=    -w -lSDL2 -o
LD=        gcc
LDFLAGS=    -shared -o
AR=        ar
ARFLAGS=    rcs
TARGETS=    firstwindow

all:    $(TARGETS)

firstwindow : firstwindow.cpp
	$(CC) firstwindow.cpp -w -lSDL2 -lSDL2_image -o firstwindow

clean:
	rm -f $(TARGETS) *.o

