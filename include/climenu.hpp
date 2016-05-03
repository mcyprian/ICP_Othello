#ifndef CLIMENU_HPP
#define CLIMENU_HPP
#include <string>
#include <vector>

using namespace std;

class CLIMenu {
public:
    CLIMenu(string title);
    CLIMenu(string title, vector<string> entries);
    ~CLIMenu() {}
    void addEntry(string entry);
    vector<string> getEntries() const { return this->entries; }
    static void printTitle(string title);
    unsigned prompt(string title="");


private:
    string title;
    vector<string> entries;
};

string inputStr(string title);
int inputNum(string title);
int str_to_number(const string& data);

#endif
