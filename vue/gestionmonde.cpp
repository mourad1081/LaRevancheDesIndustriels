#include "gestionmonde.h"

GestionMonde::GestionMonde(SDL_Surface * fenetre
                           ,int largeurFenetre, int hauteurFenetre){
    _fenetre = fenetre;
    _lesEvents = new Evenement();
    _largeurFenetre = largeurFenetre;
    _hauteurFenetre = hauteurFenetre;
    _monde = new Monde(largeurFenetre,hauteurFenetre);
    _hero = new Hero("img/walkright.png", 93 ,800, 40, 80);

    /*float randomX;
        for(int i=0; i < _nbMonstres ; i++)
        {
            //Il faudra placer les monstres en fonction du niveau.
            randomX = rand()%_monde->getMaxX();
            //randomX = 400;
            monstres[i] = new Monstre ("img/walkright.png", 93 ,800, 40, 80);
        }*/

    _monstres[0] = new Monstre ("img/walkright.png", 93 ,800, 40, 80);
    _monstres[1] = new Monstre ("img/walkright.png", 1845 ,685, 40, 80);
    _monstres[2] = new Monstre ("img/walkright.png", 2394 ,685, 40, 80);
    _monstres[3] = new Monstre ("img/walkright.png", 2877 ,750, 40, 80);
    _monstres[4] = new Monstre ("img/walkright.png", 3480 ,750, 40, 80);
}
void GestionMonde::miseAjourJoueurs(){
    if (_lesEvents->key[SDLK_ESCAPE] || _lesEvents->quit || _hero->getNbVies() <= 0 ) {
        exit(0);
    }
    _hero->drawAnimatedPlayer(_fenetre, _monde);
    _hero->updatePlayer(_lesEvents, _monde, _fenetre);

    for(int i=0; i < _nbMonstres ; i++){
        if(!_monstres[i]->estMort()){
            _monstres[i]->drawAnimatedMonster(_fenetre, _monde);
            _monstres[i]->updateMonster(_hero, _monde);
        }
    }
    SDL_Flip(_fenetre);
    SDL_Delay(5);

}

void GestionMonde::miseAjourDeLaMap(){
    if (_lesEvents->key[SDLK_ESCAPE] || _lesEvents->quit || _hero->getNbVies() <= 0 ) {
        exit(0);
    }
    _lesEvents->ActiveAttenteEvenement();
    _monde->AfficherMonde(_fenetre);
}
