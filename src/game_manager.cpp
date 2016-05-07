#include <map>
#include <string>
#include <game.hpp>
#include <fstream>

#include <sys/stat.h>

#include <game_manager.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

GameManager::GameManager(){
	this->game = nullptr;
    this->initialized = false;
/*
    struct stat stat_buf;
    int rc = stat("data.bin", &stat_buf);
    */
}

GameManager::~GameManager(){
	//delete this->game;
	this->initialized = false;

	for (auto p: this->saved){
		delete p.second;
		p.second = nullptr;
	}
}

Game & GameManager::getGame(){
	return *this->game;
}

void GameManager::initNewGame(string game_name, GameMode mode, int size, string name1, Color color, Difficulty d) {
    if (this->initialized)
        runtime_error(string(__func__) + string("Game can be initialized only once.\n"));
    this->game = new Game(game_name, mode, size);
    this->game->setPlayerAi(name1, color, d);
    this->initialized = true;

    this->saveGame();
}

void GameManager::initNewGame(string game_name, GameMode mode, int size, string name1, Color color, string name2) {
    if (this->initialized)
        runtime_error(string(__func__) + string("Game can be initialized only once.\n"));
    this->game = new Game(game_name, mode, size);
    this->game->setPlayerVs(name1, color, name2);
    this->initialized = true;

    this->saveGame();
}

void GameManager::saveGame(){
	if (!this->initialized) runtime_error(string(__func__) + string("Game was not loaded\n"));
	saved[this->game->getName()] = this->game;
}

void GameManager::removeGame(string name){
    if (!this->initialized) runtime_error(string(__func__) + string("Game was not loaded\n"));
    if (saved[name] != this->game)
    delete saved[name];
    saved.erase(name);
}

void GameManager::loadGame(string name){
    if (this->game != nullptr)
        this->saved[this->game->getName()] = this->game;
    if (this->saved.count(name) == 0)
        runtime_error(string(__func__) + string("Game " + name + " doesn't exist.\n"));
    else
        this->game = this->saved[name];
}

std::vector<string> * GameManager::getSavedGames(){
	vector<string> * v = new vector<string>();

	for (auto p: this->saved){
		v->push_back(p.second->getName());
	}
	return v;
}

void GameManager::serialize(string filename){
    ofstream ofs(filename, ios::binary);
    boost::archive::text_oarchive ar(ofs);
    ar & this->saved;
}

void GameManager::deserialize(string filename){
    ifstream ifs(filename, ios::binary);
    boost::archive::text_iarchive ar(ifs);
    ar & this->saved;
}