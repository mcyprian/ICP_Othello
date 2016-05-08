/**
 * @file playground.hpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Playground class represents field of disks.
 */

#ifndef PLAYGROUND_HPP
#define PLAYGROUND_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <disk.hpp>

#include <boost/serialization/split_member.hpp>

using namespace std;

/** Class that represents game field */
class Playground {
  int size = 8; /** Size of field */
  Disk** grid;  /** Field pointer */

  /** Serialization logic */
  friend class boost::serialization::access;

  template <typename Archive>
  void load(Archive& ar, const unsigned version) {
    ar& size;
    grid = new Disk*[size * size];
    for (int i = 0; i < size * size; i++) {
      ar& grid[i];
    }
    cout << version;
  }

  template <typename Archive>
  void save(Archive& ar, const unsigned version) const {
    ar& size;
    for (int i = 0; i < size * size; i++) {
      ar& grid[i];
    }
    cout << version;
  }

  BOOST_SERIALIZATION_SPLIT_MEMBER()

 public:
  /** Default constructor */
  Playground() {}
  /** Create contrunctor */
  Playground(int size);
  /** Something like copy constructor */
  Playground(Playground& p);

  /** Default destructor */
  ~Playground();

  void putDisk(int x, int y, Color c);
  void freeDisk(int x, int y);
  Disk*& getDisk(int x, int y);

  RET isValid(int x, int y);

  void print();
  int getSize();
};

#endif