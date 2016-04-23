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
    dialog.cpp

HEADERS  += mainwindow.hpp \
    dialog.hpp

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += resources.qrc
