#ifndef DISK_HPP
#define DISH_HPP

#include <resources.hpp>

class Disk {

	Color color;
		
public:
	Disk(Color c){this->color = c;}
	void flip(){
		if (this->color == WHITE)this->color = BLACK;
 		else this->color = WHITE;
	}
	Color get_color(){return this->color;}
};


#endif
