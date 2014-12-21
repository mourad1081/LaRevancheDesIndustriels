#include "monde.h"


Niveaux Monde::getNiveaux() const
{
    return niveaux;
}

void Monde::setNiveaux(const Niveaux &value)
{
    niveaux = value;
}

int Monde::getNiveauActuel() const
{
    return niveauActuel;
}

void Monde::setNiveauActuel(int value)
{
    niveauActuel = value;
}
Monde::Monde()
{
}

void Monde::genererMonde(QString nomFichier)
{

}
