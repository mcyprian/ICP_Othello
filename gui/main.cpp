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
