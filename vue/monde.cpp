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
    _schema = _niveau->getNiveau();
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
    _schema = _niveau->getNiveau();
    _horiScroll = 0;
    _vertiScroll = 0;
    _nbrTuilesEnColonneMonde = _niveau->getNbrColonne();
    _nbrTuilesEnLigneMonde = _niveau->getNbrLigne();
}


void Monde::setHoriScroll(int horiScroll){
    _horiScroll = horiScroll;
}

void Monde::setVertiScroll(int vertiScroll){
    _vertiScroll = vertiScroll;
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

vector<SDL_Rect> Monde::getListPosMonstres() {
    return _niveau->getListPosMonstres();
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
                numTuile = _schema[j][i];
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
            || posHero.y + posHero.h >= this->getMaxY() - 10)
    {
        return true;
    }

    x1 = posHero.x / _largeurTuile;
    y1 = posHero.y / _hauteurTuile;
    x2 = (posHero.x + posHero.w -1) / _largeurTuile;
    y2 = (posHero.y + posHero.h -1) / _hauteurTuile;

    for ( i = x1 ; i <=  x2  ; i++) {
        for ( j = y1 ; j <= y2  ; j++){

            indicetile = _schema[j][i];
            if (_tuiles[indicetile].getType() == TypeTuile::PLEIN){
                return true;
            }
            //On gère la tuile des pieces.
            if (_tuiles[indicetile].getType() == TypeTuile::PIECE){
                if(posHero.x <= (i * _largeurTuile) + 2*(_largeurTuile/3)
                        && posHero.y <= (j * _hauteurTuile) + 2*(_hauteurTuile / 3)
                        && posHero.x + posHero.w >= (i * _largeurTuile) + (_largeurTuile/3)
                        && posHero.y + posHero.h >= (j * _hauteurTuile) + (_hauteurTuile / 3)){

                    _schema[j][i] = 6;
                    h->incNbPoints();
                    if(h->getNbPoints() > 0 && h->getNbPoints()%50 == 0){
                        h->setNbVies(h->getNbVies()+1);
                    }
                }
            }

            if (_tuiles[indicetile].getType() == TypeTuile::VIDE_AVEC_DEGATS){
                if(posHero.y + posHero.h >= (j * _hauteurTuile)+ (_hauteurTuile / 3)
                        && posHero.x <= (i * _largeurTuile) + 2*(_largeurTuile/3)
                        && posHero.x + posHero.w >= (i * _largeurTuile) + (_largeurTuile/3)){
                    if(_schema[j][i] == 10){
                        _schema[j][i] = 11;
                    }
                    if(h->getTimerMort() == 0){
                        h->setTimerMort(30);
                    }
                }
            }

            if (_schema[j][i] == 3){
                if(posHero.x <= (i * _largeurTuile) + 2*(_largeurTuile/3)
                        && posHero.x + posHero.w >= (i * _largeurTuile) + (_largeurTuile/3)
                        && posHero.y + posHero.h >= (j * _hauteurTuile) + 2*(_hauteurTuile / 3)){
                    SDL_Rect posDebutHero = h->getPosTestHero();
                    posDebutHero.y -= 200;
                    h->setPosReelHero(&posDebutHero);
                }
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
            indicetile = _schema[j][i];
            if (_tuiles[indicetile].getType() == TypeTuile::PLEIN){
                return true;
            }
            if (_tuiles[indicetile].getType() == TypeTuile::VIDE_AVEC_DEGATS){
                return true;
            }
            if( i-1 >= 0 && i+1 <=_nbrTuilesEnColonneMonde && j+2 < _nbrTuilesEnLigneMonde){

                if (((_tuiles[_schema[j+2][i]].getType() == TypeTuile::VIDE
                      || _tuiles[_schema[j+2][i]].getType() == TypeTuile::VIDE_AVEC_DEGATS)
                     && _tuiles[_schema[j+2][i-1]].getType() == TypeTuile::PLEIN)
                        || ((_tuiles[_schema[j+2][i]].getType() == TypeTuile::VIDE
                             || _tuiles[_schema[j+2][i]].getType() == TypeTuile::VIDE_AVEC_DEGATS)
                            && _tuiles[_schema[j+2][i+1]].getType() == TypeTuile::PLEIN)) {
                    return true;
                }
            }
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
                } else if( ! typeTuile.compare("piece") ){
                    _tuiles[numTuile].setType(TypeTuile::PIECE);
                } else if( ! typeTuile.compare("fin_niveau") ){
                    _tuiles[numTuile].setType(TypeTuile::FIN_NIVEAU);
                } else {
                    _tuiles[numTuile].setType(TypeTuile::VIDE);
                }
                numTuile++;
            }
        }
    }else{
        throw new ExceptionGame("Votre fichier ne contient pas la balise #typeTuile");
    }

}

bool Monde::finDuNiveau(Hero *h){
    SDL_Rect posHero = h->getPosTestHero();
    int x1, x2, y1, y2,i,j;
    Uint16 indicetile;

    x1 = posHero.x / _largeurTuile;
    y1 = posHero.y / _hauteurTuile;
    x2 = (posHero.x + posHero.w -1) / _largeurTuile;
    y2 = (posHero.y + posHero.h -1) / _hauteurTuile;

    for ( i = x1 ; i <=  x2  ; i++) {
        for ( j = y1 ; j <= y2  ; j++){

            indicetile = _schema[j][i];
            //Si on est sur le bonhomme, on passe au niveau suivant
            if (_tuiles[indicetile].getType() == TypeTuile::FIN_NIVEAU){
                if(this->getNiveauActuel() <= 4){
                    this->setNiveauActuel(this->getNiveauActuel()+1);
                    SDL_Rect posDebutHero = h->getPosTestHero();
                    posDebutHero.x = 0;
                    posDebutHero.y = 0;
                    h->setPosReelHero(&posDebutHero);
                    return true;
                }
            }
        }
    }
    return false;
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
