/**
 * @file climenu.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Implementation of simple command-line menu.
 */

#ifndef CLIMENU_HPP
#define CLIMENU_HPP
#include <string>
#include <vector>

using namespace std;

/** Class providing methods to add menu entries and get user's option. */
class CLIMenu {
public:
    /** Stores menu title as an attribute. */
    CLIMenu(string title);
    ~CLIMenu() {}
    /** Adds new entry to the end of vector of entries.
     * @param entry string representation of menu entry
     */
    void addEntry(string entry);
    /** Getter of menu enties vector. */
    vector<string> getEntries() const { return this->entries; }
    /** Prints title of the instance.
     * @title title to be used
     */
    static void printTitle(string title);
    /** Prints menu to stdout and load the selected option.
     * @param title optional title to overwrite title attribute.
     */
    unsigned prompt(string title="");


private:
    string title; /* Default title of the instance. */
    vector<string> entries; /* Vector of menu entries. */
};

/** Reads string from stdin
 * @param title initial message to prompt for input.
 * @return inserted string
 */
string inputStr(string title);

/** Reads number from stdin
 * @param title initial message to prompt for input.
 */
int inputNum(string title);

/** Converts string to number
 * @param data string to be converted
 * @returns converted int or -1 on error
 */
int str_to_number(const string& data);

#endif
