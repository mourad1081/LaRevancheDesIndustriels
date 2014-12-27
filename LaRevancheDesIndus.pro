#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:56:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaRevancheDesIndus
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors

SOURCES += main.cpp\
    O_SDO/sujetDObservation.cpp \
    vue/personnagevue.cpp \
    vue/histoire.cpp \
    vue/gestionmonde.cpp \
    vue/monde.cpp \
    vue/application.cpp \
    metier/exceptiongame.cpp \
    metier/tuile.cpp \
    metier/evenement.cpp \
    metier/niveau.cpp \
    metier/monstre.cpp \
    metier/hero.cpp

HEADERS  += \
    O_SDO/observateur.h \
    O_SDO/sujetDObservation.h \
    vue/personnagevue.h \
    vue/histoire.h \
    vue/monde.h \
    vue/application.h \
    metier/exceptiongame.h \
    metier/tuile.h \
    metier/TypeTuile.h \
    metier/evenement.h \
    metier/niveau.h \
    metier/monstre.h \
    metier/hero.h \
    vue/gestionmonde.h

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SDL/lib/ -lSDL_image
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SDL/lib/ -lSDL_image
else:unix: LIBS += -L$$PWD/SDL/lib/ -lSDL_image

INCLUDEPATH += $$PWD/SDL/include
DEPENDPATH += $$PWD/SDL/include
