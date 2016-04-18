CC=        g++
CFLAGS=    -w -lSDL2 -o
LD=        gcc
LDFLAGS=    -shared -o
AR=        ar
ARFLAGS=    rcs
TARGETS=    main 

all:    $(TARGETS)

main : main.cpp sprites.png
			$(CC) main.cpp -w -lSDL2 -lSDL2_image -o main

clean:
	    rm -f $(TARGETS) *.o
