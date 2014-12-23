#include "monde.h"

Monde::Monde(int largeurFenetre , int hauteurFenetre)  throw(ExceptionGame)
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
