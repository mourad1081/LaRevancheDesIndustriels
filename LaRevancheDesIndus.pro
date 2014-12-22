#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:56:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaRevancheDesIndus
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors

SOURCES += main.cpp\
    O_SDO/sujetDObservation.cpp \
    metier/niveaux.cpp \
    metier/personnage.cpp \
    vue/personnagevue.cpp \
    vue/histoire.cpp \
    vue/gestionmonde.cpp \
    vue/monde.cpp \
    vue/application.cpp \
    metier/exceptiongame.cpp \
    metier/tuile.cpp

HEADERS  += \
    O_SDO/observateur.h \
    O_SDO/sujetDObservation.h \
    metier/niveaux.h \
    metier/personnage.h \
    vue/personnagevue.h \
    vue/histoire.h \
    vue/gestionmonde.h \
    vue/monde.h \
    vue/application.h \
    metier/exceptiongame.h \
    metier/tuile.h \
    metier/TypeTuile.h

FORMS    += \
    vue/application.ui

INCLUDEPATH += $$PWD/SDL/include/SDL
DEPENDPATH += $$PWD/SDL/include/SDL

INCLUDEPATH += $$PWD/SDL/lib
DEPENDPATH += $$PWD/SDL/lib

LIBS += -L SDL/lib/ -lmingw32 -lSDLmain -llibSDL -lSDL_image -lSDL_ttf

unix|win32: LIBS += -L$$PWD/SDL/lib/ -lSDLmain

INCLUDEPATH += $$PWD/SDL/include
DEPENDPATH += $$PWD/SDL/include

unix|win32: LIBS += -L$$PWD/SDL/lib/ -llibSDL

INCLUDEPATH += $$PWD/SDL/include
DEPENDPATH += $$PWD/SDL/include

unix|win32: LIBS += -L$$PWD/SDL/lib/ -lSDL_image

INCLUDEPATH += $$PWD/SDL/include
DEPENDPATH += $$PWD/SDL/include

unix|win32: LIBS += -L$$PWD/SDL/lib/ -lSDL_ttf

INCLUDEPATH += $$PWD/SDL/include
DEPENDPATH += $$PWD/SDL/include

RESOURCES += \
    images.qrc
