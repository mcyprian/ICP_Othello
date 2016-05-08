/**
 * @file game.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Game class represents one game and it's state.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <playground.hpp>
#include <player.hpp>
#include <move.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

/** Contains methods to create game and it's behavior. */
class Game {
  string name;         /** Name of game */
  Playground *pground; /** Playground */

  GameMode mode; /** mode of game VERSUS/AI */

  Player *p1; /** first player */
  Player *p2; /** Nsecond player */

  Player *turn; /** player who has turn */

  vector<Move *> moves; /** vector of moves */
  int index; /** index for moves, it helps make forward and bacward move */

  int ready; /** Initialozation check */

  /** Recursive function for picked disk called for every direction from it */
  RET checkLine(int x, int y, int dx, int dy, Move &move);
  /** check if is able to put disk */
  RET ableToPut(int x, int y, Move &move);
  /** apply one move object to field */
  RET applyMove(Move &move);
  /** revert one move object from field, it's reverse apply */
  RET revertMove(Move &move);
  /** add created move to vector */
  void addMove(Move *move);
  /** change turn between players */
  void changeTurn();

  /** serialization methods */
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive &ar, const unsigned version) {
    ar &name;
    ar &pground;
    ar &mode;
    ar &p1;
    ar &p2;
    ar &turn;
    ar &moves;
    ar &index;
    ar &ready;
    cout << version;
  }

 public:
  /** Default contructor */
  Game() {}
  /** new game constructor */
  Game(string name, GameMode mode, int size);
  /** default destructor */
  ~Game();

  /** Playground getter */
  Playground &playground();

  /** Versus mode initialization funtion */
  void setPlayerVs(string name1, Color color, string name2);
  /** AI mode initialization function */
  void setPlayerAi(string name, Color color, Difficulty d);

  /** init of field */
  void init();
  /** who is in turn */
  Color who();

  /** Make move function, if it's possible puts disk and flip disks */
  MoveCons makeMove(int x, int y, int *flipped, bool apply);
  /** check if another move exists or end of game is reached */
  RET existMove();

  /** get next move from AI with simple dificulty */
  RET getAISimple(int &x, int &y);
  /** get next move from AI with hard dificulty */
  RET getAIHard(int &x, int &y);

  /** make move back */
  RET undoMove();
  /** make move forward */
  RET redoMove();

  /** getter for number of moves */
  int getNumOfMoves();
  /** getter for name of this game */
  string getName() const { return this->name; }
  /** getter for player1 */
  Player *getPlayer1() const { return this->p1; }
  /** getter for player2 */
  Player *getPlayer2() const { return this->p2; }
  /** getter for mode of this game */
  GameMode getMode() const { return this->mode; }
};

#endif
