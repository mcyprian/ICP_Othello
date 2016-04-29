#include <QApplication>

#include "mainwindow.hpp"
#include "dialog.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GraphicalUserInterface gui;
    gui.getGameData();

    return app.exec();
}
