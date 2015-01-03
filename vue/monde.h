#ifndef MONDE_H
#define MONDE_H

#include <iostream>
#include <vector>
#include <SDL.h>
#include <string>
#include <fstream>

#include "metier/hero.h"
#include "metier/monstre.h"
#include "metier/tuile.h"
#include "metier/exceptiongame.h"

#include "metier/niveau.h"
#include "metier/tuile.h"

using namespace std;
/*!
 * \brief Représente un Monde
 */
class Hero;
class Monstre;

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

    vector<vector<int>> _schema;
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

    /*!
     * \brief Crée un monde avec le niveau 1.
     * \param largeurFenetre la largeur de la fenètre
     *  ou vas être afficher le monde.
     * \param hauteurFenetre la hauteur de la fenètre
     *  ou vas être afficher le monde.
     * \exception ExceptionGame Problème d'ouverture du fichier de configuration
     * \exception ExceptionGame Problème au niveau des balises
     *  dans le fichier de configuration
     */
    Monde(int largeurFenetre, int hauteurFenetre) throw(ExceptionGame);   
    /*!
     * \brief Asseseur en lecture.
     * \return le niveau actuel.
     */
    int getNiveauActuel() const;
    /*!
     * \brief Asseseur en écriture.
     * \param le nouveau niveau actuel.
     */
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
        * \brief Donne la largeur de la fenetre
        * \return la largeur de la fenetre
        */
    int getLargeurFenetre() const;
    /*!
        * \brief Donne la hauteur d'une de la fenetre
        * \return la hauteur de la fenetre
        */
    int getHauteurFenetre() const;
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
     * \brief Donne la largeur du monde
     * \return largeur du monde
     */
    int getMaxX()const;
    /*!
     * \brief Donne la hauteur du monde
     * \return hauteur du monde
     */
    int getMaxY()const;
    /*!
     * \brief Donne la liste des positions des monstres
     * \return liste des positions
     */
    vector<SDL_Rect> getListPosMonstres();
    /*!
        * \brief Permet l'affichage du monde dans une fenetre
        * \param fenetre la fenetre dans laquel on affiche le monde
        */
    void AfficherMonde(SDL_Surface * fenetre);
    /*!
     * \brief Permet de savoir si le personnage est en collison avec
     * un element du monde qu'il ne peut pas traverser
     * \param perso
     * \return true s'il y a collision, faux sinon
     */
    bool collisionPerso(Hero *h);
    /*!
     * \brief Permet de savoir si un monstre est en collison avec
     * un element du monde qu'il ne peut pas traverser
     * \param monstre
     * \return true s'il y a collision, faux sinon
     */
    bool collisionMonstre(Monstre *m);

    bool finDuNiveau(Hero *h);
private:
    void chargerInfoDepuisFichier(ifstream &fichier) throw(ExceptionGame);
    SDL_Surface* chargerImage(string nomFichierImage);
};

#endif // MONDE_H
