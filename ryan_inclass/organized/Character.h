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

	public:
		Character();
		~Character();
		void move(char);
		bool loadMedia(SDL_Renderer *& gRenderer);
		void render(SDL_Renderer *& gRenderer);
		void dug(SDL_Renderer *& gRenderer, tempBoard & asd );
		/*
		Get Functions
		*/
		
		int get_xpos();
		int get_ypos();
		int get_xspeed();
		int get_yspeed()
		int get_state();
		int get_dirstat();
	private:
		int xpos; // x position
		int ypos; // y position
		int xspeed; // x speed
		int yspeed; // y speed
		int state; // walking, attacking, dead, still
		int dirstat; // 0 = facing right, 2 = facing left, 6 = facin down, 4 = facing up - when getting attacked by enemies this is important
		SDL_Rect r;
		int walkanimatecount;
		//Scene sprites
		SDL_Rect gSpriteClips[ 12 ];
		LTexture gSpriteSheetTexture;
};
#endif
