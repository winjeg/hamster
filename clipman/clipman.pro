#-------------------------------------------------
#
# Project created by QtCreator 2017-08-11T19:33:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clipman
TEMPLATE = app


SOURCES += main.cpp\
        clipman.cpp \
    clipboardmanager.cpp \
    clipserver.cpp \
    clipclient.cpp \
    about.cpp \
    clipsettings.cpp \
    settingdialog.cpp

HEADERS  += clipman.h \
    clipboardmanager.h \
    clipserver.h \
    clipclient.h \
    about.h \
    clipsettings.h \
    settingdialog.h

FORMS    += clipman.ui \
    about.ui \
    settingdialog.ui

RESOURCES += \
    imgs.qrc

DISTFILES += \
    clipman.rc

RC_FILE = clipman.rc
