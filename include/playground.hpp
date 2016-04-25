#ifndef PLAYGROUND_HPP
#define PLAYDROUND_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <disk.hpp>

using namespace std;

class Playground {

	int size = 8;
	
	Disk** grid;

	Disk* & get_disk(int x, int y){
		if (x > this->size || x < 0 || y > this->size || y < 0){
			runtime_error(string(__func__) + string(": index out of range\n"));
		}
		return this->grid[x*this->size + y];
	}

public:
	Playground(int size){
		this->size = size;
		grid = new Disk*[size*size];
		for (int i = 0 ; i < size*size ; i++)grid[i] = nullptr;
	}
	 
	~Playground(){
		for (int i = 0 ; i < size*size ; i++)delete grid[i];
		delete [] grid;
	}

	void put_disk(int x, int y, Color c){
		Disk* & d = get_disk(x, y);
		if (d == nullptr)d = new Disk(c);
	}

	void print(){
		for (int i = 0 ; i < this->size ; i++){
			for (int j = 0 ; j < this->size ; j++){
				cout << get_disk(i, j) << " ";
			}
		cout << endl;
		}
	}

	int get_size(){
		return this->size;
	}
};


#endif
