CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -Wextra -pedantic -O2 -I../include 
LDLIBS=-lboost_serialization 

hra2016-cli: hra2016-cli.o cligame.o gameio.o climenu.o game.o game_manager.o playground.o commandlineinterface.o
	$(CXX) $(LDFLAGS) -o hra2016-cli *.o $(LDLIBS) 
clean:
	rm -f *.o
	rm -f hra2016-cli
