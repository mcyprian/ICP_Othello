/**
 * @file commandlineinterface.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Commad-line variant of main interface for creating and loading existing games.
 */

#ifndef COMMANDLINEINTERFACE_HPP
#define COMMANDLINEINTERFACE_HPP

#include "userinterface.hpp"

/** Contains methods to create menus and start created or selected game. */
class CommandLineInterface : public UserInterface {
public:
    /** Empty constructor */
    CommandLineInterface() {};
    ~CommandLineInterface() {};
    /** Method copying common interface. */
    void mainLoop();
    /** Initalized main menu, gets options from user, creates
     * object cligame for selected game.
     */
    void startGame();
};

#endif
