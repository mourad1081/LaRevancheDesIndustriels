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
     * produit seront enregistre et pourront être consulter
     */
    void ActiveAttenteEvenement();

public:
    char _touches[SDLK_LAST];
    char _quitter;
};

#endif // EVENEMENT_H
