#include <QApplication>

#include "mainwindow.hpp"
#include "dialog.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Dialog d;
    d.main_loop();

    return a.exec();
}
