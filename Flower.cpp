#include "Flower.h"
#include "time.h"
#include <stdlib.h>
#include "Character.h"
using namespace std;

Flower::Flower(){
//	srand(time(NULL));

	xpos = rand()%475;
	ypos = rand()%496 +108; 
	dirstat = 0;
	walkanimatecount = 0;
	a.x = xpos;
	a.y = ypos;
	a.w = 36;
	a.h = 36;
	r.x = xpos;
	r.y = ypos;
	r.w = 36;
	r.h = 36;



}
Flower::~Flower(){
	gSpriteSheetTexture.free();

}


void Flower::render(SDL_Renderer *& gRenderer)
{
		gSpriteSheetTexture.renderClip( gRenderer, xpos, ypos, &gSpriteClips[ 45 ]);
}
int Flower::get_xpos(){
	return xpos;
}
int Flower::get_ypos(){
	return ypos;
}
