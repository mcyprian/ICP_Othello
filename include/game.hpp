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
	Game(string name, GameMode mode, int size);
	~Game();

	Playground & playground();

	void setPlayer_vs(string name1, Color color, string name2);
	void setPlayer_ai(string name, Color color, Difficulty d);

	void change_turn();
	void init();
	Color who();

	int make_move();
	int undo_move();
	int redo_move();

	void serialize();
	void deserialize();

	string get_name();

};



#endif
