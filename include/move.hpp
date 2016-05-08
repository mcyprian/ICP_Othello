/**
 * @file move.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Move class represents simply one move in game.
 */

#ifndef MOVE_HPP
#define MOVE_HPP

#include <vector>
#include <boost/serialization/vector.hpp>

using namespace std;

/** Class that carries information about coordinates */
class Coord {
  /** Serialization logic */
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive& ar, const unsigned version) {
    ar& x& y;
    if (version != 0) return;
  }

 public:
  /** member x */
  int x;
  /** member y */
  int y;

  /** Default contructor */
  Coord() {}
  /** fill up contructor */
  Coord(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

/** Class that represents move as vector of Coord */
class Move {
  /** coord x of move */
  int x;
  /** coord y of move */
  int y;
  /** vector of moves that have to flip */
  vector<Coord*> diff;

  /** serialization logic */
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive& ar, const unsigned version) {
    ar& x& y& diff;
    (void)version;
  }

 public:
  /** Default constructor */
  Move() {}
  /** fill up constructor */
  Move(int x, int y) {
    this->x = x;
    this->y = y;
  }

  /** destructor */
  ~Move() {
    for (auto c : diff) delete c;
  }
  /** add coord with change to vector */
  void addChange(int x, int y) { this->diff.push_back(new Coord(x, y)); }

  /** get number of flipped disks in move */
  int getFlipped() { return this->diff.size(); }

  /** member x getter */
  int getX() { return this->x; }

  /** member y getter */
  int getY() { return this->y; }

  /** vector getter */
  vector<Coord*>& getCoords() { return diff; }
};
#endif
