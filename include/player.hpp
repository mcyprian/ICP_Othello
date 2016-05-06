#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <resources.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

class Player{
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & name;
		ar & color;
		ar & dif;
		cout << version;
	}
public:
	string name;
	Color color;
	Difficulty dif;

	Player(){}
	Player(string name, Color color, Difficulty d = NONE){
		this->name = name;
		this->color = color;
		this->dif = d;
	}


	~Player(){}
	
};

#endif