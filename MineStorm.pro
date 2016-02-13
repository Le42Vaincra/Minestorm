#-------------------------------------------------
#
# Project created by QtCreator 2016-02-13T12:04:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineStorm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    spaceship.cpp \
    ufo.cpp

HEADERS  += mainwindow.h \
    game.h \
    spaceship.h \
    ufo.h

FORMS    += mainwindow.ui
