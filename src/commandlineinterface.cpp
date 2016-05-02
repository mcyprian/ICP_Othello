#include <iostream>
#include <sstream>
#include <string>


#include "../include/commandlineinterface.hpp"
#include "../include/resources.hpp"

CLIMenu::CLIMenu(string title) {
    this->title = title;
}

void CLIMenu::addEntry(string entry) {
    this->entries.push_back(entry);
}

void CLIMenu::printTitle(string title) {
    cout << "-----------------------\n" << title << ":\n-----------------------\n\n";
}

unsigned CLIMenu::prompt() {
    unsigned i;
    string choice;
    int num_choice;
    bool satisfied = false;

    while (!satisfied) {
        satisfied = false;
        CLIMenu::printTitle(this->title);
        for (i = 0; i < this->entries.size(); i++) {
            cout << i << ". " << this->entries[i] << endl;
        }
        cin >> choice;
        try {
            num_choice = str_to_number(choice);
            if (num_choice < 0 || static_cast<unsigned>(num_choice) >= this->entries.size()) 
                throw runtime_error("No entry with inserted number.");
            satisfied = true;
        } catch (const runtime_error &error) {
            cout << "Invalid option, insert number of entry.\n";
            continue;
        }
    }
    return num_choice;
}


string inputStr(string title) {
    string input;
    CLIMenu::printTitle(title);
    cin >> input;
    return input;
}

int inputNum(string title) {
    string input;
    int num_input;
    CLIMenu::printTitle(title);
    cin >> input;
    try {
        num_input = str_to_number(input);
    } catch (const runtime_error &error) {
        return -1;
    }
    return num_input;
}

int str_to_number(const string& data) {
    if (!data.empty()) {
    int data_number;
    istringstream iss(data);
    iss >> dec >> data_number;
    if (iss.fail())
        throw runtime_error("Failed to convert data number to int.");
        return data_number;
    }
    throw runtime_error("Empty string can not be converted to int");
}

void CommandLineInterface::mainLoop() {
    int grid_size;
    bool satisfied = false;
    CLIMenu main(string("Othello"));
    main.addEntry(string("New game"));
    main.addEntry(string("Load game"));
    if (main.prompt() == 0) { // New game selected
        string name = inputStr("Name");
        while (!satisfied) {
            satisfied = false;
            grid_size = inputNum("Grid size (6, 8, 10 or 12)");
            if (grid_size == 6 || grid_size == 8 || grid_size == 10 || grid_size == 12)
                satisfied = true;
            else
                cout << "Invalid grid size: " << grid_size << ", insert number 6 8 10 or 12.\n";
        }
        CLIMenu mode_menu(string("Mode"));
        mode_menu.addEntry(string("2 Players"));
        mode_menu.addEntry(string("Versus AI"));
        GameMode mode = static_cast<GameMode>(mode_menu.prompt());
        if (mode == VERSUS) {
            string player1 = inputStr("Player1 ");
            string player2 = inputStr("Player2 ");
        } else {
            string player1 = inputStr("Player1 ");
            CLIMenu difficulty_menu("Difficulty");
            difficulty_menu.addEntry("Easy");
            difficulty_menu.addEntry("Hard");
            Difficulty difficulty = static_cast<Difficulty>(difficulty_menu.prompt());
        }
    } else { // Load game selected
    ;}
}
