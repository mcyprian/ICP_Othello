#ifndef GUIDISK_HPP
#define GUIDISK_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QEvent>

#include "../include/resources.hpp"

class GUIDisk : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    GUIDisk(int color=BLACK, int x=0, int y=0, int cell_size=60, QGraphicsItem *parent=0);
    void flip();
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void cell_selected(int x, int y);

private:
    QPixmap colors[2];
    int color;
    int x;
    int y;
};



#endif // GUIDISK_HPP
