#ifndef RESOURCES_HPP
#define RESOURCES_HPP


enum Color {
	WHITE,
	BLACK
};

enum GameMode{
	VERSUS,
	AI
};

enum Difficulty{
	NONE,
	SIMPLE,
	HARD
};

enum MoveCons{
	MOVED,
	OUT_OF_RANGE,
	PUT_ALREADY,
	CANNOT_PUT
};

enum RET{
	OKAY = 1,
	FAILURE = 0
};

#endif