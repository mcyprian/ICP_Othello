/**
 * @file main.cpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Main function of graphical form of user interface.
 */

#include <QApplication>

#include "mainwindow.hpp"
#include "dialog.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;
    main_window.mainLoop();

    return a.exec();
}
