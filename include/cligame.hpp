#ifndef CLIGAME_HPP
#define CLIGAME_HPP

#include "game_manager.hpp"

class CLIGame {
public:
    CLIGame(GameManager *gm);
    ~CLIGame() {};
    void runGame();
    void updateScore();
    void drawScene();
    void refreshGrid();

private:
    int grid_size;
    GameManager *gm;
    int black_count;
    int white_count;
};

#endif // CLIGAME_HPP

