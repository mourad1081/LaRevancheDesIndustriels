#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <SDL.h>

class Evenement
{
public:
    /*!
     * \brief Initaliser les Evenement a null
     */
    Evenement();
    /*!
     * \brief Active l'attente d'évenement, les evenements qui se seront
     * produit seront enregistre et pourront etre consulter
     */
    void ActiveAttenteEvenement();

public:
    char key[SDLK_LAST];
    int mousex,mousey;
    int mousexrel,mouseyrel;
    char mousebuttons[8];
    char quit;
};

#endif // EVENEMENT_H
