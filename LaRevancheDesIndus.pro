#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:56:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaRevancheDesIndus
TEMPLATE = app


SOURCES += main.cpp\
        application.cpp \
    O_SDO/sujetDObservation.cpp \
    metier/niveaux.cpp \
    metier/personnage.cpp

HEADERS  += application.h \
    O_SDO/observateur.h \
    O_SDO/sujetDObservation.h \
    metier/niveaux.h \
    metier/personnage.h

FORMS    += application.ui

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors
