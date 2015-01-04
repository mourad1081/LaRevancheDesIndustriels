#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:56:27
#
#-------------------------------------------------

<<<<<<< HEAD

QT       += core gui sql

QT       += core gui
QT       += multimedia
=======
QT       += core gui sql multimedia

>>>>>>> 07328e53dc70ae5c4f7360cef1f2fa60413f0113
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaRevancheDesIndus
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors

SOURCES += main.cpp\
    vue/gestionmonde.cpp \
    vue/monde.cpp \
    vue/application.cpp \
    metier/exceptiongame.cpp \
    metier/tuile.cpp \
    metier/evenement.cpp \
    metier/niveau.cpp \
    metier/monstre.cpp \
    metier/hero.cpp \
    vue/gestionson.cpp \
    vue/parametresson.cpp \
    vue/choixmusique.cpp \
    vue/hud.cpp \
    metier/gestionbd.cpp \
    vue/historiquescore.cpp

HEADERS  += \
    vue/monde.h \
    vue/application.h \
    metier/exceptiongame.h \
    metier/tuile.h \
    metier/TypeTuile.h \
    metier/evenement.h \
    metier/niveau.h \
    metier/monstre.h \
    metier/hero.h \
    vue/gestionmonde.h \
    vue/gestionson.h \
    vue/parametresson.h \
    vue/choixmusique.h \
    vue/hud.h \
    metier/gestionbd.h \
    vue/historiquescore.h

FORMS    += \
    vue/application.ui \
    vue/parametresson.ui \
    vue/choixmusique.ui \
    vue/historiquescore.ui

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

unix|win32: LIBS += -L$$PWD/SDL/lib/ -lSDL_mixer

INCLUDEPATH += $$PWD/SDL/include
DEPENDPATH += $$PWD/SDL/include

unix|win32: LIBS += -L$$PWD/ -llibmysql

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
