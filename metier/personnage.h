#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <QString>
#include "O_SDO/sujetDObservation.h"

class Personnage : public SujetDObservation
{
private:
    QString _nomPersonnage;
    int _pointDeVieTotal;
    int _pointDeVieCourant;
    int _degats;
public:
    Personnage();
    Personnage(QString nomPersonnage);
    Personnage(QString nomPersonnage, int pointDeVie);
    Personnage(QString nomPersonnage, int pointDeVie, int degats);
    virtual ~Personnage();
    QString nomPersonnage() const;
    void setNomPersonnage(const QString &nomPersonnage);
    int pointDeVieTotal() const;
    void setPointDeVieTotal(int pointDeVieTotal);
    int pointDeVieCourant() const;
    void setPointDeVieCourant(int pointDeVieCourant);
    int degats() const;
    void setDegats(int degats);
};

#endif // PERSONNAGE_H
