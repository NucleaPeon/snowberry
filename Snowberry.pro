#-------------------------------------------------
#
# Project created by QtCreator 2023-12-16T21:32:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snowberry
TEMPLATE = app

OTHER_FILES = \
    snowberrynotes1.txt \
    snowberrynotes.txt \
    LEFTOFF.txt \
    DESIGN.txt \
    CMakeLists.txt \
    globals.h \
    version.h.in \
    \
    snowd/main.cpp \
    snowd/CMakeLists.txt \
    snowd/version.h.in \
    snowd/daemon.h \
    snowd/daemon.cpp \
    snowd/runner/main.cpp \
    snowd/runner/CMakeLists.txt \
    \
    snowgui/CMakeLists.txt \
    snowgui/main.cpp \
    snowgui/about.cpp \
    snowgui/about.h \
    snowgui/about.ui \
    snowgui/cocoainitializer.h \
    snowgui/cocoainitializer.mm \
    snowgui/mainwindow.h \
    snowgui/mainwindow.cpp \
    snowgui/preferences.h \
    snowgui/preferences.cpp \
    snowgui/preferences.ui \
    snowgui/version.h.in \
    \
    snowctl/CMakeLists.txt \
    snowctl/main.cpp \
    snowctl/version.h.in

