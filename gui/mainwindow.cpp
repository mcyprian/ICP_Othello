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
    //this->ui->difficulty_label->setHidden((true));


}

MainWindow::~MainWindow()
{
    delete this->ui;
}


void MainWindow::on_startgame_clicked()
{
    struct game_data game_data;
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
        cout << "size: " << game_data.grid_size << " mode " << game_data.mode << " player1: "
             << game_data.player1.toStdString() << " player2: " << game_data.player2.toStdString() << endl;
    else
        cout << "size: " << game_data.grid_size << " mode " << game_data.mode << " player1: "
             << game_data.player1.toStdString() << " difficulty: " << game_data.difficulty << endl;

    Dialog d;
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
