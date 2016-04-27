#ifndef PLAYGROUND_HPP
#define PLAYGROUND_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <disk.hpp>

using namespace std;

class Playground {

	int size = 8;	
	Disk** grid;

public:
	Playground(int size);
	~Playground();
	
	void putDisk(int x, int y, Color c);
	Disk* & getDisk(int x, int y);

	RET isValid(int x, int y);

	void print();
	int getSize();
};

#endif