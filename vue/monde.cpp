#include "monde.h"

Monde::Monde(int largeurFenetre, int hauteurFenetre)  throw(ExceptionGame)
    :   _niveauActuel(1)
{
    _largeurFenetre = largeurFenetre;
    _hauteurFenetre = hauteurFenetre;
    _horiScroll = 0;
    _vertiScroll = 0;
    _niveau = new Niveau(_niveauActuel);
    _nbrTuilesEnColonneMonde = _niveau->getNbrColonne();
    _nbrTuilesEnLigneMonde = _niveau->getNbrLigne();

    // ouvre le fichier de configuration en lecture
    ifstream fichierConfig(NOM_FICHIER_CONFIG.c_str(), ios::in);
    if ( fichierConfig ){
        chargerInfoDepuisFichier(fichierConfig);
    }else{
        throw new ExceptionGame("Erreur d'ouverture du fichier de configuration");
    }

    fichierConfig.close();
}

int Monde::getNiveauActuel() const
{
    return _niveauActuel;
}

void Monde::setNiveauActuel(int nouveauNiveau) throw(ExceptionGame)
{
    _niveauActuel = nouveauNiveau;
    delete _niveau;
    _niveau = new  Niveau(_niveauActuel);
    _horiScroll = 0;
    _vertiScroll = 0;
    _nbrTuilesEnColonneMonde = _niveau->getNbrColonne();
    _nbrTuilesEnLigneMonde = _niveau->getNbrLigne();
}


void Monde::setHoriScroll(int horiScroll){
    if (horiScroll < 0
            || horiScroll > (_nbrTuilesEnColonneMonde*_largeurTuile)-_largeurFenetre) {
     _horiScroll = _horiScroll;
    } else {
        _horiScroll = horiScroll;
    }
}

void Monde::setVertiScroll(int vertiScroll){
    if (vertiScroll < 0
            || vertiScroll > (_nbrTuilesEnLigneMonde*_hauteurTuile)-_hauteurFenetre) {
     _vertiScroll = _vertiScroll;
    } else {
        _vertiScroll = vertiScroll;
    }
}
int Monde::getHoriScroll()const{
    return _horiScroll;
}
int Monde::getVertiScroll()const{
    return _vertiScroll;
}
int Monde::getLargeurTuile() const{
    return _largeurTuile;
}
int Monde::getHauteurTuile() const{
    return _hauteurTuile;
}
int Monde::getNbrTuilesEnColonneMonde() const{
    return _nbrTuilesEnColonneMonde;
}
int Monde::getNbrTuilesEnLigneMonde()const{
    return _nbrTuilesEnLigneMonde;
}
int Monde::getMaxX()const{
    return this->getNbrTuilesEnColonneMonde()
            * this->getLargeurTuile();
}
int Monde::getMaxY()const{
    return this->getNbrTuilesEnLigneMonde()
            * this->getHauteurTuile();
}
int Monde::getLargeurFenetre() const{
    return _largeurFenetre;
}
int Monde::getHauteurFenetre() const{
    return _hauteurFenetre;
}

void Monde::AfficherMonde(SDL_Surface * fenetre){

    SDL_Rect rectDest;
    int numTuile;
    int minX,minY,maxX,maxY;
    minX = _horiScroll / _largeurTuile-1;
    minY = _vertiScroll / _hauteurTuile-1;
    maxX = ((_horiScroll + _largeurFenetre) / _largeurTuile);
    maxY = ((_vertiScroll + _hauteurFenetre) / _hauteurTuile);

    for ( int i = minX; i <=  maxX ; i++){
        for ( int j = minY ; j <= maxY ; j++){
            rectDest.x = i * _largeurTuile - _horiScroll;
            rectDest.y = j * _hauteurTuile - _vertiScroll;

            if ( i < 0
                 || i >= _nbrTuilesEnColonneMonde
                 || j < 0
                 || j >= _nbrTuilesEnLigneMonde){
                numTuile = 0;
            }else{
                numTuile = _niveau->getNiveau()[j][i];

            }
            SDL_BlitSurface(_imagesDesTuiles
                            ,&(_tuiles[numTuile].getRectangle()),fenetre,&rectDest);
        }
    }
}

bool Monde::collisionPerso(Hero *h){
    SDL_Rect posHero = h->getPosTestHero();
    int x1, x2, y1, y2,i,j;
    Uint16 indicetile;

    //On teste si la position du joueur n'est pas en dehors de la map,
    //si c'est le cas, on retourne vrai.
    if (posHero.x < 0  || posHero.y < 0 ||
            posHero.x + posHero.w >= this->getMaxX()
            || posHero.y + posHero.h >= this->getMaxY())
    {
        return true;
    }

    x1 = posHero.x / _largeurTuile;
    y1 = posHero.y / _hauteurTuile;
    x2 = (posHero.x + posHero.w -1) / _largeurTuile;
    y2 = (posHero.y + posHero.h -1) / _hauteurTuile;

    for ( i = x1 ; i <=  x2  ; i++) {
        for ( j = y1 ; j <= y2  ; j++){

            indicetile = _niveau->getNiveau()[j][i];
            if (_tuiles[indicetile].getType() == TypeTuile::PLEIN){
                cout << "perso i : "<< i << endl;
                cout << "perso j : " << j << endl;
                return true;
            }
            if (_tuiles[indicetile].getType() == TypeTuile::VIDE_AVEC_DEGATS){
                if(h->getTimerMort() == 0){
                    h->setTimerMort(20);
                }
                return false;
            }
            if (_niveau->getNiveau()[j][i] == 18){
                _niveau->getNiveau()[j][i] = 5;
                h->incNbPoints();
            }
        }
    }
    return false;
}

