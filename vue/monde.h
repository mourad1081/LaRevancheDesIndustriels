#ifndef MONDE_H
#define MONDE_H
#include "metier/niveaux.h"
class Monde
{
private:
    Niveaux niveaux;
    int niveauActuel;
public:
    Monde();
    static void genererMonde(QString nomFichier);

    Niveaux getNiveaux() const;
    void setNiveaux(const Niveaux &value);
    int getNiveauActuel() const;
    void setNiveauActuel(int value);
};

#endif // MONDE_H
