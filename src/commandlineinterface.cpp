#include <string>

#include "commandlineinterface.hpp"
#include "game_manager.hpp"
#include "cligame.hpp"
#include "resources.hpp"
#include "climenu.hpp"



void CommandLineInterface::mainLoop() {
    this->startGame();
}

void CommandLineInterface::startGame() {
    int grid_size;
    bool satisfied = false;
    CLIMenu main(string("Othello"));
    main.addEntry(string("New game"));
    main.addEntry(string("Load game"));
    if (main.prompt() == 0) { // New game selected
        string name = inputStr("Name");
        if (name.empty())
            name = "Game1";
        while (!satisfied) {
            satisfied = false;
            grid_size = inputNum("Grid size (6, 8, 10 or 12)");
            if (grid_size == 6 || grid_size == 8 || grid_size == 10 || grid_size == 12)
                satisfied = true;
            else
                cout << "Invalid grid size: " << grid_size << ", insert number 6 8 10 or 12.\n";
        }
        CLIMenu mode_menu(string("Mode"));
        mode_menu.addEntry(string("2 Players"));
        mode_menu.addEntry(string("Versus AI"));
        GameMode mode = static_cast<GameMode>(mode_menu.prompt());
        string player1 = inputStr("Player1 ");
        if (player1.empty())
            player1 = "player1";
        if (mode == VERSUS) {
            string player2 = inputStr("Player2 ");
            if (player2.empty())
                player2 = "player2";
            this->gm->initNewGame(name, mode, grid_size, player1, BLACK, player2);
        } else {
            CLIMenu difficulty_menu("Difficulty");
            difficulty_menu.addEntry("Easy");
            difficulty_menu.addEntry("Hard");
            Difficulty difficulty = static_cast<Difficulty>(difficulty_menu.prompt());
            this->gm->initNewGame(name, mode, grid_size, player1, BLACK, difficulty);
        }
        CLIGame cli_game(this->gm);
        cli_game.runGame();
    } else { // Load game selected
    ;}
}
