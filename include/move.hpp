#ifndef MOVE_HPP
#define MOVE_HPP

#include <vector>
#include <boost/serialization/vector.hpp>

using namespace std;

class Coord{

	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & x & y;
		cout << version;
	}

public:
	int x;
	int y;
	Coord(){}
	Coord(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Move{
	int x;
	int y;
	vector<Coord*> diff;

	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & x & y & diff;
		cout << version;
	}

public:
	Move(){}
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