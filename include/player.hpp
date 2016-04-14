#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <resources.hpp>

using namespace std;

class Player{
	string name;
	Color color;
	Difficulty dif;

public:
	Player(string name, Color color, Difficulty d = NONE){
		this->name = name;
		this->color = color;
		this->dif = d;
	}


	~Player(){}
	
};

#endif