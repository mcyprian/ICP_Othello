#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <playground.hpp>
#include <player.hpp>
#include <move.hpp>

class Game{
	string name;
	Playground * pground;
	GameMode mode;
	Player * p1;
	Player * p2;

	Player * turn;

	std::vector<Move*> v;

	int ready;

public:
	Game(string name, GameMode mode, int size = 8){
		this->name = name;
		this->mode = mode;
		this->pground = new Playground(size);
		this->p1 = nullptr;
		this->p2 = nullptr;
		this->turn = nullptr;
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
		if (this->mode != VERSUS) runtime_error(string(__func__) + string(": this function can be used only in versus mode\n"));

		this->p1 = new Player(name1, color);
		this->p2 = new Player(name2, color ? WHITE : BLACK);

		this->turn = this->p1;

		this->ready = 1;
		init();
	}

	void setPlayer_ai(string name, Color color, Difficulty d){
		if (this->mode != VERSUS) runtime_error(string(__func__) + string(": this function can be used only in AI mode\n"));

		this->p1 = new Player(name, color);
		this->p2 = new Player("AI", color ? WHITE : BLACK, d);

		this->turn = this->p1;

		this->ready = 1;
		init();
	}

	void change_turn(){
		if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));

		if (this->turn == this->p1)this->turn = this->p2;
		else if (this->turn == this->p2)this->turn = this->p1;
	}

	void init(){
		if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));

		int size = this->pground->get_size();

		this->pground->put_disk(size/2-1, size/2-1, WHITE);
		this->pground->put_disk(size/2, size/2, WHITE);
		this->pground->put_disk(size/2, size/2-1, BLACK);
		this->pground->put_disk(size/2-1, size/2, BLACK);
	}

	Color who_is(){
		return this->turn->color;
	}

	int make_move(){

	}

	int undo_move(){

	}

	int redo_move(){

	}

	void serialize(){

	}

	void deserialize(){

	}

};



#endif
