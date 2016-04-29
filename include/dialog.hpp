#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "celllabel.hpp"
#include "userinterface.hpp"
#include "mainwindow.hpp"
#include "graphicaluserinterface.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    Dialog( struct gameData &game_data, GameManager &gm, QWidget *parent = 0);
    ~Dialog();
    void mainLoop() { this->show(); }
    void refreshData() {}
    void setupScene();
    void setVersus();
    void setAI();

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene;
    int grid_size;   //TODO preberat z objektu game
    static const int cell_size = 60;
    QVector<QVector<CellLabel*>> ggrid;
    GameManager gm;
    struct gameData *game_data;

private slots:
    void cellSelected(int x, int y);

};

#endif // DIALOG_HPP
