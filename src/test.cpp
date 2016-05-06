#include <iostream>
#include <fstream>

#include <game_manager.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;

int main(){

	GameManager gm;
	gm.initNewGame("gamename", AI, 8, "p1", WHITE, SIMPLE);
	{
    	ofstream ofs("data.bin", ios::binary);
    	boost::archive::text_oarchive ar(ofs);
		ar & gm;
	}

	cout << gm.getGame().getName() << endl;

	GameManager gm_new;
	{
    	ifstream ifs("data.bin", ios::binary);
    	boost::archive::text_iarchive ar(ifs);
		ar & gm_new;
	}

	cout << gm_new.getGame().getName() << endl;

	return 0;
}
