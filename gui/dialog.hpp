#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "guiplayground.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
     void setup_scene();

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene;

    GUIPlayground *playground;

};

#endif // DIALOG_HPP
