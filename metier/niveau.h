#ifndef NIVEAU_H
#define NIVEAU_H

#include <metier/exceptiongame.h>

#include <fstream>
#include <iostream>
#include <QVector>
#include <QString>
#include <string>
#include <SDL.h>

using namespace std;
/*!
 * \brief Classe qui représente un niveau du jeu
 */
class Niveau
{
private:
    int _numeroNiveau;
    int _nbrLigne;
    int _nbrColonne;
    int _nbrMonstres;
    vector<vector<int>> _niveau;
    vector<SDL_Rect> _listePosMonstres;

    const int NB_NIVEAUX = 5;
    const string NOM_FICHIER = "lvls/lvl_";
    const string EXTENSION_FICHIER = ".txt";
    const string BALISE_FICHIER_NIVEAU = "#NIVEAU";
    const string BALISE_LIGNE_NIVEAU = "#LIGNE";
    const string BALISE_COLONNE_NIVEAU = "#COLONNE";
    const string BALISE_NOMBRE_MONSTRE = "#NOMBRE_MONSTRE";

public:
    /*!
     * \brief Crée un niveau d'un certain numéro
     * \param numeroDuNiveau le numéro du niveau que l'on veut crée
     * \exception ExceptionGame Problème d'ouverture du fichier de niveau
     * \exception ExceptionGame Problème au niveau des balises
     *  dans le fichier de niveau
     */
    Niveau(int numeroDuNiveau) throw (ExceptionGame);
    /*!
     * \brief Asseseur en lecture.
     * \return le niveau sous forme de tableau 2d.
     */
    vector<vector<int>> getNiveau();
    /*!
     * \brief Asseseur en lecture.
     * \return le nombre de ligne du niveau.
     */
    int getNbrLigne() const;
    /*!
     * \brief Asseseur en lecture.
     * \return le nombre de colonne du niveau.
     */
    int getNbrColonne() const;
    /*!
     * \brief Asseseur en lecture au tableau de position des monstres.
     * \return le tableau.
     */
    vector<SDL_Rect> getListPosMonstres();


private:
    void chargerNiveauDepuisFichier(ifstream& fichier)throw (ExceptionGame);

};

#endif // NIVEAU_H
