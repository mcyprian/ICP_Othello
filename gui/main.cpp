#include "mainwindow.hpp"
#include "dialog.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Dialog d;
    d.show();

    return a.exec();
}
