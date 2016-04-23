#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene;

    QGraphicsPixmapItem *cell;
    QGraphicsPixmapItem *white;
    QGraphicsPixmapItem *black;

};

#endif // DIALOG_HPP
