#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "celllabel.hpp"

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
    int grid_size;   //TODO preberat z objektu game
    static const int cell_size = 60;
    QVector<QVector<CellLabel*>> ggrid;

private slots:
    void cell_selected(int x, int y);
};

#endif // DIALOG_HPP
