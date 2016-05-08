/**
 * @file resources.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Enums to share for every module.
 */

#ifndef RESOURCES_HPP
#define RESOURCES_HPP

/** Color of disk/player */
enum Color {
	WHITE,
	BLACK
};

/** Mode of Game */
enum GameMode{
	VERSUS,
	AI
};

/** Difficulty of Player(AI) */
enum Difficulty{
	SIMPLE,
	HARD,
	NONE
};

/** MakeMove possible returns */
enum MoveCons{
	MOVED,
	OUT_OF_RANGE,
	PUT_ALREADY,
	CANNOT_PUT
};

/** Return macros */
enum RET{
	OKAY = 1,
	FAILURE = 0
};

#endif
