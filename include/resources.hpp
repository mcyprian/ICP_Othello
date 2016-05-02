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
	SIMPLE,
	HARD,
	NONE
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
