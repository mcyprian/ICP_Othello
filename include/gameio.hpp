#ifndef GAMEIO_HPP
#define GAMEIO_HPP

#include "game_manager.hpp"

class GameIO {
public:
    GameIO(GameManager *gm);
    ~GameIO() {};
    void updateScore();
    virtual void drawScene() = 0;
    virtual void refreshGrid() = 0;

protected:
    int grid_size;
    GameManager *gm;
    int black_count;
    int white_count;
};

#endif // GameIO
