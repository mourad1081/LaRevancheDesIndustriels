#include "hero.h"
Hero::Hero()
{
    _sprite = nullptr;
    //On charge les coordonnées du hero
    posReelle.x = 0;
    posReelle.y = 0;
    posReelle.w = 0;
    posReelle.h = 0;

    //On initialise les variables pour l'animation
    _frameNumber = 0;
    _frameTimer = 0;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    _timerMort = 0;
    _onGround = 0;

    _nbVies = 3;
    _nbPoints = 0;
}
Hero::Hero(char * name, int x, int y, int w, int h)
{
    //On charge le sprite
    _sprite = IMG_Load(name);
    //On charge les coordonnées du hero
    posReelle.x = x;
    posReelle.y = y;
    posReelle.w = w;
    posReelle.h = h;

    //On indique l'état et la direction du héro
    _direction = RIGHT;
    _etat = STOPPED;

    //On initialise les variables pour l'animation
    _frameNumber = 0;
    _frameTimer = TIME_BETWEEN_2_FRAMES;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    _timerMort = 0;
    _onGround = 0;

    _nbVies = 3;
    _nbPoints = 0;

}

Hero::~Hero(){
    SDL_FreeSurface(_sprite);
}

void Hero::drawAnimatedPlayer(SDL_Surface * screen, Monde * m)
{
    //On utilise un timer pour animer le héro
    if(_etat == WALK){
        if (_frameTimer <= 0)
        {
            //Lorsqu'il arrive à zéro, on le réinitialise
            _frameTimer = TIME_BETWEEN_2_FRAMES;

            //On passe à la frame suivante
            _frameNumber++;

            //Si on dépasse la frame max, il faut revenir à la première
            //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
            //par la longueur de notre héros : 480 / 40 = 12 frames
            //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11
            if(_frameNumber >= _sprite->w / posReelle.w)
                _frameNumber = 0;
        }else{
            //Sinon, on décrémente notre timer
            _frameTimer--;
        }
    }else{
        _frameNumber = 0;
    }

    //Ensuite, on peut dessiner le joueur en fonction de la frame choisie

    // Rectangle de destination à blitter
    SDL_Rect dest;

    // On soustrait des coordonnées de notre héros, ceux du début de la map, pour qu'il colle
    //au scrolling :
    dest.x = posReelle.x - m->getHoriScroll();
    dest.y = posReelle.y - m->getVertiScroll();
    dest.w = posReelle.w;
    dest.h = posReelle.h;

    // Rectangle source à blitter
    SDL_Rect src;

    //On choisit la bonne frame à blitter
    src.x = _frameNumber * posReelle.w;
    src.y = 0;
    src.w = posReelle.w;
    src.h = posReelle.h;

    // Blitte notre héros sur l'écran aux coordonnées x et y
    SDL_BlitSurface(_sprite, &src, screen, &dest);
}

