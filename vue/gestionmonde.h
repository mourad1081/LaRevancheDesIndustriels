#ifndef GESTIONMONDE_H
#define GESTIONMONDE_H

#include "vue/monde.h"
#include "metier/evenement.h"
#include "metier/hero.h"
#include "metier/monstre.h"
#include "vue/monde.h"

/*!
 * \brief Classe qui permet la gestion complete du monde.
 */
class GestionMonde
{
private:
    SDL_Surface * _fenetre;
    Monde * _monde;
    Evenement * _lesEvents;
    Hero * _hero;
    Monstre * _monstres[5];
    int _largeurFenetre;
    int _hauteurFenetre;
    int _nbMonstres=5;


public:
    /*!
     * \brief Crée une nouvelle partie qu'il suffira simplement de mettre à jour.
     */
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
