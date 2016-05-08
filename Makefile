CXX=g++
CXXFLAGS=-std=c++11 -g -Wall -Wextra -pedantic -O2
INC=-I./include
LDLIBS=-lboost_serialization $(INC)

default: hra2016-gui hra2016-cli

hra2016-cli:
	cd src && make && cp hra2016-cli ../hra2016-cli

hra2016-gui:
	cd gui && qmake-qt5 || qmake && make && cp gui ../hra2016-gui

doxygen:
	doxygen doc/dox

pack:
	zip xsroka00_xcypri01.zip data.bin  doc/*  examples/*  gui/*  include/*  LICENSE  Makefile  README.txt  src/*

clean:
	cd src && make clean
	cd gui && make clean
	rm -rf gui/gui gui/Makefile
	rm -rf doc/html
	rm -f hra2016-cli hra2016-gui
