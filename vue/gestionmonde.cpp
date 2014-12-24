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

        hero = new Hero("img/walkright.png", 0, 0, 40, 80);

        float randomX;
        for(int i=0; i < _nbMonstres ; i++)
        {
            //Il faudra placer les monstres en fonction du niveau.
            randomX = rand()%_monde->getMaxX();
            //randomX = 400;
            monstres[i] = new Monstre ("img/walkright.png", randomX ,300, 40, 80);
        }

        while(!_lesEvents->key[SDLK_ESCAPE] && !_lesEvents->quit && hero->getNbVies() > 0){

            this->miseAjourDeLaMap();
            this->miseAjourJoueurs();
        }

    } catch( ExceptionGame eg ) {
        cerr << eg.what() ;
    }
}
void GestionMonde::miseAjourJoueurs(){
    hero->drawAnimatedPlayer(_fenetre, _monde);
    hero->updatePlayer(_lesEvents, _monde, _fenetre);

    for(int i=0; i < _nbMonstres ; i++)
    {
        if(!monstres[i]->estMort()){
            monstres[i]->drawAnimatedMonster(_fenetre, _monde);
            monstres[i]->updateMonster(hero, _monde);
        }
    }
    SDL_Flip(_fenetre);
    SDL_Delay(5);
}

void GestionMonde::miseAjourDeLaMap(){
    _lesEvents->ActiveAttenteEvenement();
    _monde->AfficherMonde(_fenetre);
}
