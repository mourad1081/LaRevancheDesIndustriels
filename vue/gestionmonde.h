#ifndef GESTIONMONDE_H
#define GESTIONMONDE_H

#include "vue/monde.h"
#include "metier/evenement.h"
#include "metier/hero.h"
#include "metier/monstre.h"
#include "vue/monde.h"

class GestionMonde
{
private:
    SDL_Surface * _fenetre;
    Monde * _monde;
    Evenement * _lesEvents;
    Hero * hero;
    Monstre * monstres[2];
    int _largeurFenetre;
    int _hauteurFenetre;
    int _nbMonstres=2;


public:
    GestionMonde(SDL_Surface *fenetre, int largeurFenetre, int hauteurFenetre);

    /*!
     * \brief Permet de mettre a joueurs les joueurs à l'écran
     */
    void miseAjourJoueurs();

    /*!
     * \brief Permet mettre à jour la map
     */
    void miseAjourDeLaMap();

};

#endif // GESTIONMONDE_H
