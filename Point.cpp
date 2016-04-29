#include "Point.h"
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
void Point::setColor(char k){
	color = k;
}


