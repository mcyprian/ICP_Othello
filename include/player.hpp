/**
 * @file player.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Player class represents one player in the game.
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <resources.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

/** Class that represents player in game */
class Player {
  /** serialization logic */
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive& ar, const unsigned version) {
    ar& name;
    ar& color;
    ar& dif;
    cout << version;
  }

 public:
  /** Name of player */
  string name;
  /** Color that represents him */
  Color color;
  /** Difficulty of player, it's important for AI player */
  Difficulty dif;

  /** Default constructor */
  Player() {}
  /** fill up contructor */
  Player(string name, Color color, Difficulty d = NONE) {
    this->name = name;
    this->color = color;
    this->dif = d;
  }

  /** Default destructor */
  ~Player() {}
};

#endif