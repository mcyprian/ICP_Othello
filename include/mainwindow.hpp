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
    MainWindow(struct gameData &game_data, QWidget *parent = 0) {};
    ~MainWindow();

private slots:
    void on_startgame_clicked();

    void on_mode_AI_clicked();

    void on_mode_2players_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
