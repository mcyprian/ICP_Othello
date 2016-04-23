#ifndef GUIPLAYGROUND_HPP
#define GUIPLAYGROUND_HPP

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>

#include "guidisk.hpp"

class GUIPlayground : public QObject, public QGraphicsPixmapItem
{
    friend class Dialog;
    Q_OBJECT

public:
    GUIPlayground( int size=8, QGraphicsItem *parent=0);
    ~GUIPlayground();

private:
    int size;
    QVector<QVector<GUIDisk*>> ggrid;
};



#endif // GUIPLAYGROUND_HPP
