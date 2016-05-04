#ifndef CLIGAME_HPP
#define CLIGAME_HPP

#include "game_manager.hpp"
#include "gameio.hpp"

class CLIGame : public GameIO {
public:
    CLIGame(GameManager *gm);
    ~CLIGame() {};
    void runGame();
    void drawScene();
    void refreshGrid();
};

#endif // CLIGAME_HPP

