#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"
#include "tempBoard.h"

//Character class
class Character {
	friend class tempBoard;
	friend class Enemy;

	public:
		Character();
		~Character();
		void move(char);
		bool loadMedia(SDL_Renderer *& gRenderer);
		void render(SDL_Renderer *& gRenderer);
		void dug(SDL_Renderer *& gRenderer, tempBoard & asd );
		void shoot(SDL_Renderer *& gRenderer, TempBoard & myBoard)
		/*
		Get Functions
		*/
		
		int get_xpos();
		int get_ypos();
		int get_xspeed();
		int get_yspeed();
		int get_state();
		int get_dirstat();
		void die(SDL_Renderer *& gRenderer, tempBoard & myBoard);
	private:
		int xpos; // x position
		int ypos; // y position
		int move_vert_val; // x speed
		int move_horiz_val; // y speed
		int state; // walking, attacking, dead, still
		int dirstat; // 0 = facing right, 2 = facing left, 6 = facin down, 4 = facing up - when getting attacked by enemies this is important
		SDL_Rect r;
		int walkanimatecount;
		int type;
		//Scene sprites
		SDL_Rect gSpriteClips[ 51];
		LTexture gSpriteSheetTexture;
};
#endif
