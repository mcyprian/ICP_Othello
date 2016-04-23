#include "guiplayground.hpp"

GUIPlayground::GUIPlayground( int size, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->size = size;
    this->setPos(0, 0);

    this->setPixmap(QPixmap(":/image/images/board.png"));

    for (int i = 0; i < size; i++)
    {
        QVector<GUIDisk*> row;
        for (int j = 0; j < size; j++)
        {
            row.push_back(new GUIDisk((i + j) % 2, i, j));
        }
        this->ggrid.push_back(row);
    }

}

GUIPlayground::~GUIPlayground()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            delete this->ggrid[i][j];
        }
    }
}
