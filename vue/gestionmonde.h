#ifndef GESTIONMONDE_H
#define GESTIONMONDE_H

#include "vue/monde.h"
#include "metier/evenement.h"

class GestionMonde
{
private:
    SDL_Surface * _fenetre;
    Monde * _monde;
    Evenement * _lesEvents;
    int _largeurFenetre;
    int _hauteurFenetre;
    const int VITESSE_DEPLACEMENT = 10;
public:
    GestionMonde(SDL_Surface *fenetre, int largeurFenetre, int hauteurFenetre);
    void miseAjourDeLaMap();
private:
    /*!
         * \brief Permet de se deplacer dans la map en utilisant les fleches
         * \param monde Le monde dans lequel on veut se déplacé
         * \param event
         */
    void bougerLaMap();
};

#endif // GESTIONMONDE_H
