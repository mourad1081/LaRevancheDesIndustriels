#include "gestionmonde.h"

GestionMonde::GestionMonde(SDL_Surface * fenetre
                           ,int largeurFenetre, int hauteurFenetre){
    _fenetre = fenetre;
    _lesEvents = new Evenement();
    //_lesEvents->ActiveAttenteEvenement();
    _largeurFenetre = largeurFenetre;
    _hauteurFenetre = hauteurFenetre;

    try {
        _monde = new Monde(largeurFenetre,hauteurFenetre);
    } catch( ExceptionGame eg ) {
        cerr << eg.what() ;
    }
}


void GestionMonde::bougerLaMap(){
    if (_lesEvents->_touches[SDLK_LEFT])
       _monde->setHoriScroll(_monde->getHoriScroll() - VITESSE_DEPLACEMENT);

    if (_lesEvents->_touches[SDLK_RIGHT])
       _monde->setHoriScroll(_monde->getHoriScroll() + VITESSE_DEPLACEMENT);

    if (_lesEvents->_touches[SDLK_UP])
        _monde->setVertiScroll(_monde->getVertiScroll() - VITESSE_DEPLACEMENT);

    if (_lesEvents->_touches[SDLK_DOWN])
        _monde->setVertiScroll(_monde->getVertiScroll() + VITESSE_DEPLACEMENT);

    if (_lesEvents->_quitter)
        exit(0);
}

void GestionMonde::miseAjourDeLaMap(){
    _lesEvents->ActiveAttenteEvenement();
    bougerLaMap();
    _monde->AfficherMonde(_fenetre);
    SDL_Flip(_fenetre);
}
