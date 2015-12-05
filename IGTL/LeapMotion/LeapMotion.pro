#-------------------------------------------------
#
# Project created by QtCreator 2015-11-24T20:55:01
#
#-------------------------------------------------

QT       += core

QT       -= gui

INCLUDEPATH += ../../include

LIBS += -L../../lib -lLeap -lOpenIGTLink

TARGET = LeapMotion
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    lm/leapmotionlistener.cpp \
    igt/tracker.cpp

HEADERS += \
    lm/leapmotionlistener.h \
    igt/tracker.h

MOC_DIR = ./moc
OBJECTS_DIR =./obj
DESTDIR = ./bin

