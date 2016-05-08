CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -Wextra -pedantic -O2
INC=-I./include
LDLIBS=-lboost_serialization $(INC)

hra2016-cli: src/hra2016-cli.cpp src/cligame.cpp src/gameio.cpp src/climenu.cpp src/game.cpp src/game_manager.cpp src/playground.cpp src/commandlineinterface.cpp
	$(CXX) $(CXXFLAGS) $(LDLIBS) -o hra2016-cli

default: hra2016-cli

doxygen:
	doxygen doc/dox

pack:
	zip xsroka00__.zip *
