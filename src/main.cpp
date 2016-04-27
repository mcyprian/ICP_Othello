#include <iostream>

#include <game_manager.hpp>

using namespace std;

int main(){

	GameManager gm;
	gm.initNewGame("MyGame", VERSUS, 10, "player", WHITE, SIMPLE);
	gm.getGame().playground().print();
	cout << "----------------------" << endl;
	if (gm.getGame().makeMove(4,3) == CANNOT_PUT)cout << "zle suradnice" << endl;
	else cout << "dobre suradnice" << endl;
	return 0;
}
