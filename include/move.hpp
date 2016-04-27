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
	vector<Coord*> diff;
public:
	Move(){};
	~Move(){
		for (auto c: diff)
			delete c;
	};

	void addChange(int x, int y){
		this->diff.push_back(new Coord(x, y));
		cout << "addChange" << this->diff.size() << endl;
	}

	vector<Coord*> & getCoords(){
		return diff;
	}

};
#endif