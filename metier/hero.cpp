#include "hero.h"
Hero::Hero()
{
    _sprite = nullptr;
    //On charge les coordonnées du hero
    posReelle.x = 0;
    posReelle.y = 0;
    posReelle.w = PLAYER_WIDTH;
    posReelle.h = PLAYER_HEIGHT;

    //On initialise les variables pour l'animation
    _frameNumber = 0;
    _frameTimer = 0;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    _timerMort = 0;
    _onGround = 0;

    _nbVies = 3;
    _nbPoints = 0;
}
Hero::Hero(char * name, int x, int y)
{
    //On charge le sprite
    _sprite = IMG_Load(name);
    //On charge les coordonnées du hero
    posReelle.x = x;
    posReelle.y = y;
    posReelle.w = PLAYER_WIDTH;
    posReelle.h = PLAYER_HEIGHT;

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
            if(_frameNumber >= _sprite->w / PLAYER_WIDTH)
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
    dest.w = PLAYER_WIDTH;
    dest.h = PLAYER_HEIGHT;

    // Rectangle source à blitter
    SDL_Rect src;

    //On choisit la bonne frame à blitter
    src.x = _frameNumber * PLAYER_WIDTH;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGHT;

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
    posTest.h = PLAYER_HEIGHT;
    posTest.w = PLAYER_WIDTH;

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

    if ((evt->key[SDLK_UP] ||
         evt->key[SDLK_SPACE]) && _onGround == 1){

        _etat = JUMP;

        posTest.y -= JUMP_HEIGHT;
        if(!m->collisionPerso(this)){
            posReelle.y -= JUMP_HEIGHT;
        }

         double v_x;

         if(_direction == LEFT){
            v_x = -3;
        }else{
            v_x = 3;
        }
        bool collision = false;
        double v_y = -15;
        while(!collision && v_y < 15) {
            posTest.y += v_y;
            posTest.x += v_x;
            if(!m->collisionPerso(this)){
                posReelle.y += v_y;
                posReelle.x += v_x;
            }else{
                collision =true;
            }
            v_y += 0.9;
            this->centerScrollingOnPlayer(m);
            //m->AfficherMonde(screen);
            drawAnimatedPlayer(screen, m);
            //Affiche l'écran
            SDL_Flip(screen);
            SDL_Delay(20);
        }

        if(_direction == LEFT){
            _sprite = IMG_Load("img/jumpleft.png");
        }

        if(_direction ==  RIGHT){
            _sprite = IMG_Load("img/jumpright.png");
        }

    }

    //On incrémente la position y du perso, ce qui permet de
    //le faire chuter.
    posTest.y += VITESSE_JOUEUR +valTest;

    //Le perso passe sous la map et donc meurt.
    if(!m->collisionPerso(this)){
        posReelle.y += VITESSE_JOUEUR;
        //_onGround = 0;
    }else{
        _onGround = 1;
    }

    //On centre le scrolling sur le joueur.
    this->centerScrollingOnPlayer(m);

    if (_timerMort > 0)
    {
        _timerMort--;

        //Mort du joueur.
        if (_timerMort == 0)
        {
            //Possiblité de rajouter un saut comme dans mario.
            //posTest.y -= JUMP_HEIGHT/2;

            posReelle.y = 0;
            posReelle.x = 0;

            //_nbVies--;
        }
    }
    //cout << "_timerMort : " << _timerMort << endl;
    //cout << "nbVies : " << _nbVies << endl;
    //cout << "nbPoints : " << _nbPoints << endl;
}

void Hero::centerScrollingOnPlayer(Monde * m)
{
    //On définit les coordonnées du début de l'affichage de la map par rapport à celles
    //du joueur.
    //Pour centrer le joueur, la map doit donc s'afficher à un demi-écran avant la position
    //du joueur.
    //Puis on "clamp" (limite) l'affichage de l'écran pour ne pas sortir de la map.


    //La map se déplacera sur le joueur, il sera toujours situé au milieu de l'écran.

    m->setHoriScroll( posReelle.x  - (SCREEN_WIDTH / 2));

    //On bloque le scroll sur le début et la fin de la map lorsque
    //le scrolling va trop loin.

    if (m->getHoriScroll() < 0)
    {
        m->setHoriScroll(0);
    }
    else if (m->getHoriScroll() + SCREEN_WIDTH >= m->getMaxX())
    {
        m->setHoriScroll(m->getMaxX() - SCREEN_WIDTH);
    }

    //La map se déplacera sur le joueur, il sera toujours situé au milieu de l'écran.

    m->setVertiScroll( posReelle.y  - (SCREEN_HEIGHT / 2));

    //On bloque le scroll sur le haut et le bas de la map lorsque
    //le scrolling va trop loin.

    if (m->getVertiScroll() < 0)
    {
        m->setVertiScroll(0);
    }
    else if (m->getVertiScroll() + SCREEN_HEIGHT >= m->getMaxY() )
    {
        m->setVertiScroll(m->getMaxY() - SCREEN_HEIGHT);
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

