#include "dialog.hpp"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPixmap board(":/image/images/board.png");
    QPixmap black_stone(":/image/images/white_stone.png");
    QPixmap white_stone(":/image/images/black_stone.png");

    cell = scene->addPixmap(board);

    white = scene->addPixmap(white_stone);
    white->setPos(6*79.25+10+6, 6*79.25+10+6);

    black = scene->addPixmap(black_stone);
    black->setPos(79.25+10+1, 79.25+10+1);

}
Dialog::~Dialog()
{
    delete ui;
    delete scene;
}
