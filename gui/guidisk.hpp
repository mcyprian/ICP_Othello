#ifndef GUIDISK_HPP
#define GUIDISK_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class GUIDisk : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    GUIDisk(int color=0, int x=0, int y=0, QGraphicsItem *parent=0);
    void flip();

private:
    QPixmap colors[2];
    int color;
};



#endif // GUIDISK_HPP
