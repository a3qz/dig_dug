
//Using SDL, SDL_image, standard math, and strings
#include <ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <SDL2/SDL_image.h>    // this actually gets SDL2_image
#include <stdio.h>
#include <string>
#include "tempBoard.h"
#include "Character.h"
#include "LTexture.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 504;
const int SCREEN_HEIGHT = 684;

bool init(SDL_Renderer *& gRenderer, SDL_Window *& gWindow);
void close(SDL_Renderer *& gRenderer, SDL_Window *& gWindow);

//The window we'll be rendering to
//SDL_Window* gWindow = NULL;

//The window renderer
//SDL_Renderer* gRenderer = NULL;



int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;


	int lastmod = 0;
	tempBoard board;
	Character player_character;	
	//Start up SDL and create window
	if( !init(gRenderer, gWindow) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
   	player_character.loadMedia(gRenderer);


		if( !board.loadMedia( gRenderer) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			SDL_RenderClear( gRenderer );
			board.render(gRenderer);
			player_character.render(gRenderer);
			player_character.render(gRenderer);
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else if ((e.type == SDL_KEYDOWN) ) //& ((time(NULL) - lastmod) > 1))
					{
						switch( e.key.keysym.sym )
						{

							case SDLK_UP:
								player_character.move('u');
								cout << 'u'<< endl;
								lastmod = time(NULL);
				//	player_character.render();

								break;
							case SDLK_DOWN:
								player_character.move('d');
								cout << 'd'<< endl;
								lastmod = time(NULL);
					//player_character.render();
								break;
							case SDLK_LEFT:
								player_character.move('l');
								cout << 'l' << endl;
								lastmod = time(NULL);
					//player_character.render();
								break;
							case SDLK_RIGHT:
								player_character.move('r');
								cout << 'r' <<endl;
								lastmod = time(NULL);
					//player_character.render();
								break;
							case SDLK_z:
								board.render(gRenderer);
								break;

						}
					player_character.dug(gRenderer,board );
					player_character.render(gRenderer);
					player_character.render(gRenderer);
					SDL_RenderPresent( gRenderer );
					}
				}

				//Clear screen
				//SDL_SetRenderDrawColor( gRenderer, 255, 156, 0, 0xFF );
				//SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );

				//Render top left sprite
        //usleep(5000);

				//Render top right sprite
				//gSpriteSheetTexture.render( SCREEN_WIDTH - gSpriteClips[ 1 ].w, 0, &gSpriteClips[ 1 ] );

				//Render bottom left sprite
				//gSpriteSheetTexture.render( 0, SCREEN_HEIGHT - gSpriteClips[ 2 ].h, &gSpriteClips[ 2 ] );

				//Render bottom right sprite
			//	gSpriteSheetTexture.render( SCREEN_WIDTH - gSpriteClips[ 3 ].w, SCREEN_HEIGHT - gSpriteClips[ 3 ].h, &gSpriteClips[ 3 ] );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close( gRenderer,  gWindow);

	return 0;
}



void close( SDL_Renderer *& gRenderer, SDL_Window *& gWindow)
{
	//Free loaded images
//	gSpriteSheetTexture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


bool init(SDL_Renderer *& gRenderer, SDL_Window *& gWindow)
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


