#ifndef MOVE_HPP
#define MOVE_HPP

#include <vector>

class Coord{
public:
	int x;
	int y;
	Coord(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Move{
	int x;
	int y;
	vector<Coord*> diff;
public:
	Move(int x, int y){
		this->x = x;
		this->y = y;
	}

	~Move(){
		for (auto c: diff)
			delete c;
	}

	void addChange(int x, int y){
		this->diff.push_back(new Coord(x, y));
	}

	int getFlipped(){
		return this->diff.size();
	}

	int getX(){
		return this->x;
	}

	int getY(){
		return this->y;
	}

	vector<Coord*> & getCoords(){
		return diff;
	}

};
#endif