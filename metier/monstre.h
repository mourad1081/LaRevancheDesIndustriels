#ifndef MONSTRE_H
#define MONSTRE_H
#include <SDL.h>
#include <SDL_image.h>
#include "vue/monde.h"
#include "metier/evenement.h"
#include "metier/hero.h"

// Taille du sprite de notre héros (largeur = width et hauteur = heigth)
#define MONSTER_WIDTH 40
#define MONSTER_HEIGHT 80

#define VITESSE_MONSTER 1
// Constantes pour l'animation
#define TIME_BETWEEN_2_FRAMES 8
//Valeurs attribuées aux états/directions
#define WALK 1
#define RIGHT 1
#define LEFT 2

#define NB_MONSTRES 1
class Monde;
class Hero;
class Monstre
{
private:
    //Sprite du monstre
    SDL_Surface* _sprite;

    //Coordonnées monstre
    SDL_Rect posReelle;

    //Position de test pour les collisions
    SDL_Rect posTest;

    //Variables utiles pour animation
    int _frameNumber, _frameTimer;
    int _etat, _direction;
    int _onGround, _timerMort;


    bool _estMort;
public:
    Monstre();
    ~Monstre();
    Monstre(char * name, int x, int y);
    void drawAnimatedMonster(SDL_Surface * screen, Monde * m);
    void updateMonster(Hero * h, Monde * m);
    int testCollision(Hero * h);

    SDL_Rect getPosReelleMonstre();
    SDL_Rect getPosTestMonstre();

    int getTimerMort();
    void setTimerMort(int val);

    bool estMort();
    bool isOnGround();

};

#endif // MONSTRE_H
