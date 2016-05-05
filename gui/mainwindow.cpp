#include "mainwindow.hpp"
#include "dialog.hpp"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->widget->setHidden(true);
    this->ui->logo_label->setPixmap(QPixmap(":/image/images/logo.png"));
    this->ui->logo_label->show();
    this->ui->stackedWidget->setCurrentIndex(0);

    QStandardItem *Game1 = new QStandardItem("Game1");
    QStandardItem *Game2 = new QStandardItem("Game2");
    QStandardItemModel *ListModel = new QStandardItemModel();
    ListModel->appendRow(Game1);
    ListModel->appendRow(Game2);
    this->ui->listView->setModel(ListModel);
}

MainWindow::~MainWindow()
{
    delete this->ui;
}


void MainWindow::on_startgame_clicked()
{
    int grid_size;
    GameMode mode;
    Difficulty difficulty;
    QString player1;
    QString player2;
    QString name;

    name = (this->ui->game_name_entry->text());
    if (name == "Insert name")
        name = "Game1";
    grid_size = (this->ui->buttonGroup->checkedId()) * -2 + 2;
    player1 = this->ui->pl1_name->text();
    if (player1 == "Insert name")
        player1 =  "Player1";
    if (this->ui->mode_2players->isChecked()) {
        mode = VERSUS;
        player2 = this->ui->pl2_name->text();
        if (player2 == "Insert name")
            player2 = "Player2";
    } else {
        mode = AI;
        difficulty = (this->ui->pl2_radio_easy->isChecked()) ? SIMPLE : HARD;
    }
    if (mode == VERSUS)
        this->gm->initNewGame(name.toStdString(), mode, grid_size, player1.toStdString(), BLACK, player2.toStdString());
    else
        this->gm->initNewGame(name.toStdString(), mode, grid_size, player1.toStdString(), BLACK, difficulty);

    Dialog d(this->gm, 0);
    this->hide();
    d.exec();
    this->show();
}

void MainWindow::on_mode_AI_clicked()
{
    this->ui->widget->setHidden(false);
    this->ui->pl2_label->setText("AI (white)");
    this->ui->pl2_name->setHidden((true));
}

void MainWindow::on_mode_2players_clicked()
{
    this->ui->widget->setHidden(true);
    this->ui->pl2_label->setText("Player2 (white):");
    this->ui->pl2_name->setHidden((false));
}

void MainWindow::on_new_game_button_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_load_game_button_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_back1_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}
