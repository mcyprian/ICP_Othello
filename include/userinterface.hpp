#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "game_manager.hpp"
#include "resources.hpp"

class UserInterface {
public:
    UserInterface() {
        this->gm = new GameManager();
    }

    ~UserInterface() {
        delete this->gm;
    }

    virtual void mainLoop() = 0;


protected:
    GameManager* gm;
};

#endif
