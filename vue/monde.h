#ifndef MONDE_H
#define MONDE_H

#include <SDL.h>

#include "metier/niveau.h"
#include "metier/tuile.h"

class Monde
{
private:
    Niveau * _niveau;
    int _niveauActuel;
    //---- pour les tuiles
    int _largeurTuile;       // largeur d'une tuile
    int _hauteurTuile;       // hauteur d'une tuile
    int _nbrTuilesEnColonne; // nbr de tuile en colonne de l'image tuiles.bmp
    int _nbrTuilesEnLigne;   // nbr de tuile en ligne de l'image tuile.bmp
    SDL_Surface * _imagesDesTuiles; // l'image tuiles.bmp
    vector<Tuile> _tuiles;   // liste des tuiles presente dans l'image tuiles.bmp
    //---- pour l'affichage du monde
    int _nbrTuilesEnColonneMonde; // nbr de tuiles en colonne du monde
    int _nbrTuilesEnLigneMonde;   // nbr de tuiles en ligne du monde
    int _horiScroll;     // position horizontale actuel du scroll
    int _vertiScroll;    // position verticale actuel du scroll
    int _largeurFenetre;
    int _hauteurFenetre;


    const string BALISE_FICHIER_IMAGE = "#nomFichierImage";
    const string BALISE_NBR_T_H_FI = "#nbrTuilesColonneFichierImage";
    const string BALISE_NBR_T_V_FI = "#nbrTuilesLigneFichierImage";
    const string BALISE_TYPE_TUILE = "#typeTuile";
    const string NOM_FICHIER_CONFIG = "mondeConfiguration.txt";

public:
    Monde(int largeurFenetre , int hauteurFenetre) throw(ExceptionGame);
    int getNiveauActuel() const;

    void setNiveauActuel(int nouveauNiveau) throw(ExceptionGame);
    /*!
        * \brief Modifie la valeur de la coordonnée Horizontale(x) de
        * scroll ( la position de la fenetre qui bouge dans le monde)
        * \param horiScroll la coordonné horizontale (x) de scroll
        */
    void setHoriScroll(int horiScroll);
    /*!
        * \brief Modifie la valeur de la coordonnée Verticale(y) de
        * scroll ( la position de la fenetre qui bouge dans le monde)
        * \param vertiScroll la coordonné verticale (y) de scroll
        */
    void setVertiScroll(int vertiScroll);
    /*!
        * \brief Donne la position Horizontale (x) de scroll
        * \return la position horizontale (x) de scroll
        */
    int getHoriScroll()const;
    /*!
        * \brief Donne la position Verticale (y) de scroll
        * \return la position verticale (y) de scroll
        */
    int getVertiScroll()const;
    /*!
        * \brief Donne la largeur d'une tuile(un élément du monde)
        * \return la largeur d'une tuile
        */
    int getLargeurTuile() const;
    /*!
        * \brief Donne la hauteur d'une tuile(un élément du monde)
        * \return la hauteur d'une tuile
        */
    int getHauteurTuile() const;
    /*!
        * \brief Donne le nombre de tuile en colonne du monde
        * \return le nombre de tuile en colonne du monde
        */
    int getNbrTuilesEnColonneMonde() const;
    /*!
        * \brief Donne le nombre de tuile en ligne du monde
        * \return le nombre de tuile en ligne du monde
        */
    int getNbrTuilesEnLigneMonde()const;
    /*!
        * \brief Permet l'affichage du monde dans une fenetre
        * \param fenetre la fenetre dans laquel on affiche le monde
        */
    void AfficherMonde(SDL_Surface * fenetre);
private:
    void chargerInfoDepuisFichier(ifstream &fichier) throw(ExceptionGame);
    SDL_Surface* chargerImage(string nomFichierImage);
};

#endif // MONDE_H
