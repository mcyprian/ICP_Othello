#include <iostream>

#include "cligame.hpp"
#include "climenu.hpp"

CLIGame::CLIGame(GameManager *gm) {
    this->gm = gm;
    this->grid_size = this->gm->getGame().playground().getSize();
    this->drawScene();
}

void CLIGame::updateScore() {
    this->black_count = 0;
    this->white_count = 0;
    Disk *current;

    for (int i = 0; i < this->grid_size; i++)
        for (int j = 0; j < this->grid_size; j++) {
            current = this->gm->getGame().playground().getDisk(i, j);
            if (current != nullptr)
                current->getColor() != BLACK ? this->black_count++ : this->white_count++;
        }
}

void CLIGame::drawScene() {
    this->updateScore();
    cout << "------------------- " << this->gm->getGame().getName() << " -------------------\n";
    cout << this->gm->getGame().getPlayer1()->name << " (black), score: " << this->black_count << endl;
    if (this->gm->getGame().getMode() == VERSUS)
        cout << this->gm->getGame().getPlayer2()->name << " (white), score: " << this->white_count << endl;
    else {
        string level = this->gm->getGame().getPlayer2()->dif ? "HARD" : "EASY";
        cout << "AI (" +  level + ") (white), score: " << this->white_count << endl;
    }
    this->refreshGrid();
}


void CLIGame::refreshGrid() {
    int i;
    int j;
    Disk *current;

    cout << "╔";
    for (i = 0; i < 2 * this->grid_size + 1; i++)
        cout << "═";
    cout << "╗\n";
    for (i = 0; i < this->grid_size; i++) {
        cout << "║ ";
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
    cout << "╚";
    for (i = 0; i < 2 * this->grid_size + 1; i++)
        cout << "═";;
    cout << "╝\n";
}

