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
    void mainLoop() { this->show(); }

private slots:
    void on_startgame_clicked();

    void on_mode_AI_clicked();

    void on_mode_2players_clicked();

    void on_new_game_button_clicked();

    void on_load_game_button_clicked();

    void on_back1_clicked();

    void on_back2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
