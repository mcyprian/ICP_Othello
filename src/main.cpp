/**
 * @file rmain.cpp
 * @author Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * This file is only for testing reason
 */

#include <iostream>

#include <game_manager.hpp>

using namespace std;

int main() {
  GameManager gm;
  gm.initNewGame("MyGame", VERSUS, 10, "player", WHITE, SIMPLE);
  gm.getGame().playground().print();
  cout << "----------------------" << endl;
  if (gm.getGame().makeMove(4, 3, nullptr, true) == CANNOT_PUT)
    cout << "zle suradnice" << endl;
  else
    cout << "dobre suradnice" << endl;
  gm.getGame().playground().print();
  if (gm.getGame().makeMove(3, 3, nullptr, true) == CANNOT_PUT)
    cout << "zle suradnice" << endl;
  else
    cout << "dobre suradnice" << endl;
  gm.getGame().playground().print();
  return 0;
}