void Hero::updatePlayer(Evenement * evt, Monde * m, SDL_Surface * screen)
{
    //Cette variable permet d'augmenter la distance de test de collisions
    int valTest= 0;

    //A chaque fois que l'on va déplacer notre joueur,
    //on va vérifier s'il entre en collision avec des éléments.
    //On utilisera donc une position de test.

    posTest.x = posReelle.x;
    posTest.y = posReelle.y;
    posTest.h = posReelle.h;
    posTest.w = posReelle.w;

    //std::cout << "_x" << posReelle.x << endl;
    //std::cout << "_y" << posReelle.y << endl;


    //On défini l'état du perso
    _etat = STOPPED;

    if (evt->key[SDLK_LEFT])
    {
        _etat = WALK;

        //On teste le déplacement vers la gauche, le joueur ne sera déplacé que si
        // il n'y a pas de collision.

        posTest.x -= VITESSE_JOUEUR + valTest;
        if(!m->collisionPerso(this)){
            posReelle.x -= VITESSE_JOUEUR;
        }

        //On teste le sens pour l'animation : si le joueur allait dans le sens contraire
        //précédemment, il faut recharger le spritesheet pour l'animation.
        if(_direction == RIGHT)
        {
            _direction = LEFT;
            _sprite = IMG_Load("img/walkleft.png");
        }
    }

    if (evt->key[SDLK_RIGHT])
    {
        _etat = WALK;

        //On teste le déplacement vers la droite, le joueur ne sera déplacé que si
        // il n'y a pas de collision.

        posTest.x += VITESSE_JOUEUR + valTest;
        if(!m->collisionPerso(this)){
            posReelle.x += VITESSE_JOUEUR;
        }

        if(_direction == LEFT)
        {
            _direction =  RIGHT;
            _sprite = IMG_Load("img/walkright.png");
        }
    }
    if(evt->key[SDLK_UP] && _nb <= 20){
        _nb++;
        _etat = JUMP;
        posTest.y -= JUMP_HEIGHT;
        if(!m->collisionPerso(this)){
            posReelle.y -= JUMP_HEIGHT;
        }

        /*if(_direction == LEFT)
        {
            _sprite = IMG_Load("img/jumpleft.png");
        }else
        {
            _sprite = IMG_Load("img/jumpright.png");
        }*/
    }
    //On incrémente la position y du perso, ce qui permet de
    //le faire chuter.

    posTest.y += _gravity;
    if(!m->collisionPerso(this)){
        posReelle.y += _gravity;
    }else{
        _nb = 0;
        _gravity = 0.8;
    }
    _gravity += _gravity;
    if(_gravity >= MAX_FALL_SPEED)
    {
        _gravity = MAX_FALL_SPEED;
    }


    //On centre le scrolling sur le joueur.
    this->centerScrollingOnPlayer(m);



    if (_timerMort > 0)
    {
        _timerMort--;

        //Mort du joueur.
        if (_timerMort == 0)
        {
            _nb = 0;
            posReelle.x = 0;
            posReelle.y = 0;
            //_nbVies--;
        }
    }
    if(_estMort){
    }
    //cout << "_timerMort : " << _timerMort << endl;
    //cout << "nbVies : " << _nbVies << endl;
    //cout << "nbPoints : " << _nbPoints << endl;


    //cout << "posReelle.x : "<< posReelle.x << endl;
    //cout << "posReelle.y : "<< posReelle.y << endl;
    //cout << "_onGround : "<< _onGround << endl;
    //cout << "_gravity : "<< _gravity << endl;
    cout << "_nb : "<< _nb << endl;


}

void Hero::centerScrollingOnPlayer(Monde * m)
{
    //On définit les coordonnées du début de l'affichage de la map par rapport à celles
    //du joueur.
    //Pour centrer le joueur, la map doit donc s'afficher à un demi-écran avant la position
    //du joueur.
    //Puis on "clamp" (limite) l'affichage de l'écran pour ne pas sortir de la map.


    //La map se déplacera sur le joueur, il sera toujours situé au milieu de l'écran.

    m->setHoriScroll( posReelle.x  - (m->getLargeurFenetre() / 2));

    //On bloque le scroll sur le début et la fin de la map lorsque
    //le scrolling va trop loin.

    if (m->getHoriScroll() < 0)
    {
        m->setHoriScroll(0);

    }
    else if (m->getHoriScroll() + m->getLargeurFenetre() >= m->getMaxX())
    {
        m->setHoriScroll(m->getMaxX() - m->getLargeurFenetre());
    }

    //La map se déplacera sur le joueur, il sera toujours situé au milieu de l'écran.

    m->setVertiScroll( posReelle.y  - (m->getHauteurFenetre() / 2));

    //On bloque le scroll sur le haut et le bas de la map lorsque
    //le scrolling va trop loin.

    if (m->getVertiScroll() < 0)
    {
        m->setVertiScroll(0);
    }
    else if (m->getVertiScroll() + m->getHauteurFenetre() >= m->getMaxY() )
    {
        m->setVertiScroll(m->getMaxY() - m->getHauteurFenetre());
    }
}

SDL_Rect Hero::getPosReelleHero()
{
    return posReelle;
}
SDL_Rect Hero::getPosTestHero()
{
    return posTest;
}

int Hero::getTimerMort(){
    return _timerMort;
}

void Hero::setTimerMort(int val){
    _timerMort = val;
}

void Hero::setNbVies(int nbVies){
    _nbVies = nbVies;
}

int Hero::getNbVies(){
    return _nbVies;
}

void Hero::incNbPoints(){
    _nbPoints++;
}

int Hero::getNbPoints(){
    return _nbPoints;
}

