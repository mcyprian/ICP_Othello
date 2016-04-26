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

	Disk* & get_disk(int x, int y);

public:
	Playground(int size);
	~Playground();
	
	void put_disk(int x, int y, Color c);
	void print();
	int get_size();
};

#endif