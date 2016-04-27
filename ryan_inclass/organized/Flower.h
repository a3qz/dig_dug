#ifndef FLOWER_H 
#define FLOWER_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"
#include "tempBoard.h"
#include "Character.h"

class Flower : public Character{

	friend class tempBoard;
	friend class Character;
	friend class Point;
	
	public:
		Flower();
		~Flower();
		//void draw(int); // draws int number of enemies on the board 
//		bool loadMedia(SDL_Renderer *& gRenderer);
		void render(SDL_Renderer *& gRenderer);
		void dug(SDL_Renderer *& gRenderer, tempBoard & asd );
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
	private:
		static int num; // number of enemies
		SDL_Rect a;
		int type; // fygar or pooka - unless you just want two spearate classes for them

};

#endif
