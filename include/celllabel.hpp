/**
 * @file cellabel.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Contains declaration of customized label, that serves as one cell of grid.
 */

#ifndef CELLLABEL_HPP
#define CELLLABEL_HPP

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

#include "guidisk.hpp"

/** Customized QLabel, containing mouse interaction and position settings of
 * grid cell. */
class CellLabel : public QLabel {
  Q_OBJECT

 public:
  /** Stores values of axis to attributes, sets relative position of the cell.
   * @param x_base x coordinate of graphicsView position.
   * @param y_base y coordinate of graphicsView position.
   * @param x coordinate of cell position on the grid.
   * @param y coordinate of cell position on the grid.
   * @param cell_size size of the cell
   * @param parent pointer to parent QWidget (default 0)
   */
  explicit CellLabel(int x_base, int y_base, int x, int y, int cell_size,
                     QWidget *parent = 0);
  /* Emiting signal cellSelected.
   * @param ev pointer to QMouseEvent
   */
  void mousePressEvent(QMouseEvent *ev);
  /* Emiting signal cellMoved and setting frame shape to WinPanel.
   * @param ev pointer to QMouseEvent
   */
  void mouseMoveEvent(QMouseEvent *ev);
  /* Emiting signal cellLeft, setting frame shape to default. */
  void leaveEvent(QEvent *);
  GUIDisk *getDisk() { return &this->disk; };
  void AITurn();

 signals:
  /** Signal to indicate that cell was selected. */
  void cellSelected(int x, int y);
  /** Signal to indicate mouse move on the cell. */
  void cellMoved(int x, int y);
  /** Signal to indicate that mouse left the cell. */
  void cellLeft(int x, int y);

 private:
  int x; /** Stores x coordinate of the instance. */
  int y; /** Stores y coordinate of the instance. */

  GUIDisk disk;
};

#endif  // CELLLABEL_HPP
