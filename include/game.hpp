#ifndef GAME_HPP
#define GAME_HPP

#include <playground.hpp>
#include <player.hpp>

class Game{
	Playground * pground;
	GameMode mode;
	Player * p1;
	Player * p2;

	int ready;

public:
	Game(GameMode mode, int size = 8){
		this->mode = mode;
		this->pground = new Playground(size);
		this->p1 = nullptr;
		this->p2 = nullptr;
		this->ready = 0;
	}

	~Game(){
		delete this->pground;
		delete this->p1;
		delete this->p2;
	}

	Playground & playground(){
		return *this->pground;
	}

	void setPlayer_vs(string name1, Color color, string name2){
		if (this->mode != VERSUS)runtime_error(string(__func__) + string(": this function can be used only in versus mode\n"));

		this->p1 = new Player(name1, color);
		this->p2 = new Player(name2, color ? WHITE : BLACK);

		this->ready = 1;
	}

	void setPlayer_ai(string name, Color color, Difficulty d){
		if (this->mode != VERSUS)runtime_error(string(__func__) + string(": this function can be used only in AI mode\n"));

		this->p1 = new Player(name, color);
		this->p2 = new Player("AI", color ? WHITE : BLACK, d);

		this->ready = 1;
	}

	void init(){

	}

};



#endif
