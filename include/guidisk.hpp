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
    void setColor(Color new_color, bool transparent);
    bool isTransparent() const { return this->transparent; }
    void setTransparent(bool value) { this->transparent = value; }

private:
    QPixmap colors_pix[2];
    QPixmap transparent_pix[2];
    int color;
    bool transparent;
};



#endif // GUIDISK_HPP
