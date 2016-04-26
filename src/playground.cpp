#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <disk.hpp>

#include <playground.hpp>


Playground::Playground(int size){
	this->size = size;
	grid = new Disk*[size*size];
	for (int i = 0 ; i < size*size ; i++)grid[i] = nullptr;
}
 
Playground::~Playground(){
	for (int i = 0 ; i < size*size ; i++)delete grid[i];
	delete [] grid;
}

void Playground::put_disk(int x, int y, Color c){
	Disk* & d = get_disk(x, y);
	if (d == nullptr)d = new Disk(c);
}

void Playground::print(){
	for (int i = 0 ; i < this->size ; i++){
		for (int j = 0 ; j < this->size ; j++){
			cout << get_disk(i, j) << " ";
		}
	cout << endl;
	}
}

int Playground::get_size(){
	return this->size;
}

Disk* & Playground::get_disk(int x, int y){
	if (x > this->size || x < 0 || y > this->size || y < 0){
		runtime_error(string(__func__) + string(": index out of range\n"));
	}
	return this->grid[x*this->size + y];
}
