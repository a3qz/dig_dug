
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>    // this actually gets SDL2_image
#include "tempBoard.h"
#include "Point.h"
using namespace std;


tempBoard::tempBoard(){
	for ( int j = 0; j < 684; j++){
		for( int i = 0; i < 504; i ++){
			points[i][j].x = i;
			points[i][j].y = j;
			if ( j < 108){
				points[i][j].color = 'u';
			}
			else if (j < 252){
				points[i][j].color = 'y';
			}
			else if (j < 369){
				points[i][j].color = 'o';
			}
			else if (j < 540){
				points[i][j].color = 'r';
			}
			else{
				points[i][j].color = 'b';
			}
		
		}
	}
}

tempBoard::~tempBoard(){

	gSpriteSheetTexture.free();

}



bool tempBoard::loadMedia(SDL_Renderer *& gRenderer){
  bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "./background.png" , gRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
	{
		//Set top left sprite
		gSpriteClips.x =   0;
		gSpriteClips.y =   0;
		gSpriteClips.w = 504;
		gSpriteClips.h = 108;


	}

	return success;
}






void tempBoard::render( SDL_Renderer *& gRenderer)
{
	for ( int j = 0; j < 684; j++){
		for( int i = 0; i < 504; i ++){
			if( points[i][j].state ==  1){
				switch(points[i][j].color){
					case 'u':
						SDL_SetRenderDrawColor(gRenderer, 0, 0, 225, 0);
						break;
					case 'o':
						SDL_SetRenderDrawColor(gRenderer, 255, 128, 0, 0);
						break;
					case 'r':
						SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0);
						break;
					case 'y':
						SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 0);
						break;
					case 'b':
						SDL_SetRenderDrawColor(gRenderer, 102, 51, 0, 0);
						break;


				
				
				}
			
			}
			else{
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
			}
			SDL_RenderDrawPoint(gRenderer, i, j);
		}
	}
	//gSpriteSheetTexture.render( 0, 0, &gSpriteClips);
}




