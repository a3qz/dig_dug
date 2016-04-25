#ifndef POINT_H
#define POINT_H
using namespace std;

class Point{
	friend class tempBoard;
	friend class Character;

	public:
		Point(  );
		Point( int, int, char );
		~Point();
		void setState(int);
		int getState();
		int getx();
		int gety();
		char getColor();
		void setColor(char k);
		void setx();
	private:
		char color;
		int state;
		int x;
		int y;


};





#endif
