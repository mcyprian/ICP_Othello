#include <iostream>

#include <game_manager.hpp>

using namespace std;

int main(){

	GameManager gm;
	gm.initNewGame("MyGame", VERSUS, 10, "player", WHITE, SIMPLE);
	gm.getGame().playground().print();
	return 0;
}
