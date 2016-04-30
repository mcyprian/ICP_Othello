#include "guidisk.hpp"

GUIDisk::GUIDisk(int color, int x, int y, int cell_size, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->colors[0] = QPixmap(":/image/images/black_stone.png");
    this->colors[1] = QPixmap(":/image/images/white_stone.png");

    this->setPos(x * cell_size + 5, y * cell_size + 5);
    this->color = color;

    this->setPixmap(this->colors[color]);
}


void GUIDisk::flip()    // TODO remove if not necessary
{
    if (this->color == WHITE)
        this->color = BLACK;
    else
        this->color = WHITE;
    this->setPixmap(this->colors[this->color]);
}

void GUIDisk::setColor(Color new_color)
{
    this->setPixmap(this->colors[new_color]);

}
