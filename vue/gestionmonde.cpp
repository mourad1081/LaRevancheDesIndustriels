#include "gestionmonde.h"
GestionMonde::GestionMonde(SDL_Surface * fenetre,
                           int largeurFenetre,
                           int hauteurFenetre)
{
    _fenetre = fenetre;
    _lesEvents = new Evenement();
    _largeurFenetre = largeurFenetre;
    _hauteurFenetre = hauteurFenetre;


    // Charge la police en 32 points (taille)

    _font = Hud::loadFont("font/jokerman.ttf", 42);
    //Variables nécessaires à l'affichage du HUD.
    _HUD_vie = IMG_Load("img/life.png");
    _HUD_etoiles = IMG_Load("img/stars.png");

    _monde = new Monde(largeurFenetre,hauteurFenetre);
    _hero = new Hero("img/walkright.png", 0 ,0, 40, 80);
    _nbMonstres = _monde->getListPosMonstres().size();


    _monstres.resize(_nbMonstres);
    SDL_Rect posMonstre;
    for(int i=0; i < _nbMonstres ; i++)
    {
        posMonstre = _monde->getListPosMonstres()[i];
        _monstres[i] = new Monstre ("img/monstre.png",
                                    posMonstre.x,
                                    posMonstre.y,
                                    40,
                                    65);
    }
}
GestionMonde::~GestionMonde()
{
    //Libère le HUD
    if (_HUD_etoiles != NULL)
    {
        SDL_FreeSurface(_HUD_etoiles);
    }
    if (_HUD_vie != NULL)
    {
        SDL_FreeSurface(_HUD_vie);
    }
}

void GestionMonde::miseAjourJoueurs()
{
    if (_lesEvents->key[SDLK_ESCAPE]
            || _lesEvents->quit
            || _hero->getNbVies() <= 0 )
    {
        exit(0);
    }
    _hero->drawAnimatedPlayer(_fenetre, _monde);
    _hero->updatePlayer(_lesEvents, _monde, _fenetre);
    // passage au niveau suivant
    if ( _monde->finDuNiveau(_hero) )
    {
        _nbMonstres = _monde->getListPosMonstres().size();
        _monstres.clear();
        _monstres.resize(_nbMonstres);

        SDL_Rect posMonstre;
        for(int i=0; i < _nbMonstres ; i++)
        {
            posMonstre = _monde->getListPosMonstres()[i];
            _monstres[i] = new Monstre ("img/monstre.png",
                                        posMonstre.x,
                                        posMonstre.y,
                                        40,
                                        65);
        }
    }
    for(int i=0; i < _nbMonstres ; i++){
        if(!_monstres[i]->estMort()){
            _monstres[i]->drawAnimatedMonster(_fenetre, _monde);
            _monstres[i]->updateMonster(_hero, _monde);
        }
    }
    SDL_Flip(_fenetre);
    SDL_Delay(5);

}

void GestionMonde::miseAjourDeLaMap()
{
    if (_lesEvents->key[SDLK_ESCAPE]
            || _lesEvents->quit
            || _hero->getNbVies() <= 0 )
    {
        exit(0);
    }
    _lesEvents->ActiveAttenteEvenement();
    _monde->AfficherMonde(_fenetre);
}

void GestionMonde::drawHUD()
{
    //On crée une varuiable qui contiendra notre texte (jusqu'à 200 caractères, y'a de la marge ;) ).
    char text[200];

    // Affiche le nombre de vies en bas à droite
    Hud::drawImage(_HUD_vie, _largeurFenetre - 200 , _hauteurFenetre - 100,_fenetre);
    //Pour afficher le nombre de vies, on formate notre string pour qu'il prenne la valeur de la variable
    sprintf(text, "%d", _hero->getNbVies());
    //Puis on utilise notre fonction créée précédemment
    Hud::drawString(text, _largeurFenetre - 75, _hauteurFenetre - 92, _font, _fenetre);

    // Affiche le nombre d'étoiles en haut à gauche
    Hud::drawImage(_HUD_etoiles, 60, 60, _fenetre);
    sprintf(text, "%d", _hero->getNbPoints());
    Hud::drawString(text, 150, 62, _font, _fenetre);
}
