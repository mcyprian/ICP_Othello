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

void Game::setPlayerVs(string name1, Color color, string name2){
	if (this->mode != VERSUS) runtime_error(string(__func__) + string(": this function can be used only in versus mode\n"));

	this->p1 = new Player(name1, color);
	this->p2 = new Player(name2, color ? WHITE : BLACK);

	this->turn = this->p1->color == BLACK ? this->p1 : this->p2;

	this->ready = 1;
	init();
}

void Game::setPlayerAi(string name, Color color, Difficulty d){
	if (this->mode != VERSUS) runtime_error(string(__func__) + string(": this function can be used only in AI mode\n"));

	this->p1 = new Player(name, color);
	this->p2 = new Player("AI", color ? WHITE : BLACK, d);

	this->turn = this->p1->color == BLACK ? this->p1 : this->p2;

	this->ready = 1;
	init();
}

void Game::changeTurn(){
	if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));

	if (this->turn == this->p1)this->turn = this->p2;
	else if (this->turn == this->p2)this->turn = this->p1;
}

void Game::init(){
	if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));

	int size = this->pground->getSize();

	this->pground->putDisk(size/2-1, size/2-1, WHITE);
	this->pground->putDisk(size/2, size/2, WHITE);
	this->pground->putDisk(size/2, size/2-1, BLACK);
	this->pground->putDisk(size/2-1, size/2, BLACK);
}

Color Game::who(){
	return this->turn->color;
}

string Game::getName(){
	return this->name;
}

int Game::ableToPut(int x, int y){
	
}

MoveCons Game::makeMove(int x, int y){
	Disk * disk = nullptr;
	try {
		disk = this->pground->getDisk(x, y);
	} catch (const runtime_error& error) {
		return OUT_OF_RANGE;
	}

	if (disk != nullptr) return PUT_ALREADY;

	this->pground->putDisk(x, y, this->who());

}

int Game::undoMove(){

}

int Game::redoMove(){

}

void Game::serialize(){

}

void Game::deserialize(){

}