CC=        g++
CFLAGS=    -w -lSDL2 -o
LD=        gcc
LDFLAGS=    -shared -o
AR=        ar
ARFLAGS=    rcs
TARGETS=    main 

all:    $(TARGETS)

LTexture.o:LTexture.h LTexture.cpp
	$(CC) LTexture.cpp -c -w -lSDL2_image -lSDL2 -o LTexture.o

tempBoard.o:tempBoard.h tempBoard.cpp Point.o
	$(CC) tempBoard.cpp  -c -w -lSDL2_image -lSDL2 -o tempBoard.o

Point.o:Point.h Point.cpp
	$(CC) Point.cpp -c -w -lSDL2_image -lSDL2 -o Point.o

Character.o:Character.h Character.cpp
	$(CC) Character.cpp -c -w -lSDL2_image -lSDL2 -o Character.o

main : main.cpp sprites.png LTexture.o tempBoard.o Character.o
			$(CC) main.cpp LTexture.o tempBoard.o Point.o Character.o -w -lSDL2 -lSDL2_image -lSDL2_ttf -o main

clean:
	    rm -f $(TARGETS) *.o
