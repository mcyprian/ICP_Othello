/**
 * @file guidisk.hpp
 * @author Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
 *
 * @section DESCRIPTION
 *
 * Customized QGraphiscPixmapItem to represent disk in GUI.
 */

#ifndef GUIDISK_HPP
#define GUIDISK_HPP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QEvent>

#include "resources.hpp"

/** Contains methods of GUI represenatation of one disk. */
class GUIDisk : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /** Constructor loads pictures from resources, sets up position according to arguments.
     * @param x coordinate of the disk
     * @param y coordinate of the disk
     * @param cell_size size of one cell
     * @param parent pointer to parent QGraphicsItem (default 0)
     */
    GUIDisk(int x=0, int y=0, int cell_size=60, QGraphicsItem *parent=0);
    /** Sets color of the disk.
     * @param new_color color to be set
     * @param transparent transparent version of disk will be set if true
     */
    void setColor(Color new_color, bool transparent);
    /** Indicates if disk is currently transparent or not
     * @return true if disk is tranparent, false if it is not.
     */
    bool isTransparent() const { return this->transparent; }
    /** Sets disk to tranparent of regular variant
     * @param value disk will be set to transparent version if true.
     */
    void setTransparent(bool value) { this->transparent = value; }

private:
    QPixmap colors_pix[2]; /** Array storing regular pictures of black and white disk. */
    QPixmap transparent_pix[2]; /** Array storing transparent versions of disks images. */
    int color; /** Current color of the disk. */
    bool transparent; /** Indicates if disk is currently transparent or not. */
};

#endif // GUIDISK_HPP
