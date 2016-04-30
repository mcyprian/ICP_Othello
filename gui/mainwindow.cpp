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

}

MainWindow::~MainWindow()
{
    delete this->ui;
}


void MainWindow::on_startgame_clicked()
{
    struct gameData game_data;
    game_data.grid_size = (this->ui->buttonGroup->checkedId()) * -2 + 2;
    game_data.player1 = this->ui->pl1_name->text();
    if (this->ui->mode_2players->isChecked()) {
        game_data.mode = VERSUS;
        game_data.player2 = this->ui->pl2_name->text();
    } else {
        game_data.mode = AI;
        game_data.difficulty = (this->ui->pl2_radio_easy->isChecked()) ? SIMPLE : HARD;
    }
    if (game_data.mode == VERSUS)
        this->gm->initNewGame("game1", game_data.mode, game_data.grid_size, game_data.player1.toStdString(), BLACK, game_data.player2.toStdString());
    else
        this->gm->initNewGame("game1", game_data.mode, game_data.grid_size, game_data.player1.toStdString(), BLACK, game_data.difficulty);

    Dialog d(this->gm, game_data, 0);
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
