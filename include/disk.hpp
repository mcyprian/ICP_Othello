#ifndef DISK_HPP
#define DISK_HPP

#include <resources.hpp>

#include <boost/serialization/access.hpp>

class Disk {

	Color color;

	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & color;
		std::cout << version;
	}
		
public:
	Disk(){}
	Disk(Color c){this->color = c;}
	void flip(){
		if (this->color == WHITE)this->color = BLACK;
 		else this->color = WHITE;
	}
	Color getColor(){return this->color;}
};


#endif
