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
		void draw(int); // draws int number of enemies on the board
		void AI(); // enemy's movement
		
		/*
		Get Functions
		*/
		int getXpos();
		int getYpos();
		int getState();
		int getSpeed();
		int getNum();

	private:
		int xpos; // x position
		int ypos; // y position
		int speed; // how fast the enemy is travelling - incremented as level increases
		int state; // moving, attacking, dead
		int num; // number of enemies

};









#endif
