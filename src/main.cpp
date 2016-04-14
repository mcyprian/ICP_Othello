#include <iostream>

#include <game.hpp>

using namespace std;

int main(){

	Game game(VERSUS, 10);
	game.playground().put_disk(3,5, WHITE);
	game.playground().print();
	return 0;
}
