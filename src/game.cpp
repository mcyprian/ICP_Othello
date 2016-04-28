#include <game.hpp>
#include <playground.hpp>
#include <player.hpp>
#include <move.hpp>

#include <vector>


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
	if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));
	return this->turn->color;
}

string Game::getName(){
	return this->name;
}

RET Game::applyMove(Move & move){
	Playground * p = new Playground(*this->pground);
	for (auto c: move.getCoords()){
		if (!p->getDisk(c->x, c->y))return FAILURE;
		if (p->getDisk(c->x, c->y)->getColor() == this->who())return FAILURE;
		p->getDisk(c->x, c->y)->flip();
	}

	this->changeTurn();
	delete this->pground;
	this->pground = p;
	return OKAY;
}

RET Game::checkLine(int x, int y, int dx, int dy, Move & move){
	if (!this->pground->isValid(x, y))return FAILURE; 				//check if we are in bounds
	if (!this->pground->getDisk(x, y))return FAILURE;				//check if it's not empty field

	if (this->pground->getDisk(x, y)->getColor() == this->who())return OKAY;	//we found our color

	if (this->checkLine(x + dx, y + dy, dx, dy, move) == OKAY){
		move.addChange(x, y);
		return OKAY;
	}
	else{
		return FAILURE;
	}
}

RET Game::ableToPut(int x, int y, Move & move){
	int isPossible = 0;
	if (!this->pground->isValid(x, y))return FAILURE;

	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			if (!this->pground->isValid(i, j))continue;
			if (i == x && j == y)continue;
			
			if (this->pground->getDisk(i, j) && (this->pground->getDisk(i, j)->getColor() == this->who()))continue;

			if (this->checkLine(i, j, i - x, j - y, move) == OKAY) isPossible = 1;
		}
	}

	return isPossible ? OKAY : FAILURE;
}

MoveCons Game::makeMove(int x, int y, int * flipped, bool apply){
	if (!this->ready) runtime_error(string(__func__) + string(": this game is not ready\n"));
	
	Disk * disk = nullptr;
	if (flipped) *flipped = 0;

	if (!this->pground->isValid(x, y))return OUT_OF_RANGE;
	disk = this->pground->getDisk(x, y);

	if (disk != nullptr) return PUT_ALREADY;

	Move * move = new Move();
	if (this->ableToPut(x, y, *move)){
		if (flipped) *flipped = move->getFlipped();
		
		this->pground->putDisk(x, y, this->who());
		
		if (apply && this->applyMove(*move))
			this->moves.push_back(move);
		else runtime_error(string(__func__) + string(": cannot apply rule\n"));
		
		return MOVED;
	}
	else
		delete move;

	return CANNOT_PUT;
}

int Game::undoMove(){

}

int Game::redoMove(){

}

void Game::serialize(){

}

void Game::deserialize(){

}