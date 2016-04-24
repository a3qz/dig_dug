
#ifndef TEMPBOARD_H
#define TEMPBOARD_H
#include "LTexture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Point.h"
class tempBoard{


	public:
		    tempBoard();
		    ~tempBoard();
		bool loadMedia(SDL_Renderer *& gRenderer);
		void render(SDL_Renderer *& gRenderer);
	private:
		//Scene sprites
		SDL_Rect gSpriteClips;
		Point points[504][684];

		LTexture gSpriteSheetTexture;



};


#endif
