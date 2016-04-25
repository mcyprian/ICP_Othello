#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <map>
#include <string>
#include <game.hpp>

class GameManager{
	Game *game;
    bool initialized;
    std::map<string, Game*> saved;
public:
	GameManager(){
		this->game = nullptr; 
        this->initialized = false;
        //deserialize games into map
	}
	~GameManager(){
		delete this->game;
		this->initialized = false;
		//serialize and free all games from map
	}

	void initNewGame(GameMode mode, int size, string name1, Color color, Difficulty d) {
        if (this->initialized)
            throw runtime_error("Game can be initialized only once.\n");
        this->game = new Game(mode, size);
        this->game->setPlayer_ai(name1, color, d);
        this->initialized = true;
    }

    void initNewGame(GameMode mode, int size, string name1, Color color, string name2) {
        if (this->initialized)
            throw runtime_error("Game can be initialized only once.\n");
        this->game = new Game(mode, size);
        this->game->setPlayer_vs(name1, color, name2);
        this->initialized = true;
    }

    int save_game(){
    	if (!this->initialized) throw runtime_error("Game was not loaded\n");
    	//save into map
    }

    int load_game(string name){
    	//save game and load from map
    }
};

#endif