#include <QString>
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

    this->grid_size = 10;

    int background_size = this->grid_size * this->cell_size + 10;
    this->ui->graphicsView->setGeometry(this->width() / 2 - background_size / 2,
                                        180, background_size, background_size);


    // allocate matrix of cells
    for (int i = 0; i < this->grid_size; i++)
    {
        QVector<CellLabel*> row;
        for (int j = 0; j < this->grid_size; j++)
        {
            row.push_back(new CellLabel(this->ui->graphicsView->x() + 5,
                                        this->ui->graphicsView->y() + 5,
                                        i, j, this->cell_size, this));
        }
        this->ggrid.push_back(row);
    }

    this->setup_scene();
}

Dialog::~Dialog()
{
    for (int i = 0; i < this->grid_size; i++)
    {
        for (int j = 0; j < this->grid_size; j++)
        {
            delete this->ggrid[i][j];
        }
    }
    delete this->scene;
    delete this->ui;
}

void Dialog::setup_scene()
{
    QString background;
    // load wooden background pattern of correct size
    switch (this->grid_size) {
    case 6:
        background = "board6.png";
        break;
    case 8:
        background = "board8.png";
        break;
    case 10:
        background = "board10.png";
        break;
    case 12:
        background = "board12.png";
        break;

    }

    this->scene->addPixmap(QPixmap(":/image/images/" + background));

    // add allocated cells to scene
    for (int i = 0; i < this->grid_size; i++)
    {
        for (int j = 0; j < this->grid_size; j++)
        {
            this->scene->addItem(this->ggrid[i][j]->get_disk());
            this->connect(this->ggrid[i][j], SIGNAL(cell_selected(int, int)), this, SLOT(cell_selected(int, int)));
        }
    }

    // load players avatars images
    this->ui->player1_image->setPixmap(QPixmap(":/image/images/black_avatar.png"));
    this->ui->player2_image->setPixmap(QPixmap(":/image/images/white_avatar.png"));



}

void Dialog::cell_selected(int x, int y)
{
    this->ggrid[x][y]->get_disk()->flip();
}