bool Monde::collisionMonstre(Monstre *m){
    SDL_Rect posMonstre = m->getPosTestMonstre();
    int x1, x2, y1, y2,i,j;
    Uint16 indicetile;

    //On teste si la position du monstre n'est pas en dehors de la map,
    //si c'est le cas, on retourne vrai.
    if (posMonstre.x < 0  || posMonstre.y < 0 ||
            posMonstre.x + posMonstre.w >= this->getMaxX()
            || posMonstre.y + posMonstre.h >= this->getMaxY())
    {
        return true;
    }

    x1 = posMonstre.x / _largeurTuile;
    y1 = posMonstre.y / _hauteurTuile;
    x2 = (posMonstre.x + posMonstre.w -1) / _largeurTuile;
    y2 = (posMonstre.y + posMonstre.h -1) / _hauteurTuile;

    for ( i = x1 ; i <=  x2  ; i++) {
        for ( j = y1 ; j <= y2  ; j++){
            indicetile = _niveau->getNiveau()[j][i];
            if (_tuiles[indicetile].getType() == TypeTuile::PLEIN){
                //cout << "monstre i : " << i << endl;
                //cout << "monstre j : " << j << endl;

                return true;
            }
            if (_tuiles[indicetile].getType() == TypeTuile::VIDE_AVEC_DEGATS){
                return true;
            }
            if( i-1 >= 0 && j-1 >= 0
                    && i+1 <=_nbrTuilesEnColonneMonde && j+1 <= _nbrTuilesEnLigneMonde
                    && m->isOnGround()
                    ){

                //SOUCIS AVEC UN SEGMENTATION FAULT
                /*if ((_tuiles[_niveau->getNiveau()[j+1][i-1]].getType() == TypeTuile::VIDE
                     && _tuiles[_niveau->getNiveau()[j+1][i]].getType() == TypeTuile::PLEIN)
                         || (_tuiles[_niveau->getNiveau()[j+1][i+1]].getType() == TypeTuile::VIDE
                             && _tuiles[_niveau->getNiveau()[j+1][i]].getType() == TypeTuile::PLEIN)) {
                   return true;
                }*/
            }

            /*if (_niveau->getNiveau()[j][i] == 9){
                _niveau->getNiveau()[j][i] = 0;
                m->setTimerMort(1);
            }*/
        }
    }
    return false;
}

void Monde::chargerInfoDepuisFichier(ifstream &fichier) throw(ExceptionGame){

    string baliseTitre, nomFichierImage, baliseNbrTuileImg;
    string baliseTypeTuile, typeTuile;

    fichier >> baliseTitre;
    if ( ! baliseTitre.compare(BALISE_FICHIER_IMAGE) ){
        fichier >> nomFichierImage;
        _imagesDesTuiles = chargerImage(nomFichierImage);
    }else{
        throw new ExceptionGame("Votre fichier ne contient pas la balise #nomFichierImage");
    }

    fichier >> baliseNbrTuileImg;
    if ( ! baliseNbrTuileImg.compare(BALISE_NBR_T_H_FI) ){
        fichier >> _nbrTuilesEnColonne;
    }else{
        throw new ExceptionGame("Votre fichier ne contient pas la balise #nbrTuilesColonneFichierImage");
    }

    fichier >> baliseNbrTuileImg;
    if ( ! baliseNbrTuileImg.compare(BALISE_NBR_T_V_FI) ){
        fichier >> _nbrTuilesEnLigne;
    }else{
        throw new ExceptionGame("Votre fichier ne contient pas la balise #nbrTuilesLigneFichierImage");
    }

    _largeurTuile = _imagesDesTuiles->w / _nbrTuilesEnColonne;
    _hauteurTuile = _imagesDesTuiles->h / _nbrTuilesEnLigne;

    fichier >> baliseTypeTuile;
    if ( ! baliseTypeTuile.compare(BALISE_TYPE_TUILE) ){
        _tuiles.resize(_nbrTuilesEnLigne*_nbrTuilesEnColonne);

        for ( int j=0,numTuile=0 ; j < _nbrTuilesEnLigne ; j++){
            for ( int i=0 ; i < _nbrTuilesEnColonne ; i++){
                _tuiles[numTuile].setRectangle(_largeurTuile
                                               ,_hauteurTuile
                                               ,i*_largeurTuile
                                               ,j*_hauteurTuile);
                fichier >> typeTuile;
                fichier >> typeTuile;
                if ( ! typeTuile.compare("plein") ) {
                    _tuiles[numTuile].setType(TypeTuile::PLEIN);
                } else if ( ! typeTuile.compare("vide") ) {
                    _tuiles[numTuile].setType(TypeTuile::VIDE);
                } else if( ! typeTuile.compare("vide_avec_degats") ){
                    _tuiles[numTuile].setType(TypeTuile::VIDE_AVEC_DEGATS);
                } else {
                    _tuiles[numTuile].setType(TypeTuile::VIDE_AVEC_DEGATS);
                }
                numTuile++;
            }
        }
    }else{
        throw new ExceptionGame("Votre fichier ne contient pas la balise #typeTuile");
    }

}

SDL_Surface* Monde::chargerImage(string nomFichierImage){
    //SDL_Surface* image_result;
    // charge l'image dans image_ram en RAM
    SDL_Surface* image_ram = SDL_LoadBMP(nomFichierImage.c_str());

    if (image_ram == NULL){
        throw new ExceptionGame("l'image "+nomFichierImage+" est introuvable ");
    }
    //image_result = SDL_DisplayFormat(image_ram);
    //SDL_FreeSurface(image_ram);
    return image_ram;
}
