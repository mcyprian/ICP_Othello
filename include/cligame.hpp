/**
 * @file cligame.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Commad-line variant of user interface for the specific game after
 * initialization.
 */

#ifndef CLIGAME_HPP
#define CLIGAME_HPP

#include "game_manager.hpp"
#include "gameio.hpp"

/** Contains methods of command line output of the initialized game. */
class CLIGame : public GameIO {
 public:
  /** Constructor drawing the scene for the first time.
   * @param gm pointer to game_manager object.
   */
  CLIGame(GameManager *gm);
  ~CLIGame(){};
  /** Creates runtime menu, prints actual state of the game, communicates
   * with game manager object.
   */
  void runGame();
  /** Prints actual game info in text form to stdout. */
  void drawScene();
  /** Prints actual state of the grid to stdout. */
  void refreshGrid();
  /** Simulates turn of AI. */
  void AITurn();
};

#endif  // CLIGAME_HPP
