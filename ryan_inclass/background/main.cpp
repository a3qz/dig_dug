/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

/////////////////////////////////////////// PLAN FOR THE FUTURE: NO ARRAY< JUST DELETE BEHIND MAN EVERY TIME


//Using SDL, SDL_image, standard math, and strings
#include <ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <SDL2/SDL_image.h>    // this actually gets SDL2_image
#include <stdio.h>
#include <string>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 504;
const int SCREEN_HEIGHT = 684;
//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;



//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

class Point{
	friend class tempBoard;

	public:
		Point(  );
		Point( int, int, char );
		~Point();
		void setState(int);
		int getState();
		int getx();
		int gety();
		char getColor();
		void setColor();
		void setx();
	private:
		char color;
		int state;
		int x;
		int y;


};

Point::Point(){
	state = 1;
}
Point::~Point(){}
Point::Point(int newx , int newy, char col){
	x = newx;
	y = newy;
	color = col;
	state = 1;
	
}

void Point::setState(int g){
	state = g;
}

int Point::getState(){

	return state;
}
int Point::getx(){
	return x;
}
int Point::gety(){
	return y;
}
char Point::getColor(){
	return color;
}


class tempBoard{


	public:
    tempBoard();
    ~tempBoard();
		bool loadMedia();
		void render();
	private:
		//Scene sprites
		SDL_Rect gSpriteClips;
		Point points[504][684];

		LTexture gSpriteSheetTexture;



};

//Character class
class Player{

	public:
		Player();
		~Player();
		int get_xpos();
		int get_ypos();
		void move(char);
		bool loadMedia();
		void render();
	private:
		int xpos;
		int ypos; 
		int dirstat; // 0 = facing right, 2 = facing left, 6 = facin down, 4 = facing up
		int walkanimatecount;
		//Scene sprites
		SDL_Rect gSpriteClips[ 12 ];
		LTexture gSpriteSheetTexture;



};
Player::Player()
{
	xpos = SCREEN_WIDTH/2;
	ypos = SCREEN_HEIGHT/2;
	dirstat = 0;
	walkanimatecount = 0;

}

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
Player::~Player()

{
	gSpriteSheetTexture.free();
}
int Player::get_xpos(){
	return xpos;
}
int Player::get_ypos(){
	return ypos;
}
void Player::move(char dir)
{
	int move_vert_val = 8;
	int move_horiz_val = 5;
	switch(dir)
	{
		case 'd':
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
      if (xpos - move_horiz_val < 0){
        xpos = xpos;
      }
      else{
        xpos -= move_horiz_val;
      }
			dirstat = 2;
			break;
		case 'r':
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

void tempBoard::render()
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

void Player::render()
{
	gSpriteSheetTexture.render( xpos, ypos, &gSpriteClips[ (dirstat + walkanimatecount%2) ] );
}


LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render( int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
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

bool tempBoard::loadMedia(){
  bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "./background.png" ) )
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



bool Player::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "./sprites.png" ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
	{
		//Set top left sprite
		gSpriteClips[ 0 ].x =   0;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w = 39;
		gSpriteClips[ 0 ].h = 39;

		//Set top right sprite
		gSpriteClips[ 1 ].x = 40;
		gSpriteClips[ 1 ].y =   0;
		gSpriteClips[ 1 ].w = 34;
		gSpriteClips[ 1 ].h = 39;
		
		//Set bottom left sprite
		gSpriteClips[ 2 ].x =   544;
		gSpriteClips[ 2 ].y = 0;
		gSpriteClips[ 2 ].w = 39;
		gSpriteClips[ 2 ].h = 39;

		//Set bottom right sprite
		gSpriteClips[ 3 ].x = 506;
		gSpriteClips[ 3 ].y = 0;
		gSpriteClips[ 3 ].w = 34;
		gSpriteClips[ 3 ].h = 39;

		// Walking up left sprites
		gSpriteClips[ 4 ].x = 0;
		gSpriteClips[ 4 ].y = 86;
		gSpriteClips[ 4 ].w = 39;
		gSpriteClips[ 4 ].h = 40;

		gSpriteClips[ 5 ].x = 40;
		gSpriteClips[ 5 ].y = 86;
		gSpriteClips[ 5 ].w = 39;
		gSpriteClips[ 5 ].h = 40;


		// Walking up right sprites
		gSpriteClips[ 6 ].x = 506;
		gSpriteClips[ 6 ].y = 92;
		gSpriteClips[ 6 ].w = 37;
		gSpriteClips[ 6 ].h = 37;

		gSpriteClips[ 7 ].x = 543;
		gSpriteClips[ 7 ].y = 88;
		gSpriteClips[ 7 ].w = 37;
		gSpriteClips[ 7 ].h = 38;


		// Walking down left sprites
		gSpriteClips[ 8 ].x = 544;
		gSpriteClips[ 8 ].y = 38;
		gSpriteClips[ 8 ].w = 36;
		gSpriteClips[ 8 ].h = 38;

		gSpriteClips[ 9 ].x = 502;
		gSpriteClips[ 9 ].y = 36;
		gSpriteClips[ 9 ].w = 36;
		gSpriteClips[ 9 ].h = 36;


		// Walking down right sprites
		gSpriteClips[ 10 ].x = 0;
		gSpriteClips[ 10 ].y = 38;
		gSpriteClips[ 10 ].w = 39;
		gSpriteClips[ 10 ].h = 38;

		gSpriteClips[ 11 ].x = 38;
		gSpriteClips[ 11 ].y = 38;
		gSpriteClips[ 11 ].w = 39;
		gSpriteClips[ 11 ].h = 34;


	}

	return success;
}

void close()
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

int main( int argc, char* args[] )
{
	int lastmod = 0;
	tempBoard board;
	Player player_character;	
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
    board.loadMedia();


		if( !player_character.loadMedia() )
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
			board.render();
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
								lastmod = time(NULL);
				//	player_character.render();

								break;
							case SDLK_DOWN:
								player_character.move('d');
								lastmod = time(NULL);
					//player_character.render();
								break;
							case SDLK_LEFT:
								player_character.move('l');
								lastmod = time(NULL);
					//player_character.render();
								break;
							case SDLK_RIGHT:
								player_character.move('r');
								lastmod = time(NULL);
					//player_character.render();
								cout << "MOVED" << endl;
								break;
							case SDLK_z:
								board.render();
								break;

						}
					player_character.render();
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
	close();

	return 0;
}
