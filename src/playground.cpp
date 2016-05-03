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

Playground::Playground(Playground & p){
	this->size = p.getSize();
	grid = new Disk*[this->size*this->size];
	for (int i = 0 ; i < this->size ; i++){
		for (int j = 0; j < this->size; j++){
			this->getDisk(i, j) = nullptr;
			if (p.getDisk(i, j))
				this->putDisk(i, j, p.getDisk(i, j)->getColor());
		}
	}
}
 
Playground::~Playground(){
	for (int i = 0 ; i < size*size ; i++)delete grid[i];
	delete [] grid;
}

void Playground::putDisk(int x, int y, Color c){
	Disk* & d = getDisk(x, y);
	if (d == nullptr)d = new Disk(c);
}

void Playground::freeDisk(int x, int y){
	Disk* & d = getDisk(x, y);
	delete d;
	d = nullptr;
}

void Playground::print(){
	for (int i = 0 ; i < this->size ; i++){
		for (int j = 0 ; j < this->size ; j++){
			Disk * d = getDisk(i, j);
			char c = d ? (d->getColor() == WHITE ? 'W' : 'B') : '_';
			cout << c << " ";
		}
	cout << endl;
	}
}

int Playground::getSize(){
	return this->size;
}

RET Playground::isValid(int x, int y){
	if (x >= this->size || x < 0 || y >= this->size || y < 0)return FAILURE;
	else return OKAY;
}

Disk* & Playground::getDisk(int x, int y){
	if (!this->isValid(x, y)){
		runtime_error(string(__func__) + string(": index out of range\n"));
	}
	return this->grid[x*this->size + y];
}
