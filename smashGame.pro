#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T10:24:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smashGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    map.cpp \
    controller.cpp \
    windialog.cpp \
    lostdialog.cpp \
    phase.cpp \
    aboutdialog.cpp \
    helpdialog.cpp

HEADERS  += mainwindow.h \
    ball.h \
    map.h \
    controller.h \
    windialog.h \
    lostdialog.h \
    phase.h \
    aboutdialog.h \
    helpdialog.h

FORMS    += mainwindow.ui \
    windialog.ui \
    lostdialog.ui \
    phase.ui \
    aboutdialog.ui \
    helpdialog.ui

DISTFILES +=

RESOURCES += \
    images.qrc
