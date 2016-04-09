#include <iostream>

#include <playground.hpp>

using namespace std;

int main(){

	Playground  pl(8);
	pl.put_disk(3,3, WHITE);
	pl.print();
	return 0;
}
