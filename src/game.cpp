#include <game.hpp>
#include <vector>
#include <playground.hpp>
#include <player.hpp>
#include <move.hpp>


Game::Game(string name, GameMode mode, int size = 8){
		this->name = name;
		this->mode = mode;
		this->pground = new Playground(size);
		this->p1 = nullptr;
		this->p2 = nullptr;
		this->turn = nullptr;
		this->ready = 0;
	}

Game::~Game(){
		delete this->pground;
		delete this->p1;
		delete this->p2;
	}

Playground & Game::playground(){
		return *this->pground;
	}

void Game::setPlayer_vs(string name1, Color color, string name2){
	if (this->mode != VERSUS) runtime_error(string(__func__) + string(": this function can be used only in versus mode\n"));

	this->p1 = new Player(name1, color);
	this->p2 = new Player(name2, color ? WHITE : BLACK);

	this->turn = this->p1;

	this->ready = 1;
	init();
}

void Game::setPlayer_ai(string name, Color color, Difficulty d){
	if (this->mode != VERSUS) runtime_error(string(__func__) + string(": this function can be used only in AI mode\n"));

	this->p1 = new Player(name, color);
	this->p2 = new Player("AI", color ? WHITE : BLACK, d);

	this->turn = this->p1;

	this->ready = 1;
	init();
}

void Game::change_turn(){
	if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));

	if (this->turn == this->p1)this->turn = this->p2;
	else if (this->turn == this->p2)this->turn = this->p1;
}

void Game::init(){
	if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));

	int size = this->pground->get_size();

	this->pground->put_disk(size/2-1, size/2-1, WHITE);
	this->pground->put_disk(size/2, size/2, WHITE);
	this->pground->put_disk(size/2, size/2-1, BLACK);
	this->pground->put_disk(size/2-1, size/2, BLACK);
}

Color Game::who(){
	return this->turn->color;
}

string Game::get_name(){
	return this->name;
}

int Game::make_move(){

}

int Game::undo_move(){

}

int Game::redo_move(){

}

void Game::serialize(){

}

void Game::deserialize(){

}