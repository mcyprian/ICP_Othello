Project for ICP, FIT VUTBR 2015/2016 : Othello (Reversi)

Othello is a strategy board game for two players. There are sixty-four identical game 
pieces called disks, which are light on one side and dark on the other. 
Players take turns placing disks on the board with their assigned color facing up.
During a play, any disks of the opponent's color that are in a straight line and bounded by 
the disk just placed and another disk of the current player's color are turned over to the current 
player's color.

Features:
* allows to choose size of the board (6, 8, 10, 12)
* graphical and command-line user interfaces

Modes:
* 2 Players - play against each other
* Versus AI - play against artificial intelligence of selected level

Set the path and environment variables before usage, example:
PATH=/usr/local/share/Qt-5.5.1/5.5/gcc_64/bin/:$PATH
LD_LIBRARY_PATH=/usr/local/share/Qt-5.5.1/5.5/gcc_64/lib
export LD_LIBRARY_PATH

Set paths prefix for your system in qt.conf

Libraries used:
QT (v. 5.5)
Boost

Authors:
    Michal Cyprian <xcypri01@stud.fit.vutbr.cz>
    Radovan Sroka <xsroka00@stud.fit.vutbr.cz>
