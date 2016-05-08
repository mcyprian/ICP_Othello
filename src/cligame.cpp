/**
 * @file cligame.cpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Implementation of commad-line variant of user interface for the specific game
 * after initialization.
 */

#include <iostream>
#include <stdexcept>

#include "cligame.hpp"
#include "climenu.hpp"

CLIGame::CLIGame(GameManager *gm) : GameIO(gm) { this->drawScene(); }

void CLIGame::runGame() {
  CLIMenu run_menu("");
  bool exit = false;
  int x;
  int y;

  run_menu.addEntry("Make move");
  run_menu.addEntry("Save game");
  run_menu.addEntry("Backward");
  run_menu.addEntry("Forward");
  run_menu.addEntry("Exit");

  while (!exit) {
    string active_player =
        this->gm->getGame().who()
            ? this->gm->getGame().getPlayer1()->name + " (BLACK)"
            : this->gm->getGame().getPlayer2()->name + " (WHITE)";
    string title = "Active player: " + active_player;
    this->refreshGrid();
    if (this->gm->getGame().existMove() == FAILURE) {
      this->updateScore();
      string winner = this->black_count < this->white_count
                          ? this->gm->getGame().getPlayer1()->name
                          : this->gm->getGame().getPlayer2()->name;
      cout << "END OF THE GAME, player: " << winner << "have won!\n";
    }
    switch (run_menu.prompt(title)) {
      case 0:
        x = inputNum("insert X");
        y = inputNum("insert Y");
        if (x < 0 || x > this->grid_size || y < 0 || y > grid_size ||
            (this->gm->getGame().makeMove(y, x, nullptr, true) != MOVED))
          cout << "Invalid move!\n";
        else if (this->gm->getGame().getMode() == AI)
          this->AITurn();
        break;
      case 1:
        this->gm->saveGame();
        cout << "Game saved.\n";
        break;
      case 2:
        if (this->gm->getGame().undoMove() == FAILURE)
          cout << "Warning: can't move backward!\n";
        break;
      case 3:
        if (this->gm->getGame().redoMove() == FAILURE)
          cout << "Warning: can't move forward!\n";
        break;
      case 4:
        exit = true;
        break;
    }
  }
}

void CLIGame::AITurn() {
  string active_player =
      this->gm->getGame().who()
          ? this->gm->getGame().getPlayer1()->name + " (BLACK)"
          : this->gm->getGame().getPlayer2()->name + " (WHITE)";
  cout << "Active player: " + active_player << endl;
  this->refreshGrid();

  int ai_x = 0;
  int ai_y = 0;

  if (this->gm->getGame().getPlayer2()->dif == HARD) {
    cout << "HARD\n";
    this->gm->getGame().getAIHard(ai_x, ai_y);
  } else {
    cout << "EASY\n";
    this->gm->getGame().getAISimple(ai_x, ai_y);
  }

  cout << "ai_x :" << ai_x << " ai_y: " << ai_y << endl;
  if (this->gm->getGame().makeMove(ai_x, ai_y, nullptr, true) != MOVED)
    cerr << "WARNING: AI move failed\n";
}

void CLIGame::drawScene() {
  this->updateScore();
  cout << "------------------- " << this->gm->getGame().getName()
       << " -------------------\n";
  cout << this->gm->getGame().getPlayer1()->name
       << " (black), score: " << this->black_count << endl;
  if (this->gm->getGame().getMode() == VERSUS)
    cout << this->gm->getGame().getPlayer2()->name
         << " (white), score: " << this->white_count << endl;
  else {
    string level = this->gm->getGame().getPlayer2()->dif ? "HARD" : "EASY";
    cout << "AI (" + level + ") (white), score: " << this->white_count << endl;
  }
  cout << "------------------------------------------\n";
}

void CLIGame::refreshGrid() {
  int i;
  int j;
  Disk *current;
  this->drawScene();
  cout << "    ";
  for (i = 0; i < this->grid_size; i++) cout << i << " ";
  cout << "\n";
  cout << "  ╔";
  for (i = 0; i < 2 * this->grid_size + 1; i++) cout << "═";
  cout << "╗\n";
  for (i = 0; i < this->grid_size; i++) {
    cout << i << " ║ ";
    for (j = 0; j < this->grid_size; j++) {
      current = this->gm->getGame().playground().getDisk(i, j);
      if (current == nullptr)
        cout << "  ";
      else {
        if (current->getColor() == BLACK)
          cout << "B ";
        else
          cout << "W ";
      }
    }
    cout << "║\n";
  }
  cout << "  ╚";
  for (i = 0; i < 2 * this->grid_size + 1; i++) cout << "═";
  ;
  cout << "╝\n";
}
