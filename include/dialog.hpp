#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "gameio.hpp"
#include "celllabel.hpp"
#include "game_manager.hpp"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog, public GameIO
{
    Q_OBJECT

public:
    explicit Dialog(GameManager *gm, QWidget *parent = 0);
    ~Dialog();
    void drawScene();
    void refreshGrid();
    void setVersus();
    void setAI();
    void setTurn(Color color);

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene;
    static const int cell_size = 60;
    QVector<QVector<CellLabel*>> ggrid;

private slots:
    void cellSelected(int x, int y);
    void cellMoved(int x, int y);
    void cellLeft(int x, int y);
    void on_forward_button_clicked();
    void on_backward_button_clicked();
};

#endif // DIALOG_HPP
