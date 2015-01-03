#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <SDL.h>
#include "vue/gestionson.h"

/*!
 * \brief Classe qui permet de connaitre les évenements
 * qui se sont produit au clavier (ex: pression de touche,...)
 */
class Evenement
{
public:
    /*!
     * \brief Initaliser les Evenement a null
     */
    Evenement();
    /*!
     * \brief Active l'attente d'évenement, les évenements qui se seront
     * produit seront enregistré et pourront etre consulter
     */
    void ActiveAttenteEvenement();

public:
    char key[SDLK_LAST];
    char quit;
};

#endif // EVENEMENT_H
