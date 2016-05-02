#ifndef COMMANDLINEINTERFACE_HPP
#define COMMANDLINEINTERFACE_HPP

#include "userinterface.hpp"

class CommandLineInterface : public UserInterface {
public:
    CommandLineInterface() {};
    ~CommandLineInterface() {};
    void mainLoop();
    void startGame();


};

#endif
