#include "monstre.h"
Monstre::Monstre()
{
    _sprite = nullptr;
    //On charge les coordonnées du hero
    posReelle.x = 0;
    posReelle.y = 0;
    posReelle.w = 0;
    posReelle.h = 0;

    //On indique l'état et la direction du héro
    _direction = LEFT;
    _etat = WALK;

    //On initialise les variables pour l'animation
    _frameNumber = 0;
    _frameTimer = 0;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    _timerMort = 0;
    _onGround = 0;

    _estMort = false;
}
Monstre::Monstre(char * name, int x, int y, int w, int h)
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
    _etat = WALK;

    //On initialise les variables pour l'animation
    _frameNumber = 0;
    _frameTimer = TIME_BETWEEN_2_FRAMES;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    _timerMort = 0;
    _onGround = 0;

    _estMort = false;
}

Monstre::~Monstre(){
    SDL_FreeSurface(_sprite);
}

void Monstre::drawAnimatedMonster(SDL_Surface * screen, Monde * m)
{
    //On utilise un timer pour animer le héro
    if (_frameTimer <= 0)
    {
        //Lorsqu'il arrive à zéro, on le réinitialise
        _frameTimer = TIME_BETWEEN_2_FRAMES;

        //Et on incrémente notre variable pour passer à la frame suivante
        _frameNumber++;

        //Si on dépasse la frame max, il faut revenir à la première
        //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
        //par la longueur de notre héros : 480 / 40 = 12 frames
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11

        //SOUCIS SEGMENTATION FAULT ET JE VOIS PAS PQ
        if(_frameNumber >= _sprite->w / posReelle.w)
            _frameNumber = 0;
    }else{
        //Sinon, on décrémente notre timer
        _frameTimer--;
    }

    //Ensuite, on peut dessiner le joueur en fonction de la frame choisie

    // Rectangle de destination à blitter
    SDL_Rect dest;

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

void Monstre::updateMonster(Hero * h, Monde * m)
{
    //Cette variable permet d'augmenter la distance de test de collisions
    int valTest= 0;

    //A chaque fois que le monstre se déplace,
    //on va vérifier s'il entre en collision avec des éléments.
    //On utilisera donc une position de test.

    posTest.x = posReelle.x;
    posTest.y = posReelle.y;
    posTest.h = posReelle.h;
    posTest.w = posReelle.w;

    if(_direction == RIGHT)
    {

        //On teste le déplacement vers la droite, le joueur ne sera déplacé que si
        // il n'y a pas de collision.

        posTest.x += VITESSE_MONSTER + valTest;
        if(!m->collisionMonstre(this)){
            posReelle.x += VITESSE_MONSTER;
        }else{
            //Si il y a collision, le monstre change de sens
            _direction = LEFT;
        }

        if(_direction == LEFT)
        {
            _sprite = IMG_Load("img/walkleft.png");
        }
    }
    if(_direction == LEFT)
    {

        //On teste le déplacement vers la gauche, le joueur ne sera déplacé que si
        // il n'y a pas de collision.

        posTest.x -= VITESSE_MONSTER + valTest;
        if(!m->collisionMonstre(this)){
            posReelle.x -= VITESSE_MONSTER;
        }else{
            //Si il y a collision, le monstre change de sens
            _direction = RIGHT;
        }

        if(_direction == RIGHT)
        {
            _sprite = IMG_Load("img/walkright.png");
        }
    }

    //On incrémente la position _y du monstre, ce qui permet de
    //le faire chuter.
    posTest.y += VITESSE_MONSTER + valTest;
    if(!m->collisionMonstre(this)){
        posReelle.y += VITESSE_MONSTER;
        _onGround = 0;
    }else{
        _onGround = 1;
    }

    //Finalement on va tester le
    if (testCollision(h) == 1)
    {
        //On met le timer à 1 pour tuer le joueur intantanément
        h->setTimerMort(1);
    }
    else if (testCollision(h) == 2)
    {
        //On fait rebondir le joueur sur le monstre
        /*h->getPosTestHero().y -= JUMP_HEIGHT + MONSTER_HEIGHT;
        if(!m->collisionPerso(h)){
            h->getPosReelleHero().y -= JUMP_HEIGHT + MONSTER_HEIGHT;
        }*/
        _timerMort = 20;
    }
    if (_timerMort > 0)
    {
        _timerMort--;

        if (_timerMort == 0)
        {
            _estMort = true;
        }
    }
}
//Fonction de gestion des collisions
int Monstre::testCollision(Hero *player)
{
    SDL_Rect posPlayer = player->getPosReelleHero();

    //On teste pour voir s'il n'y a pas collision, si c'est le cas, on renvoie 0
    if ((posPlayer.x > posReelle.x + posReelle.w)
            || (posPlayer.x + posPlayer.w < posReelle.x)
            || (posPlayer.y > posReelle.y + posReelle.h)
            || (posPlayer.y + posPlayer.h < posReelle.y)
            ){
        return 0;
        //Sinon, il y a collision. Si le joueur est au-dessus du monstre (avec une marge
        //de 10 pixels pour éviter les frustrations dues au pixel perfect), on renvoie 2.
        //On devra alors tuer le monstre et on fera rebondir le joueur.
    }else if (posPlayer.y + posPlayer.h < posReelle.y +10)
    {
        return 2;
    }
    //Sinon, on renvoie 1 et c'est le joueur qui meurt...
    else{
        return 1;
    }
}
SDL_Rect Monstre::getPosReelleMonstre()
{
    return posReelle;
}
SDL_Rect Monstre::getPosTestMonstre()
{
    return posTest;
}

int Monstre::getTimerMort(){
    return _timerMort;
}

void Monstre::setTimerMort(int val){
    _timerMort = val;
}

bool Monstre::estMort(){
    return _estMort;
}
bool Monstre::isOnGround(){
    return _onGround;
}
