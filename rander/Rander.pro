#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T10:40:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rander
TEMPLATE = app


SOURCES += main.cpp\
        rander.cpp \
    updatethread.cpp

HEADERS  += rander.h \
    updatethread.h

FORMS    += rander.ui

RC_ICONS = icon.ico

RESOURCES += \
    resource.qrc
