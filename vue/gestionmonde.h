#ifndef GESTIONMONDE_H
#define GESTIONMONDE_H

#include "vue/monde.h"
#include "metier/evenement.h"
#include "metier/hero.h"
#include "metier/monstre.h"
#include "vue/monde.h"
#include "SDL_ttf.h"
#include "vue/hud.h"

/*!
 *\mainpage les aventures de ben le nudiste heureux
 *\author Faïssal Abouri, Benoit Rion, Mourad Akandouch, Chetouani Abdelhalim.
 *
 * \version 1.0
 *
 * \date 2014-2015
 */

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
    vector<Monstre*> _monstres;

    int _largeurFenetre;
    int _hauteurFenetre;
    int _nbMonstres;

    //HUD
    TTF_Font * _font;
    SDL_Surface *_HUD_vie, *_HUD_etoiles;

public:
    /*!
     * \brief Crée une nouvelle partie qu'il suffira simplement de mettre à jour.
     */
    GestionMonde(SDL_Surface *fenetre, int largeurFenetre, int hauteurFenetre);
    /*!
     * \brief Destructeur de la classe
     */
    ~GestionMonde();
    /*!
     * \brief Permet de mettre a joueurs les joueurs à l'écran
     */
    void miseAjourJoueurs();
    /*!
     * \brief Permet mettre à jour la map
     */
    void miseAjourDeLaMap();
    /*!
     * \brief On affiche les points et le nb de vies
     */
    void drawHUD();


};

#endif // GESTIONMONDE_H
