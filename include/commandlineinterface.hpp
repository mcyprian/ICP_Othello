#ifndef COMMANDLINEINTERFACE_HPP
#define COMMANDLINEINTERFACE_HPP

#include <string>
#include <vector>

#include "userinterface.hpp"

using namespace std;

class CLIMenu {
public:
    CLIMenu(string title);
    CLIMenu(string title, vector<string> entries);
    ~CLIMenu() {}
    void addEntry(string entry);
    vector<string> getEntry() const { return this->entries; }
    static void printTitle(string title);
    unsigned prompt();


private:
    string title;
    vector<string> entries;
};

string inputStr(string title);
int inputNum(string title);
int str_to_number(const string& data);


class CommandLineInterface : public UserInterface {
public:
    CommandLineInterface() {};
    ~CommandLineInterface() {};
    void mainLoop();


};
#endif
