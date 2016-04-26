#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"
#include "tempBoard.h"
#include "Character.h"

using namespace std;

class Enemy : public Character{

	friend class tempBoard;
	
	public:
		Enemy();
		~Enemy();
		void draw(int); // draws int number of enemies on the board 
		void AI(); // enemy's movement
		int get_num(); // returns number of enemies on the board
		int get_type(); // returns type of enemy

	private:
		int num; // number of enemies
		int type; // fygar or pooka - unless you just want two spearate classes for them

};

#endif
