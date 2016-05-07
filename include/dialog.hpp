/**
 * @file dialog.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Graphical variant of user interface for the specific game after initialization.
 */

#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "gameio.hpp"
#include "celllabel.hpp"
#include "game_manager.hpp"

namespace Ui {
class Dialog;
}

/** Contains label to show actual state of the game, 2D vector of celllabel objects. */
class Dialog : public QDialog, public GameIO
{
    Q_OBJECT

public:
    /** Constructor setting up the scene, allocate vector of CellLabel objects.
     * @param gm pointer to GameManager object
     */
    explicit Dialog(GameManager *gm, QWidget *parent = 0);
    /** Deletes vector of cells. */
    ~Dialog();
    /** Loads all pictures from resources, set up the background, fill names of the
     * game and players.
     */
    void drawScene();
    /** Redraws the scene according to matrix of the game attribute of game_manager. */
    void refreshGrid();
    /** Sets up scene for 2 players mode. */
    void setVersus();
    /** Sets up scene for AI mode. */
    void setAI();
    /** Sets graphical representation of next turn. */
    void setTurn(Color color);

private:
    Ui::Dialog * ui;
    QGraphicsScene *scene; /** Main scene holding all the pixs. */
    static const int cell_size = 60; /** Constant size of one cell. */
    QVector<QVector<CellLabel*>> ggrid; /** 2D vector of the cells. */

private slots:
    void cellSelected(int x, int y); /** catching cellSelected signal emited by cells. */
    void cellMoved(int x, int y); /** catching cellMoved signal emited by cells. */
    void cellLeft(int x, int y); /** catching cellLeft signal emited by cells. */
    void on_forward_button_clicked(); /** catching clicked signal of forward button. */
    void on_backward_button_clicked(); /** catching clicked signal of backward button. */

    void on_save_button_clicked();
};

#endif // DIALOG_HPP
