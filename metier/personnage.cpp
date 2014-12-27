#include "personnage.h"


QString Personnage::nomPersonnage() const
{
    return _nomPersonnage;
}

void Personnage::setNomPersonnage(const QString &nomPersonnage)
{
    _nomPersonnage = nomPersonnage;
    notifierChangement();
}

int Personnage::pointDeVieTotal() const
{
    return _pointDeVieTotal;
}

void Personnage::setPointDeVieTotal(int pointDeVieTotal)
{
    _pointDeVieTotal = pointDeVieTotal;
    notifierChangement();
}

int Personnage::pointDeVieCourant() const
{
    return _pointDeVieCourant;
}

void Personnage::setPointDeVieCourant(int pointDeVieCourant)
{
    _pointDeVieCourant = pointDeVieCourant;
    notifierChangement();
}

int Personnage::degats() const
{
    return _degats;
}

void Personnage::setDegats(int degats)
{
    _degats = degats;
    notifierChangement();
}

Personnage::Personnage()
    : Personnage("nameless", 0, 0)
{
}

Personnage::Personnage(QString nomPersonnage)
    : Personnage(nomPersonnage, 0, 0)
{
}

Personnage::Personnage(QString nomPersonnage, int pointDeVie)
    : Personnage(nomPersonnage, pointDeVie, 0)
{
}

Personnage::Personnage(QString nomPersonnage, int pointDeVie, int degats)
{
    setNomPersonnage(nomPersonnage);
    setPointDeVieTotal(pointDeVie);
    setPointDeVieCourant(pointDeVie);
    setDegats(degats);
}

Personnage::~Personnage()
{
}
