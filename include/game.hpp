#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <playground.hpp>
#include <player.hpp>
#include <move.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>


class Game{
	string name;
	Playground * pground;
	GameMode mode;
	Player * p1;
	Player * p2;

	Player * turn;

	vector<Move*> moves;
	int index;

	int ready;

	RET checkLine(int x, int y, int dx, int dy, Move & move);
	RET ableToPut(int x, int y, Move & move);
	RET applyMove(Move & move);
	RET revertMove(Move & move);
	void addMove(Move * move);
	void changeTurn();

	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & name;
		ar & pground;
		ar & mode;
		ar & p1;
		ar & p2;
		ar & turn;
		ar & moves;
		ar & index;
		ar & ready;
		cout << version;
	}

public:
	Game(){}
	Game(string name, GameMode mode, int size);
	~Game();

	Playground & playground();

	void setPlayerVs(string name1, Color color, string name2);
	void setPlayerAi(string name, Color color, Difficulty d);

	void init();
	Color who();
	
	MoveCons makeMove(int x, int y, int * flipped, bool apply);
	RET existMove();
	
	RET undoMove();
	RET redoMove();

	void serialize();
	void deserialize();

	int getNumOfMoves();
	string getName() const { return this->name; }
    Player *getPlayer1() const { return this->p1; }
    Player *getPlayer2() const { return this->p2; }
    GameMode getMode() const { return this->mode; }

};



#endif
