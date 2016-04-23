#include "guidisk.hpp"

GUIDisk::GUIDisk(int color, int x, int y, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->colors[0] = QPixmap(":/image/images/black_stone.png");
    this->colors[1] = QPixmap(":/image/images/white_stone.png");

    this->setPos(x*79.25+10+x, y*79.25+10+y);
    this->color = color;

    this->setPixmap(this->colors[color]);
}

void GUIDisk::flip()
{
    if (this->color == 1)
        this->color = 0;
    else
        this->color = 1;
    this->setPixmap(this->colors[this->color]);
}
