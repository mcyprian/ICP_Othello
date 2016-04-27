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

namespace Ui {
class Dialog;
}

class Dialog : public QDialog, public UserInterface
{
    Q_OBJECT

public:
    explicit Dialog(struct game_data game_data, QWidget *parent = 0);
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
    struct game_data game_data;

private slots:
    void cellSelected(int x, int y);

};

#endif // DIALOG_HPP
