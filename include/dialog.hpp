#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "celllabel.hpp"
#include "mainwindow.hpp"
#include "game_manager.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(GameManager *gm, struct gameData game_data, QWidget *parent = 0);
    ~Dialog();
    void setupScene();
    void setVersus();
    void setAI();
    void refreshGrid();

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene;
    int grid_size;   //TODO preberat z objektu game
    static const int cell_size = 60;
    QVector<QVector<CellLabel*>> ggrid;
    struct gameData game_data;
    GameManager *gm;

private slots:
    void cellSelected(int x, int y);

};

#endif // DIALOG_HPP
