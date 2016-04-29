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
	friend class Character;
	friend class Point;
	
	public:
		Enemy();
		~Enemy();
		void asdf();
		void gmove(char dir);
		//void draw(int); // draws int number of enemies on the board 
		void AI(SDL_Renderer *& gRenderer, int, int); // enemy's movement
		int get_num(); // returns number of enemies on the board
		int get_type(); // returns type of enemy
//		bool loadMedia(SDL_Renderer *& gRenderer);
		void render(SDL_Renderer *& gRenderer);
		void dug(SDL_Renderer *& gRenderer, tempBoard & asd );
		void die(SDL_Renderer *& gRenderer, tempBoard & myBoard);
		/*
		Get Functions
		*/
		
		int get_xpos();
		int get_ypos();
		int get_xspeed();
		int get_yspeed();
		int get_state();
		int get_dirstat();

		void set_state(int a);
		void set_xpos(int );
		void set_ypos(int);
	private:
		static int num; // number of enemies
		SDL_Rect a;
		int type; // fygar or pooka - unless you just want two spearate classes for them

};
#endif
