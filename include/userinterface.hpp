/**
 * @file userinterface.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Abstract interface of components containing navigation menu of the game.
 */

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "game_manager.hpp"
#include "resources.hpp"

/** Abstract base class storing GameManager instance. */
class UserInterface {
 public:
  /** Constractor creates new instance of GameManager and deserialize games. */
  UserInterface() {
    this->gm = new GameManager();
    try {
      this->gm->deserialize("data.bin");
    } catch (exception& e) {
      cerr << "Warning: Can't open archive file\n";
    }
  }
  /** Serialize games and deletes instance of GameManager. */
  ~UserInterface() {
    this->gm->serialize("data.bin");
    delete this->gm;
  }

  /** Runs infinit loop of user interface
   */
  virtual void mainLoop() = 0;

 protected:
  GameManager* gm; /** Pointer to GameManager instance. */
};

#endif
