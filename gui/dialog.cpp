#include <QString>
#include <QIcon>
#include <iostream>

#include "dialog.hpp"
#include "disk.hpp"
#include "ui_dialog.h"

Dialog::Dialog(GameManager *gm, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    scene(new QGraphicsScene(this))
{
    this->ui->setupUi(this);

    this->gm = gm;
    this->scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    this->grid_size = this->gm->getGame().playground().getSize();

    // set geometry of object relative to grid size
    int background_size =  this->grid_size * this->cell_size + 10;
    this->ui->graphicsView->setGeometry(this->width() / 2 - background_size / 2,
                                        160, background_size, background_size);

    this->ui->backward_button->setGeometry(300, this->ui->graphicsView->y() + background_size + 20, 95, 81);
    this->ui->forward_button->setGeometry(400, this->ui->graphicsView->y() + background_size + 20, 95, 81);
    this->setFixedSize(800, this->ui->forward_button->y() + 150);


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

    this->drawScene();
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

void Dialog::drawScene()
{
    this->ui->game_name->setText(QString::fromStdString(this->gm->getGame().getName()));
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
    // TODO images not loaded
    //ui->backward_button->setIcon(QIcon(QPixmap(":/image/images/left_arrow.png")));
    //ui->forward_button->setIcon(QIcon(QPixmap(":/image/images/right_arrow.png")));

    this->ui->pl1_turn->setPixmap(QPixmap(":/image/images/black_stone.png"));
    this->ui->pl2_turn->setPixmap(QPixmap(":/image/images/white_stone.png"));
    this->ui->pl1_turn->show();
    this->ui->pl2_turn->show();

    this->scene->addPixmap(QPixmap(":/image/images/" + background));

    // add allocated cells to scene
    for (int i = 0; i < this->grid_size; i++)
    {
        for (int j = 0; j < this->grid_size; j++)
        {
            this->scene->addItem(this->ggrid[i][j]->getDisk());
            this->connect(this->ggrid[i][j], SIGNAL(cellSelected(int, int)), this, SLOT(cellSelected(int, int)));
            this->connect(this->ggrid[i][j], SIGNAL(cellMoved(int, int)), this, SLOT(cellMoved(int, int)));
            this->connect(this->ggrid[i][j], SIGNAL(cellLeft(int, int)), this, SLOT(cellLeft(int, int)));
        }
    }

    // load player1 avatar image and name
    this->ui->player1_image->setPixmap(QPixmap(":/image/images/black_avatar.png"));
    this->ui->player1_name->setText(QString::fromStdString(this->gm->getGame().getPlayer1()->name));

    if (this->gm->getGame().getMode() == VERSUS)
        this->setVersus();
    else
        this->setAI();
    this->refreshGrid();
}

void Dialog::setVersus()
{
    this->ui->player2_image->setPixmap(QPixmap(":/image/images/white_avatar.png"));
    this->ui->player2_name->setText(QString::fromStdString(this->gm->getGame().getPlayer2()->name));

}

void Dialog::setAI()
{
    this->ui->player2_image->setPixmap(QPixmap(":/image/images/computer.png"));
    QString level = this->gm->getGame().getPlayer2()->dif ? "HARD" : "EASY";
    this->ui->player2_name->setText("AI (" + level + ")");
}

void Dialog::cellSelected(int x, int y)
{
    enum MoveCons ret;
    cout << "X: " << x << " Y: " << y << endl;
    ret = this->gm->getGame().makeMove(x, y, nullptr, true);
    cout << "Move: " << ret << endl;
    this->refreshGrid();
    if (this->gm->getGame().existMove() == FAILURE) cout << "there is no other move" << endl;

}

void Dialog::cellMoved(int x, int y)
{
   
    GUIDisk *current = this->ggrid[x][y]->getDisk();
    if ((this->gm->getGame().makeMove(x, y, nullptr, false)) == MOVED){
        current->setColor(this->gm->getGame().who(), true);
        current->setVisible(true);
    } 
}

void Dialog::cellLeft(int x, int y)
{
    
    GUIDisk *current = this->ggrid[x][y]->getDisk();
    if (current->isTransparent())
        current->setVisible(false);
   
}

void Dialog::refreshGrid()
{
    Disk *current;
    int black_count = 0;
    int white_count = 0;

    for (int i = 0; i < this->grid_size; i++)
    {
        for (int j = 0; j < this->grid_size; j++)
        {
            current = this->gm->getGame().playground().getDisk(i, j);
            if (current == nullptr)
               this->ggrid[i][j]->getDisk()->setVisible(false);
            else {
                this->ggrid[i][j]->getDisk()->setVisible(true);
                this->ggrid[i][j]->getDisk()->setColor(current->getColor(), false);
                current->getColor() != BLACK ? black_count++ : white_count++;
            }
        }
    }
    this->setTurn(this->gm->getGame().who());
    this->ui->player1_score->setText(QString::number(black_count));
    this->ui->player2_score->setText(QString::number(white_count));

}

void Dialog::setTurn(Color color)
{
    if ( color != BLACK) {
        this->ui->pl1_turn->setVisible(true);
        this->ui->pl2_turn->setVisible(false);
    } else {
        this->ui->pl1_turn->setVisible(false);
        this->ui->pl2_turn->setVisible(true);
    }

}

void Dialog::on_forward_button_clicked()
{
    if (this->gm->getGame().redoMove() == FAILURE)
        cout << "Invalid redo\n";
    this->refreshGrid();
}

void Dialog::on_backward_button_clicked()
{
    if (this->gm->getGame().undoMove() == FAILURE)
        cout << "Invalid undo\n";
    this->refreshGrid();

}
