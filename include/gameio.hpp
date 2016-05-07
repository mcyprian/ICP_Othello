/**
 * @file gameio.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Abstract class of the interface for the specific game after initialization.
 */

#ifndef GAMEIO_HPP
#define GAMEIO_HPP

#include "game_manager.hpp"

/** Class containing common methods for GUI and CLI subclasses. */
class GameIO {
 public:
  /** Constructor sotres GameManager instance and grid_size to the attributes */
  GameIO(GameManager *gm);
  ~GameIO(){};
  /** Gets current point of players, sets attributes black_count and
   * white_count. */
  void updateScore();
  /** Abstract method for scene drawing. */
  virtual void drawScene() = 0;
  /** Abstract method for refreshment of the grid acording to game attribute
    * of GameManager instance/
    */
  virtual void refreshGrid() = 0;

 protected:
  int grid_size;   /* Size of the board. */
  GameManager *gm; /* Pointer to GameManager instance. */
  int black_count; /* Current number of black disks on the grid. */
  int white_count; /* Current number of white disks on the grid. */
};

#endif  // GameIO
