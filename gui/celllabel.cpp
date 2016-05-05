/**
 * @file cellabel.cpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Contains implementation of customized label, that serves as one cell of grid.
 */

#include "celllabel.hpp"

CellLabel::CellLabel(int x_base, int y_base, int x, int y, int cell_size, QWidget *parent) : QLabel(parent)
{
    this->x = x;
    this->y = y;
    this ->disk.setPos(x * cell_size + 5, y * cell_size + 5);

    this->setGeometry(x_base + x * cell_size, y_base + y * cell_size, cell_size, cell_size);
    this->setMouseTracking(true);
    this->setFrameShape(this->Box);

}

void CellLabel::mousePressEvent(QMouseEvent *ev)
{
    emit cellSelected(this->x, this->y);
}

void CellLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->setFrameShape(this->WinPanel);
    emit cellMoved(this->x, this->y);
}

void CellLabel::leaveEvent(QEvent *)
{
    this->setFrameShape(this->Box);
    emit cellLeft(this->x, this->y);
}
