#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <map>
#include <vector>
#include <string>
#include <game.hpp>

class GameManager{
	Game *game;
    bool initialized;
    std::map<string, Game*> saved;

public:
	GameManager();
	~GameManager();

	void initNewGame(string game_name, GameMode mode, int size, string name1, Color color, Difficulty d);
    void initNewGame(string game_name, GameMode mode, int size, string name1, Color color, string name2);

    void save_game();
    void load_game(string name);

    vector<string> * get_saved_games();

};

#endif