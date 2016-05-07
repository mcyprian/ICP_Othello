/**
 * @file commandlineinterface.cpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Implementation of commad-line variant of main interface for creating and
 * loading existing games.
 */

#include <string>

#include "commandlineinterface.hpp"
#include "game_manager.hpp"
#include "cligame.hpp"
#include "resources.hpp"
#include "climenu.hpp"

void CommandLineInterface::mainLoop() { this->startGame(); }

void CommandLineInterface::startGame() {
  while (true) {
    int grid_size;
    bool satisfied = false;
    CLIMenu main(string("Othello"));
    main.addEntry(string("New game"));
    main.addEntry(string("Load game"));
    main.addEntry(string("Delete game"));
    main.addEntry(string("Exit"));
    int option = main.prompt();
    if (option == 0) {  // New game selected
      string name = inputStr("Name");
      if (name.empty()) name = "Game1";
      while (!satisfied) {
        satisfied = false;
        grid_size = inputNum("Grid size (6, 8, 10 or 12)");
        if (grid_size == 6 || grid_size == 8 || grid_size == 10 ||
            grid_size == 12)
          satisfied = true;
        else
          cout << "Invalid grid size: " << grid_size
               << ", insert number 6 8 10 or 12.\n";
      }
      CLIMenu mode_menu(string("Mode"));
      mode_menu.addEntry(string("2 Players"));
      mode_menu.addEntry(string("Versus AI"));
      GameMode mode = static_cast<GameMode>(mode_menu.prompt());
      string player1 = inputStr("Player1 ");
      if (player1.empty()) player1 = "player1";
      if (mode == VERSUS) {
        string player2 = inputStr("Player2 ");
        if (player2.empty()) player2 = "player2";
        this->gm->initNewGame(name, mode, grid_size, player1, BLACK, player2);
      } else {
        CLIMenu difficulty_menu("Difficulty");
        difficulty_menu.addEntry("Easy");
        difficulty_menu.addEntry("Hard");
        Difficulty difficulty =
            static_cast<Difficulty>(difficulty_menu.prompt());
        this->gm->initNewGame(name, mode, grid_size, player1, BLACK,
                              difficulty);
      }
      CLIGame cli_game(this->gm);
      cli_game.runGame();
    } else if (option == 1) {  // Load game selected
      CLIMenu load_menu("Load game");
      vector<string> *loaded = this->gm->getSavedGames();
      if (loaded->size() != 0) {
        for (vector<string>::iterator it = loaded->begin(); it != loaded->end();
             it++) {
          cout << *it;
          load_menu.addEntry(*it);
        }

        int option = load_menu.prompt();
        this->gm->loadGame((*loaded)[option]);
        CLIGame cli_game(this->gm);
        cli_game.runGame();
      } else {
        cout << "Not saved games available.\n";
      }
      delete loaded;
    } else if (option == 2) {  // Delete game
      CLIMenu delete_menu("Delete game");
      vector<string> *loaded = this->gm->getSavedGames();
      if (loaded->size() != 0) {
        for (vector<string>::iterator it = loaded->begin(); it != loaded->end();
             it++) {
          cout << *it;
          delete_menu.addEntry(*it);
        }

        int option = delete_menu.prompt();
        this->gm->removeGame((*loaded)[option]);
      } else {
        cout << "Not saved games available.\n";
      }
      delete loaded;
    } else
      break;
  }
}
