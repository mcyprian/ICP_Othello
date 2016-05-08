/**
 * @file disk.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Disk class represents one disk in game.
 */

#ifndef DISK_HPP
#define DISK_HPP

#include <resources.hpp>

#include <boost/serialization/access.hpp>

/** Class containts methotds to create Disk*/
class Disk {
  /** Color of Disk*/
  Color color;

  /** Serialization logic*/
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive& ar, const unsigned version) {
    ar& color;
    if (version != 0) return;
  }

 public:
  /** Default contructor of Disk*/
  Disk() {}

  /** Fill up Constructor*/
  Disk(Color c) { this->color = c; }

  /** Flip disk to oposite color*/
  void flip() {
    if (this->color == WHITE)
      this->color = BLACK;
    else
      this->color = WHITE;
  }

  /** Getter for private color*/
  Color getColor() { return this->color; }
};

#endif
