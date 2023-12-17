#-------------------------------------------------
#
# Project created by QtCreator 2023-12-16T21:32:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snowberry
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        about.cpp\
        preferences.cpp

HEADERS  += mainwindow.h\
        about.h\
        preferences.h

macx { 

    LIBS += -framework Cocoa

    QT += macextras

    OBJECTIVE_SOURCES += cocoainitializer.mm
    OBJECTIVE_HEADERS += cocoainitializer.h

}

OTHER_FILES = \
    snowberrynotes1.txt \
    snowberrynotes.txt \
    LEFTOFF.txt \
    DESIGN.txt


FORMS    += mainwindow.ui\
        about.ui\
        preferences.ui
