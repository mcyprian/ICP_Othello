#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "celllabel.hpp"
#include "game_manager.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(GameManager *gm, QWidget *parent = 0);
    ~Dialog();
    void drawScene();
    void setVersus();
    void setAI();
    void refreshGrid();
    void setTurn(Color color);

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene;
    int grid_size;
    static const int cell_size = 60;
    QVector<QVector<CellLabel*>> ggrid;
    GameManager *gm;

private slots:
    void cellSelected(int x, int y);
    void cellMoved(int x, int y);
    void cellLeft(int x, int y);
};

#endif // DIALOG_HPP
