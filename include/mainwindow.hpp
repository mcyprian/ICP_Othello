/**
 * @file mainwindow.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Graphical user interface class containing navigation menu of the game.
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <string>
#include <QStandardItemModel>

#include "resources.hpp"
#include "userinterface.hpp"

namespace Ui {
class MainWindow;
}

/** Class represents main window to load game or start new one. */
class MainWindow : public QMainWindow, public UserInterface {
  Q_OBJECT

 public:
  /** Constructor sets up parameters of all widget on main window. */
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  /** Runs main infinit loop of the game. */
  void mainLoop() { this->show(); }
  /** Creates and run new dialog window. */
  void runDialog();
  /** Reloades list of saved games. */
  void reloadGames();

 private slots:
  /** Starts new dialog window with selected game. */
  void on_startgame_clicked();
  /** Hides widgets of second player. */
  void on_mode_AI_clicked();
  /** Shows widgets of second player. */
  void on_mode_2players_clicked();
  /** Sets stacked widget to new game page. */
  void on_new_game_button_clicked();
  /** Sets stacked widget to load game page. */
  void on_load_game_button_clicked();
  /** Sets stacked widget back to main menu. */
  void on_back1_clicked();
  /** Sets stacked widget back to main menu. */
  void on_back2_clicked();
  /** Catches clicked signal of start_loaded button. */
  void on_start_loaded_clicked();
  /** Catches clicked signal of remove_game button. */
  void on_remove_game_clicked();

 private:
  Ui::MainWindow *ui;        /** Refernce to main window ui components. */
  QStandardItemModel *model; /** Model containing list view items. */
};

#endif  // MAINWINDOW_HPP
