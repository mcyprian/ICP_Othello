#include "dialog.hpp"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    scene(new QGraphicsScene(this))
{
    this->ui->setupUi(this);

    this->scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->setup_scene();
}

Dialog::~Dialog()
{
    delete this->playground;
    delete this->scene;
    delete this->ui;
}

void Dialog::setup_scene()
{
    this->playground = new GUIPlayground(8);
    this->scene->addItem(playground);

    for (int i = 0; i < this->playground->size; i++)
    {
        for (int j = 0; j < this->playground->size; j++)
        {
            scene->addItem(this->playground->ggrid[i][j]);
        }
    }

    this->playground->ggrid[0][5]->setVisible(false);
    this->playground->ggrid[3][3]->flip();
}
