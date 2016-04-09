#ifndef PLAYGROUND_HPP
#define PLAYDROUND_HPP

#include <iostream>
#include <cstddef>
#include <disk.hpp>

using namespace std;

class Playground {

	int size = 8;
	
	Disk** grid;

	Disk ** get_disk(int x, int y, int & err){
		if (x > this->size || x < 0 || y > this->size || y < 0){
			err = -1;
			return nullptr;
		}
		return &this->grid[x*this->size + y];
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

	int put_disk(int x, int y, Color c){
		int err = 0;
		Disk ** d = get_disk(x, y, err);
		
		if (err == -1)return err;

		if (*d == nullptr)*d = new Disk(c);
	}

	int print(){
		for (int i = 0 ; i < this->size ; i++){
			for (int j = 0 ; j < this->size ; j++){
				int a;
				cout << *get_disk(i, j, a) << " ";
			}
		cout << endl;
		}
	}
};


#endif
