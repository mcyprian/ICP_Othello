#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "dialog.hpp"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->widget->setHidden(true);

}

MainWindow::~MainWindow()
{
    delete this->ui;
}


void MainWindow::on_startgame_clicked()
{

    gameData game_data = {0, VERSUS, NONE, "", ""};
    game_data.grid_size = (this->ui->buttonGroup->checkedId()) * -2 + 2;
    game_data.player1 = this->ui->pl1_name->text();
    if (this->ui->mode_2players->isChecked()) {
        game_data.mode = VERSUS;
        game_data.player2 = this->ui->pl2_name->text();
    } else {
        game_data.mode = AI;
        game_data.difficulty = (this->ui->pl2_radio_easy->isChecked()) ? SIMPLE : HARD;
    }

    Dialog d(game_data, 0);
    d.exec();
    show();
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
