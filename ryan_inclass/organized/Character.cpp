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
	move_vert_val = 8;
	move_horiz_val = 5;
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
	switch(dir)
	{
		case 'd':
	r.w = 56;
	r.y = ypos -8;
	r.x = xpos - 7;
	r.h = 55;
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
	r.w = 55;
	r.y = ypos -7;
	r.x = xpos - 7;
	r.h = 55;
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
	r.w = 55;
	r.y = ypos -7;
	r.x = xpos - 7;
	r.h = 55;
      if (xpos - move_horiz_val < 0){
        xpos = xpos;
      }
      else{
        xpos -= move_horiz_val;
      }
			dirstat = 2;
			break;
		case 'r':
	r.w = 55;
	r.y = ypos -7 ;
	r.x = xpos -7;
	r.h = 55;
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
		/*
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

*/
//Pookas facing the right, going from right to left respectively

//Player walking to the right sprites

gSpriteClips[ 0 ].x = 0;
gSpriteClips[ 0 ].y = 0;
gSpriteClips[ 0 ].w = 38;
gSpriteClips[ 0 ].h = 39;

gSpriteClips[ 1 ].x = 40;
gSpriteClips[ 1 ].y =  0;
gSpriteClips[ 1 ].w = 34;
gSpriteClips[ 1 ].h = 39;

//Player walking to the left sprites

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

// First Pooka
gSpriteClips[ 12 ].x =   0;
gSpriteClips[ 12 ].y = 157;
gSpriteClips[ 12 ].w =  35;
gSpriteClips[ 12 ].h =  34;

// Second Pooka
gSpriteClips[ 13 ].x =  37;
gSpriteClips[ 13 ].y = 158;
gSpriteClips[ 13 ].w =  35;
gSpriteClips[ 13 ].h =  34;

// Third Pooka (his eyes) 
gSpriteClips[ 14 ].x =  75;
gSpriteClips[ 14 ].y = 165;
gSpriteClips[ 14 ].w =  35;
gSpriteClips[ 14 ].h =  22;

// Fourth Pooka (blinking eyes)
gSpriteClips[ 15 ].x = 110;
gSpriteClips[ 15 ].y = 165;
gSpriteClips[ 15 ].w =  35;
gSpriteClips[ 15 ].h =  22;

// Fifth Pooka (starting to blow up)
gSpriteClips[ 16 ].x = 146;
gSpriteClips[ 16 ].y = 156;
gSpriteClips[ 16 ].w =  37;
gSpriteClips[ 16 ].h =  41;

// Sixth Pooka
gSpriteClips[ 17 ].x = 187;
gSpriteClips[ 17 ].y = 152;
gSpriteClips[ 17 ].w =  56;
gSpriteClips[ 17 ].h =  45;

// Seventh Pooka
gSpriteClips[ 18 ].x = 243;
gSpriteClips[ 18 ].y = 144;
gSpriteClips[ 18 ].w =  60;
gSpriteClips[ 18 ].h =  54;

// Eighth Pooka
gSpriteClips[ 19 ].x = 306;
gSpriteClips[ 19 ].y = 141;
gSpriteClips[ 19 ].w =  65;// if you get rid off crushed by rock pooka, increase to 66 or 67
gSpriteClips[ 19 ].h =  56;

// Done with first set of Pookas.  Doing his arrows next.  You placed them all too close together so that may cause slight off by 1 errors later on

// Up Arrow
gSpriteClips[ 20 ].x = 448;
gSpriteClips[ 20 ].y = 127;
gSpriteClips[ 20 ].w =  17;
gSpriteClips[ 20 ].h =  81;

// Down Arrow
gSpriteClips[ 21 ].x = 464;
gSpriteClips[ 21 ].y = 127;
gSpriteClips[ 21 ].w =  17;
gSpriteClips[ 21 ].h =  81;

// Pointing to the Left Arrow
gSpriteClips[ 22 ].x = 484;
gSpriteClips[ 22 ].y = 127;
gSpriteClips[ 22 ].w =  81;
gSpriteClips[ 22 ].h =  17;

// Pointing to the Right Arrow
gSpriteClips[ 23 ].x = 484;
gSpriteClips[ 23 ].y = 144;
gSpriteClips[ 23 ].w =  81;
gSpriteClips[ 23 ].h =  17;

// Right Fygar's First Fire
gSpriteClips[ 24 ].x =   1;
gSpriteClips[ 24 ].y = 272;
gSpriteClips[ 24 ].w =  43;
gSpriteClips[ 24 ].h =  37;

// Right Fygar's Second Fire
gSpriteClips[ 25 ].x =  47;
gSpriteClips[ 25 ].y = 265;
gSpriteClips[ 25 ].w =  85;
gSpriteClips[ 25 ].h =  44;

// Right Fygar's Third Fire
gSpriteClips[ 26 ].x = 132;
gSpriteClips[ 26 ].y = 265;
gSpriteClips[ 26 ].w = 126;
gSpriteClips[ 26 ].h =  46;

// Starting Fygar facing the right, going sequentially

// First Fygar
gSpriteClips[ 27 ].x =   0;
gSpriteClips[ 27 ].y = 227;
gSpriteClips[ 27 ].w =  36;
gSpriteClips[ 27 ].h =  37;

// Second Fygar
gSpriteClips[ 28 ].x =  37;
gSpriteClips[ 28 ].y = 227;
gSpriteClips[ 28 ].w =  38;
gSpriteClips[ 28 ].h =  37;

// Third Fygar (Blinking White fire signifier)
gSpriteClips[ 29 ].x =  75;
gSpriteClips[ 29 ].y = 227;
gSpriteClips[ 29 ].w =  38;
gSpriteClips[ 29 ].h =  37;

// Fourth Fygar (his eyes)
gSpriteClips[ 30 ].x = 112;
gSpriteClips[ 30 ].y = 232;
gSpriteClips[ 30 ].w =  40;
gSpriteClips[ 30 ].h =  31;

// Fifth Fygar (his meaner eyes)
gSpriteClips[ 31 ].x = 152;
gSpriteClips[ 31 ].y = 232;
gSpriteClips[ 31 ].w =  40;
gSpriteClips[ 31 ].h =  31;

// Sixth Fygar (starting to blow up)
gSpriteClips[ 32 ].x = 195;
gSpriteClips[ 32 ].y = 227;
gSpriteClips[ 32 ].w =  39;
gSpriteClips[ 32 ].h =  37;

// Seventh Fygar
gSpriteClips[ 33 ].x = 234;
gSpriteClips[ 33 ].y = 259;
gSpriteClips[ 33 ].w =  55;
gSpriteClips[ 33 ].h =  52;

// Eigth Fygar
gSpriteClips[ 34 ].x = 289;
gSpriteClips[ 34 ].y = 207;
gSpriteClips[ 34 ].w =  55;
gSpriteClips[ 34 ].h =  57;

// Ninth Fygar (popped)
gSpriteClips[ 35 ].x = 344;
gSpriteClips[ 35 ].y = 202;
gSpriteClips[ 35 ].w =  65;
gSpriteClips[ 35 ].h =  62;

// Finished Right Facing Fygar.  Starting Left Facing Fygar

// First Fygar
gSpriteClips[ 36 ].x = 268;
gSpriteClips[ 36 ].y = 278;
gSpriteClips[ 36 ].w =  37;
gSpriteClips[ 36 ].h =  37;

// Second Fygar
gSpriteClips[ 37 ].x = 307;
gSpriteClips[ 37 ].y = 278;
gSpriteClips[ 37 ].w =  37;
gSpriteClips[ 37 ].h =  37;

// Third Fygar (Starting to Blow up)
gSpriteClips[ 38 ].x = 353;
gSpriteClips[ 38 ].y = 281;
gSpriteClips[ 38 ].w =  40;
gSpriteClips[ 38 ].h =  37;

// Fourth Fygar
gSpriteClips[ 39 ].x = 397;
gSpriteClips[ 39 ].y = 272;
gSpriteClips[ 39 ].w =  54;
gSpriteClips[ 39 ].h =  52;

// Fifth Fygar
gSpriteClips[ 40 ].x = 460;
gSpriteClips[ 40 ].y = 266;
gSpriteClips[ 40 ].w =  55;
gSpriteClips[ 40 ].h =  57;

// Sixth Fygar (Popped)
gSpriteClips[ 41 ].x = 531;
gSpriteClips[ 41 ].y = 266;
gSpriteClips[ 41 ].w =  64;
gSpriteClips[ 41 ].h =  62;

// Left Fygar's First Fire
gSpriteClips[ 42 ].x = 500;
gSpriteClips[ 42 ].y = 339;
gSpriteClips[ 42 ].w =  43;
gSpriteClips[ 42 ].h =  37;

// Left Fygar's Second Fire
gSpriteClips[ 43 ].x = 412;
gSpriteClips[ 43 ].y = 331;
gSpriteClips[ 43 ].w =  85;
gSpriteClips[ 43 ].h =  44;

// Left Fygar's Third Fire
gSpriteClips[ 44 ].x = 287;
gSpriteClips[ 44 ].y = 334;
gSpriteClips[ 44 ].w = 126;
gSpriteClips[ 44 ].h =  46;

// Flower
gSpriteClips[ 45 ].x =   0;
gSpriteClips[ 45 ].y = 361;
gSpriteClips[ 45 ].w =  33;
gSpriteClips[ 45 ].h =  35;

// Player Dying
gSpriteClips[ 46 ].x =   0;
gSpriteClips[ 46 ].y = 318;
gSpriteClips[ 46 ].w =  41;
gSpriteClips[ 46 ].h =  38;

// Player Dying Second
gSpriteClips[ 47 ].x =  43;
gSpriteClips[ 47 ].y = 313;
gSpriteClips[ 47 ].w =  43;
gSpriteClips[ 47 ].h =  43;

// Player Dying Third
gSpriteClips[ 48 ].x =  88;
gSpriteClips[ 48 ].y = 313;
gSpriteClips[ 48 ].w =  43;
gSpriteClips[ 48 ].h =  43;

// Player Dying Fourth
gSpriteClips[ 49 ].x = 133;
gSpriteClips[ 49 ].y = 318;
gSpriteClips[ 49 ].w =  43;
gSpriteClips[ 49 ].h =  38;

// Poof He's Dead
gSpriteClips[ 50 ].x = 180;
gSpriteClips[ 50 ].y = 320;
gSpriteClips[ 50 ].w =  31;
gSpriteClips[ 50 ].h =  31;

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
void Character::die(SDL_Renderer *& gRenderer , tempBoard & myBoard){
	SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
	
	SDL_RenderFillRect( gRenderer, &r);
	SDL_RenderPresent(gRenderer);
	gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 46 ]);
	SDL_RenderPresent(gRenderer);
	usleep(500000);
	
	SDL_RenderFillRect( gRenderer, &r);
	SDL_RenderPresent(gRenderer);
	gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 47 ]);
	SDL_RenderPresent(gRenderer);
	usleep(500000);
	
	
	SDL_RenderFillRect( gRenderer, &r);
	SDL_RenderPresent(gRenderer);
	gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 48 ]);
	SDL_RenderPresent(gRenderer);
	
	usleep(500000);
	
	SDL_RenderFillRect( gRenderer, &r);
	SDL_RenderPresent(gRenderer);
	gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 49 ]);
	SDL_RenderPresent(gRenderer);
	usleep(500000);

	SDL_RenderFillRect( gRenderer, &r);
	SDL_RenderPresent(gRenderer);
	gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 50 ]);
	SDL_RenderPresent(gRenderer);
	
	usleep(500000);
}


void Character::shoot(SDL_Renderer *& gRenderer , tempBoard & myBoard){

	direction = get_dirstat();
	
	switch (direction)

	case 'u':
		SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
		SDL_RenderFillRect( gRenderer, &r);
		SDL_RenderPresent(gRenderer);
		gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 55 ]);
		SDL_RenderPresent(gRenderer);
		usleep(500000);
	
		SDL_RenderFillRect( gRenderer, &r);
		SDL_RenderPresent(gRenderer);
		gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 47 ]);
		SDL_RenderPresent(gRenderer);
		usleep(500000);
	
	
		SDL_RenderFillRect( gRenderer, &r);
		SDL_RenderPresent(gRenderer);
		gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 48 ]);
		SDL_RenderPresent(gRenderer);
	
		usleep(500000);
	
		SDL_RenderFillRect( gRenderer, &r);
		SDL_RenderPresent(gRenderer);
		gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 49 ]);
		SDL_RenderPresent(gRenderer);
		usleep(500000);

		SDL_RenderFillRect( gRenderer, &r);
		SDL_RenderPresent(gRenderer);
		gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 50 ]);
		SDL_RenderPresent(gRenderer);	
		usleep(500000);
}
