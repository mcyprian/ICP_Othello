#include <iostream>
#include <sstream>
#include <string>

#include "climenu.hpp"

CLIMenu::CLIMenu(string title) {
    this->title = title;
}

void CLIMenu::addEntry(string entry) {
    this->entries.push_back(entry);
}

void CLIMenu::printTitle(string title="") {
    cout << "-----------------------\n" << title << ":\n-----------------------\n";
}

unsigned CLIMenu::prompt(string title) {
    unsigned i;
    string choice;
    int num_choice;
    bool satisfied = false;
    if (title.empty())
        title = this->title;

    while (!satisfied) {
        satisfied = false;
        CLIMenu::printTitle(title);
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
