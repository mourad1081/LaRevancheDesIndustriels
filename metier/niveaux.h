#ifndef NIVEAUX_H
#define NIVEAUX_H

#include <metier/exceptiongame.h>

#include <fstream>
#include <iostream>
#include <QVector>
#include <QString>
#include <string>

using namespace std;

class Niveaux
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
    Niveaux(int numeroDuNiveau) throw (ExceptionGame);
    vector<vector<int>> getNiveau();

private:
    void chargerNiveauDepuisFichier(ifstream& fichier)throw (ExceptionGame);

};

#endif // NIVEAUX_H
