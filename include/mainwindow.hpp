#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <string>

#include "resources.hpp"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startgame_clicked();

    void on_mode_AI_clicked();

    void on_mode_2players_clicked();

private:
    Ui::MainWindow *ui;
};


struct game_data {
    int grid_size;
    GameMode mode;
    Difficulty difficulty;
    QString player1;
    QString player2;
};

#endif // MAINWINDOW_HPP
