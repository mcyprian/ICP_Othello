#include "gameio.hpp"

GameIO::GameIO(GameManager *gm) {
    this->gm = gm;
    this->grid_size = this->gm->getGame().playground().getSize();
}

void GameIO::updateScore() {
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

