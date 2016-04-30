#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <string>

#include "resources.hpp"
#include "userinterface.hpp"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public UserInterface
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


struct gameData {
    int grid_size;
    GameMode mode;
    Difficulty difficulty;
    QString player1;
    QString player2;
};

#endif // MAINWINDOW_HPP
