#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "game.hpp"
#include "resources.hpp"

class UserInterface {
public:
    UserInterface() {
        this->game = nullptr; 
        this->initialized = false;
    }

    ~UserInterface() {
        delete this->game;
    }

    void initGame(GameMode mode, int size, string name1, Color color, Difficulty d) {
        if (this->initialized)
            throw runtime_error("Game can be initialized only once.\n");
        this->game = new Game(mode, size);
        this->game->setPlayer_ai(name1, color, d);
        this->initialized = true;
    }

    void initGame(GameMode mode, int size, string name1, Color color, string name2) {
        if (this->initialized)
            throw runtime_error("Game can be initialized only once.\n");
        this->game = new Game(mode, size);
        this->game->setPlayer_vs(name1, color, name2);
        this->initialized = true;
    }

    virtual void main_loop() = 0;
    virtual void refresh_data() = 0;

private:
    Game *game;
    bool initialized;
};

#endif
