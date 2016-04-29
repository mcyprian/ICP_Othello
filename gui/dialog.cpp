#include <QString>
#include <QIcon>

#include "dialog.hpp"
#include "game_manager.hpp"
#include "ui_dialog.h"

Dialog::Dialog( struct gameData &game_data, GameManager &gm, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    scene(new QGraphicsScene(this))
{
    this->gm = gm;
    this->ui->setupUi(this);

    this->scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->game_data = &game_data;

      // set geometry of object relative to grid size
    int background_size = game_data.grid_size * this->cell_size + 10;
    this->ui->graphicsView->setGeometry(this->width() / 2 - background_size / 2,
                                        160, background_size, background_size);

    this->ui->backward_button_2->setGeometry(300, this->ui->graphicsView->y() + background_size + 20, 95, 81);
    this->ui->forward_button_2->setGeometry(400, this->ui->graphicsView->y() + background_size + 20, 95, 81);
    this->setFixedSize(800, this->ui->forward_button_2->y() + 150);


    // allocate matrix of cells
    for (int i = 0; i < game_data.grid_size; i++)
    {
        QVector<CellLabel*> row;
        for (int j = 0; j < game_data.grid_size; j++)
        {
            row.push_back(new CellLabel(this->ui->graphicsView->x() + 5,
                                        this->ui->graphicsView->y() + 5,
                                        i, j, this->cell_size, this));
        }
        this->ggrid.push_back(row);
    }

    this->setupScene();
}

Dialog::~Dialog()
{
    for (int i = 0; i < this->game_data->grid_size; i++)
    {
        for (int j = 0; j < this->game_data->grid_size; j++)
        {
            delete this->ggrid[i][j];
        }
    }
    delete this->scene;
    delete this->ui;
}

void Dialog::setupScene()
{
    QString background;
    // load wooden background pattern of correct size
    switch (this->game_data->grid_size) {
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
    // TODO images not loaded
    //ui->backward_button->setIcon(QIcon(QPixmap(":/image/images/left_arrow.png")));
    //ui->forward_button->setIcon(QIcon(QPixmap(":/image/images/right_arrow.png")));

    this->scene->addPixmap(QPixmap(":/image/images/" + background));

    // add allocated cells to scene
    for (int i = 0; i < this->game_data->grid_size; i++)
    {
        for (int j = 0; j < this->game_data->grid_size; j++)
        {
            this->scene->addItem(this->ggrid[i][j]->get_disk());
            this->connect(this->ggrid[i][j], SIGNAL(cellSelected(int, int)), this, SLOT(cellSelected(int, int)));
        }
    }

    // load player1 avatar image and name
    this->ui->player1_image->setPixmap(QPixmap(":/image/images/black_avatar.png"));
    this->ui->player1_name->setText(this->game_data->player1);

    if (this->game_data->mode == VERSUS)
        this->setVersus();
    else
        this->setAI();
}

void Dialog::setVersus()
{
    this->ui->player2_image->setPixmap(QPixmap(":/image/images/white_avatar.png"));
    this->ui->player2_name->setText(this->game_data->player2);

}

void Dialog::setAI()
{
    this->ui->player2_image->setPixmap(QPixmap(":/image/images/computer.png"));
    this->ui->player2_name->setText("      AI");
}

void Dialog::cellSelected(int x, int y)
{
    this->ggrid[x][y]->get_disk()->flip();
}
