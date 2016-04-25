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

    void newGame(GameMode mode, int size, string name1, Color color, Difficulty d) {
        this->gm->initNewGame(mode, size, name1, color, d);
        this->initialized = true;
    }

    void initGame(GameMode mode, int size, string name1, Color color, string name2) {
        this->gm->initNewGame(mode, size, name1, color, name2);
        this->initialized = true;
    }

    void load_game(string name){

    }

    void save_game(){
        
    }

    virtual void main_loop() = 0;
    virtual void refresh_data() = 0;

private:
    GameManager* gm;
    bool initialized;
};

#endif
