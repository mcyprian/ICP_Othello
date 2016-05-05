/**
 * @file guidisk.cpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Implementation of customized QGraphiscPixmapItem to represent disk in GUI.
 */

#include "guidisk.hpp"

GUIDisk::GUIDisk(int color, int x, int y, int cell_size, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->colors_pix[0] = QPixmap(":/image/images/black_stone.png");
    this->colors_pix[1] = QPixmap(":/image/images/white_stone.png");

    this->transparent_pix[0] = QPixmap(":/image/images/black_transparent.png");
    this->transparent_pix[1] = QPixmap(":/image/images/white_transparent.png");

    this->transparent = false;

    this->setPos(x * cell_size + 5, y * cell_size + 5);
}

void GUIDisk::setColor(Color new_color, bool transparent)
{
    if (!transparent) {
        this->setPixmap(this->colors_pix[new_color]);
        this->transparent = false;
    } else {
        this->setPixmap(this->transparent_pix[new_color]);
        this->transparent = true;
    }

}
