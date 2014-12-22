#ifndef NIVEAU_H
#define NIVEAU_H

#include <metier/exceptiongame.h>

#include <fstream>
#include <iostream>
#include <QVector>
#include <QString>
#include <string>

using namespace std;

class Niveau
{
private:
    int _numeroNiveau;
    int _nbrLigne;
    int _nbrColonne;
    vector<vector<int>> _niveau;

    const int NB_NIVEAUX = 5;
    const string NOM_FICHIER = "lvls/lvl_";
    const string EXTENSION_FICHIER = ".txt";
    const string BALISE_FICHIER_NIVEAU = "#NIVEAU";
    const string BALISE_LIGNE_NIVEAU = "#LIGNE";
    const string BALISE_COLONNE_NIVEAU = "#COLONNE";

public:
    Niveau(int numeroDuNiveau) throw (ExceptionGame);
    vector<vector<int>> getNiveau();
    int getNbrLigne() const;
    int getNbrColonne() const;

private:
    void chargerNiveauDepuisFichier(ifstream& fichier)throw (ExceptionGame);

};

#endif // NIVEAU_H
