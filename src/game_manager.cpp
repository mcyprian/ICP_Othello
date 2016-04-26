#include <map>
#include <string>
#include <game.hpp>

#include <game_manager.hpp>

GameManager::GameManager(){
	this->game = nullptr; 
    this->initialized = false;
    //deserialize games into map
}

GameManager::~GameManager(){
	delete this->game;
	this->initialized = false;
	//serialize and free all games from map
}

void GameManager::initNewGame(string game_name, GameMode mode, int size, string name1, Color color, Difficulty d) {
    if (this->initialized)
        runtime_error(string(__func__) + string("Game can be initialized only once.\n"));
    this->game = new Game(game_name, mode, size);
    this->game->setPlayer_ai(name1, color, d);
    this->initialized = true;
}

void GameManager::initNewGame(string game_name, GameMode mode, int size, string name1, Color color, string name2) {
    if (this->initialized)
        runtime_error(string(__func__) + string("Game can be initialized only once.\n"));
    this->game = new Game(game_name, mode, size);
    this->game->setPlayer_vs(name1, color, name2);
    this->initialized = true;
}

void GameManager::save_game(){
	if (!this->initialized) runtime_error(string(__func__) + string("Game was not loaded\n"));
	saved[this->game->get_name()] = this->game;
}

void GameManager::load_game(string name){
    if (this->game != nullptr)
        this->saved[this->game->get_name()] = this->game;
    if (this->saved.count(name) == 0)
        runtime_error(string(__func__) + string("Game " + name + " doesn't exist.\n"));
    else
        this->game = this->saved[name];
}