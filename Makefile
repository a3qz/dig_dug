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

Enemy.o:Enemy.h Enemy.cpp
	$(CC) Enemy.cpp -c -w -lSDL2_image -lSDL2 -o Enemy.o

Flower.o:Flower.h Flower.cpp
	$(CC) Flower.cpp -c -w -lSDL2_image -lSDL2 -o Flower.o

Win.o:Win.h Win.cpp
	$(CC) Win.cpp -c -w -lSDL2_image -lSDL2 -o Win.o

main : main.cpp sprites.png LTexture.o tempBoard.o Character.o Enemy.o Flower.o Win.o
			$(CC) main.cpp LTexture.o tempBoard.o Point.o Character.o Enemy.o Flower.o Win.o -w -lSDL2 -lSDL2_image -lSDL2_ttf -o main

clean:
	    rm -f $(TARGETS) *.o
