#ifndef GUIDISK_HPP
#define GUIDISK_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QEvent>

#include "resources.hpp"

class GUIDisk : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    GUIDisk(int color=BLACK, int x=0, int y=0, int cell_size=60, QGraphicsItem *parent=0);
    void flip();

private:
    QPixmap colors[2];
    int color;
};



#endif // GUIDISK_HPP
