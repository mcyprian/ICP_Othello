#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "game_manager.hpp"
#include "resources.hpp"

class UserInterface {
public:
    UserInterface() {
        this->gm = new GameManager();
        this->initialized = false;
    }

    ~UserInterface() {
        delete this->gm;
        this->initialized = false;
    }

    virtual void getGameData() = 0;
    virtual void startNewGame() = 0;

protected:
    GameManager* gm;
    bool initialized;
};

#endif
