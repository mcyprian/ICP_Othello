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
    celllabel.cpp \
    ../src/game.cpp \
    ../src/game_manager.cpp \
    ../src/playground.cpp \
    ../src/gameio.cpp \
    ../src/cligame.cpp \
    ../src/climenu.cpp \
    ../src/commandlineinterface.cpp

HEADERS  += ../include/resources.hpp \
    ../include/userinterface.hpp \
    ../include/disk.hpp \
    ../include/game.hpp \
    ../include/player.hpp \
    ../include/playground.hpp \
    ../include/celllabel.hpp \
    ../include/dialog.hpp \
    ../include/guidisk.hpp \
    ../include/mainwindow.hpp \
    ../include/gameio.hpp \
    ../include/climenu.hpp


LIBS += -lboost_serialization

QMAKE_CXXFLAGS += -std=c++11

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += resources.qrc
INCLUDEPATH += ../include

DISTFILES += \
    ../src/CMakeLists.txt
