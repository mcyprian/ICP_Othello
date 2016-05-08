/**
 * @file game_manager.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * GameManager class represents management of games, loading, saving....
 */

#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <map>
#include <vector>
#include <string>
#include <game.hpp>

#include <boost/serialization/string.hpp>
#include <boost/serialization/map.hpp>

/** Class for manage of our games */
class GameManager {
  /** Actualy played game */
  Game* game;
  /** Initialization flag */
  bool initialized;
  /** Map of saved games */
  std::map<string, Game*> saved;

  /** Serialization logic */
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive& ar, const unsigned version) {
    ar& saved;
    cout << version;
  }

 public:
  /** Default contructor */
  GameManager();
  /** Default destructor */
  ~GameManager();

  /** game accesser */
  Game& getGame();

  /** initialization function for AI mode */
  void initNewGame(string game_name, GameMode mode, int size, string name1,
                   Color color, Difficulty d);

  /** initialization function for Versus mode */
  void initNewGame(string game_name, GameMode mode, int size, string name1,
                   Color color, string name2);

  /** save actualy played game into map */
  void saveGame();
  /** load game by name */
  void loadGame(string name);
  /** remove game from map */
  void removeGame(string name);

  /** serialize map */
  void serialize(string filename);
  /** deserialize map */
  void deserialize(string filename);
  /** Returns vector of  saved game names */
  vector<string>* getSavedGames();
};

#endif
