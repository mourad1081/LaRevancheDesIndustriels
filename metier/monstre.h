#ifndef MONSTRE_H
#define MONSTRE_H
#include <SDL.h>
#include <SDL_image.h>
#include "vue/monde.h"
#include "metier/evenement.h"
#include "metier/hero.h"
#include "vue/gestionson.h"

// Constantes pour l'animation
//Valeurs attribuées aux états/directions
#define WALK 1
#define RIGHT 1
#define LEFT 2

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

    // Constantes pour l'animation
    const int TIME_BETWEEN_2_FRAMES = 8;

    // Constante définissant le seuil entre les tiles traversables
    const int VITESSE_MONSTER = 1;

public:
    Monstre();
    ~Monstre();
    Monstre(char * name, int x, int y, int w, int h);
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
