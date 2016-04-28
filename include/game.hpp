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

	std::vector<Move*> moves;

	int ready;

	RET checkLine(int x, int y, int dx, int dy, Move & move);
	RET ableToPut(int x, int y, Move & move);
	RET applyMove(Move & move);
	void changeTurn();

public:
	Game(string name, GameMode mode, int size);
	~Game();

	Playground & playground();

	void setPlayerVs(string name1, Color color, string name2);
	void setPlayerAi(string name, Color color, Difficulty d);

	void init();
	Color who();
	
	MoveCons makeMove(int x, int y, int * flipped, bool apply);
	
	int undoMove();
	int redoMove();

	void serialize();
	void deserialize();

	string getName();

};



#endif
