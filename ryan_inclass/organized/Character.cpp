#include <ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <SDL2/SDL_image.h>    // this actually gets SDL2_image
#include <stdio.h>
#include <string>
#include "Character.h"
#include "tempBoard.h"

using namespace std;

Character::Character()
{
	xpos = 504/2;
	ypos = 684/2;
	dirstat = 0;
	walkanimatecount = 0;
	r.x = xpos;
	r.y = ypos;
	r.w = 36;
	r.h = 36;
}

Character::~Character()

{
	gSpriteSheetTexture.free();
}
int Character::get_xpos(){
	return xpos;
}
int Character::get_ypos(){
	return ypos;
}
void Character::move(char dir)
{
	int move_vert_val = 8;
	int move_horiz_val = 5;
	switch(dir)
	{
		case 'd':
	r.w = 47;
	r.y = ypos ;
	r.x = xpos;
	r.h = 47;
      if (ypos + move_vert_val > 604){
        ypos = ypos;
      }
      else{
        ypos += move_vert_val;
	
      }
			if ((dirstat == 2)| (dirstat == 4 ) | (dirstat == 8)){
			
				dirstat = 8;
			}
			else if (( dirstat == 0 ) | (dirstat == 6) | (dirstat == 10)){
				dirstat = 10;
			}
			break;
		case 'u':
	r.w = 47;
	r.y = ypos -5 ;
	r.x = xpos;
	r.h = 47;
      if (ypos - move_vert_val < 108){
        ypos = ypos;
      }
      else{
        ypos -= move_vert_val;
      }
			if ((dirstat == 2)| (dirstat == 4 ) | (dirstat == 8)){
			
				dirstat = 4;
			}
			else if (( dirstat == 0 ) | (dirstat == 6) | (dirstat == 10)){
				dirstat = 6;
			}
			break;
		case 'l': 
	r.w = 47;
	r.y = ypos;
	r.x = xpos - 4;
	r.h = 47;
      if (xpos - move_horiz_val < 0){
        xpos = xpos;
      }
      else{
        xpos -= move_horiz_val;
      }
			dirstat = 2;
			break;
		case 'r':
	r.w = 47;
	r.y = ypos;
	r.x = xpos ;
	r.h = 47;
      if (xpos + move_horiz_val > 475){
        xpos = xpos;
      }
      else{
        xpos += move_horiz_val;
      }
			dirstat = 0;
			break;
	}
	walkanimatecount++;
	if (walkanimatecount == 500){
		walkanimatecount = 0;
	}

}

void Character::render(SDL_Renderer *& gRenderer)
{
	gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ (dirstat + walkanimatecount%2) ]);
}



bool Character::loadMedia(SDL_Renderer *& gRenderer)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "./sprites.png" , gRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
	{
		// Both walking right sprites
		gSpriteClips[ 0 ].x =  0;
		gSpriteClips[ 0 ].y =  0;
		gSpriteClips[ 0 ].w = 38;
		gSpriteClips[ 0 ].h = 39;
	
		gSpriteClips[ 1 ].x = 40;
		gSpriteClips[ 1 ].y =  0;
		gSpriteClips[ 1 ].w = 34;
		gSpriteClips[ 1 ].h = 39;

		// Both walking left sprites
		gSpriteClips[ 2 ].x = 543;
		gSpriteClips[ 2 ].y =   0;
		gSpriteClips[ 2 ].w =  39;
		gSpriteClips[ 2 ].h =  39;

		gSpriteClips[ 3 ].x = 506;
		gSpriteClips[ 3 ].y =   0;
		gSpriteClips[ 3 ].w =  34;
		gSpriteClips[ 3 ].h =  39;

		// Both walking up facing left sprites
		gSpriteClips[ 4 ].x =  0;
		gSpriteClips[ 4 ].y = 86;
		gSpriteClips[ 4 ].w = 39;
		gSpriteClips[ 4 ].h = 40;

		gSpriteClips[ 5 ].x = 40;
		gSpriteClips[ 5 ].y = 86;
		gSpriteClips[ 5 ].w = 39;
		gSpriteClips[ 5 ].h = 40;

		// Both walking up facing right sprites
		gSpriteClips[ 6 ].x = 502;
		gSpriteClips[ 6 ].y =  91;
		gSpriteClips[ 6 ].w =  39;
		gSpriteClips[ 6 ].h =  38;

		gSpriteClips[ 7 ].x = 543;
		gSpriteClips[ 7 ].y =  88;
		gSpriteClips[ 7 ].w =  37;
		gSpriteClips[ 7 ].h =  39;

		// Both walking down facing left sprites
		gSpriteClips[ 8 ].x = 544;
		gSpriteClips[ 8 ].y =  38;
		gSpriteClips[ 8 ].w =  39;
		gSpriteClips[ 8 ].h =  38;

		gSpriteClips[ 9 ].x = 502;
		gSpriteClips[ 9 ].y =  36;
		gSpriteClips[ 9 ].w =  39;
		gSpriteClips[ 9 ].h =  38;

		// Both walking down facing right sprites
		gSpriteClips[ 10 ].x =  0;
		gSpriteClips[ 10 ].y = 39;
		gSpriteClips[ 10 ].w = 39;
		gSpriteClips[ 10 ].h = 38;

		gSpriteClips[ 11 ].x = 38;
		gSpriteClips[ 11 ].y = 38;
		gSpriteClips[ 11 ].w = 39;
		gSpriteClips[ 11 ].h = 38;

	}

	return success;
}

void Character::dug(SDL_Renderer *& gRenderer, tempBoard & myBoard) {

	for (int i = r.x; i < r.x+r.w; i ++){
		for ( int j = r.y; j < r.y+r.h; j++){
			if ((i >= 0 ) &( j >=0) & (i < 504) & (j < 684)){
				myBoard.points[i][j].setColor('b');
			}
		}
		
	}

	SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
	SDL_RenderFillRect( gRenderer, &r);

}
