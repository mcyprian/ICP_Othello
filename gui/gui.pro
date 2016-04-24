#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T19:21:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    guidisk.cpp \
    celllabel.cpp

HEADERS  += ../include/resources.hpp \
    ../include/userinterface.hpp \
    ../include/disk.hpp \
    ../include/game.hpp \
    ../include/player.hpp \
    ../include/playground.hpp \
    ../include/celllabel.hpp \
    ../include/dialog.hpp \
    ../include/guidisk.hpp \
    ../include/mainwindow.hpp

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += resources.qrc
INCLUDEPATH += ../include
