
//Using SDL, SDL_image, standard math, and strings
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <SDL2/SDL_image.h>    // this actually gets SDL2_image
#include <stdio.h>
#include <string>
#include "tempBoard.h"
#include "Character.h"
#include "LTexture.h"
#include "Enemy.h"
#include <vector>
#include "Flower.h"
#include "Win.h"

using namespace std;

int check_dead(int player_x, int player_y, vector<int> monster_locations);
int check_flower(int player_x, int player_y, int flower_x, int flower_y);
void win(SDL_Renderer *& gRenderer);
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

	srand(time(0));
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	vector<int> contact;
	int lastmod = 0;
	tempBoard board;
	Character player_character;	
	Flower winflower;
	//Enemy enemy;
	int numEnemies = 3;
	int variable = 1;
	vector<Enemy> enVec;
	for (int i = 0; i < numEnemies; i++){

		Enemy enemy;
		enVec.push_back(enemy);
		while( variable == 1){
			enVec[i].set_xpos(rand()%475);
			rand();
			rand();
			rand();
			enVec[i].set_ypos(rand()%496 + 108);
			if (abs(enVec[i].get_xpos()-player_character.get_xpos())> 80){
				if(abs(enVec[i].get_ypos() - player_character.get_ypos()) > 100){
					variable = 0;
				}
			}
		}
	}
	//Start up SDL and create window
	if( !init(gRenderer, gWindow) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
   	player_character.loadMedia(gRenderer);
	for (int i = 0; i < numEnemies; i++){
		enVec[i].loadMedia(gRenderer);
	}
   	winflower.loadMedia(gRenderer);


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
			for (int i = 0; i < numEnemies; i++){
				enVec[i].render(gRenderer);
				enVec[i].render(gRenderer);
			}
			int store = 1;
			LTexture gSpriteSheetTexture;
			SDL_Rect gSpriteClips;
			gSpriteSheetTexture.loadFromFile("./background.png", gRenderer) ;
			gSpriteClips.x = 0;
			gSpriteClips.y = 0;
			gSpriteClips.w = 504;
			gSpriteClips.w = 684;
			while (store == 1){
						gSpriteSheetTexture.renderClip( gRenderer, 0, 0, &gSpriteClips);
						gSpriteSheetTexture.renderClip( gRenderer, 0, 0, &gSpriteClips);
				SDL_RenderPresent( gRenderer );
				SDL_PollEvent( &e ) ;
				if (e.type == SDL_KEYDOWN){
					if (e.key.keysym.sym == SDLK_SPACE)
						store = 0;
				}
				
				
			
			}
			while( !quit )
			{
				//usleep(50000);
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
				for (int i = 0; i < numEnemies; i++){
					enVec[i].AI(gRenderer, player_character.get_xpos(), player_character.get_ypos());
				}
				//enemy.asdf();
				contact.clear();
				for (int i = 0; i < numEnemies; i++){
					contact.push_back(enVec[i].get_xpos());
					contact.push_back(enVec[i].get_ypos());
				}

				if (check_dead(player_character.get_xpos(), player_character.get_ypos(), contact)){
					cout << "DIEEEEEEEEEEE" << endl;
					player_character.die(gRenderer, board);
					SDL_RenderPresent( gRenderer );
					return 0;
				}
				if (check_flower(player_character.get_xpos(), player_character.get_ypos(), winflower.get_xpos(), winflower.get_ypos())){
	
				for (int i = 0; i < numEnemies; i++){
					enVec[i].die(gRenderer, board);
				}
				//win(gRenderer);
				Win winner;
				winner.loadMedia(gRenderer);
				winner.render(gRenderer);
				SDL_RenderPresent( gRenderer );
				SDL_Delay(5000);	

					return 0;		
				}
				
				for (int i = 0; i < numEnemies; i++){
					enVec[i].dug(gRenderer, board);
					enVec[i].render(gRenderer);
					enVec[i].render(gRenderer);
				}
				player_character.dug(gRenderer,board);
				player_character.render(gRenderer);
				player_character.render(gRenderer);
				winflower.render(gRenderer);
				winflower.render(gRenderer);
				//SDL_RenderPresent( gRenderer );
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



int check_dead(int player_x, int player_y, vector<int> monster_locations){
	for (int i = 1; i < monster_locations.size() ; i += 2){
		if ((monster_locations[i -1] <= player_x+35) & (monster_locations[i-1]+35 >= player_x )){
				cout << "XCONTACT" << endl;
			if((monster_locations[i] <= player_y+35) & (monster_locations[i]+35 >= player_y)){
				cout << "YCONTACT" << endl;
				return 1;
			}
		}
	}
	return 0;


}
int check_flower(int player_x, int player_y, int flower_x, int flower_y){
	cout << " Player: " << player_x << " " << player_y << endl << "Flower : " << flower_x << "  " << flower_y << endl;
	if (( flower_x <= player_x + 35) & (flower_x + 35 >= player_x)){
		cout << "ASD" << endl;
		if (( flower_y <= player_y + 35) & (flower_y+35 >= player_y)){
			cout << "FLOWER POWER" << endl;
			return 1;
		}
	}
	return 0;



}



void win(SDL_Renderer *& gRenderer){
	
	SDL_Rect asdf;
	asdf.x = 0;
	asdf.y = 0;
	asdf.w = 504;
	asdf.h = 684;
	SDL_SetRenderDrawColor( gRenderer, 255, 156, 255, 0xFF );
		SDL_RenderFillRect( gRenderer, &asdf);

		LTexture gSpriteSheetTexture;
			SDL_Rect gSpriteClips;
if( !gSpriteSheetTexture.loadFromFile( "./background.png" , gRenderer) )

	{
		printf( "Failed to load sprite sheet texture!\n" );
		//success = false;
	}
			gSpriteSheetTexture.loadFromFile("./background.png", gRenderer) ;
			gSpriteClips.x = 0;
			gSpriteClips.y = 0;
			gSpriteClips.w = 504;
			gSpriteClips.w = 684;

						gSpriteSheetTexture.renderClip( gRenderer, 0, 0, &gSpriteClips);

	//SDL_RenderClear( gRenderer );
	SDL_RenderPresent( gRenderer );
	SDL_Delay(5000);	

}
