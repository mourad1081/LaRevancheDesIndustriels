#ifndef HERO_H
#define HERO_H
#include <SDL.h>
#include <SDL_image.h>
#include "vue/monde.h"
#include "metier/evenement.h"

// Taille du sprite de notre héros (largeur = width et hauteur = heigth)
#define PLAYER_WIDTH 40
#define PLAYER_HEIGHT 80
// Constantes pour l'animation
#define TIME_BETWEEN_2_FRAMES 8
//Valeurs attribuées aux états/directions
#define WALK 1
#define STOPPED 2
#define JUMP 3
#define RIGHT 1
#define LEFT 2

// Constante définissant le seuil entre les tiles traversables
#define VITESSE_JOUEUR 3
#define BLANK_TILE 5

//Constantes définissant la gravité et la vitesse max de chute
#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define JUMP_HEIGHT 12

class Monde;
class Hero
{
private:
    //Sprite du Héro
    SDL_Surface* _sprite;

    //Coordonnées héro
    SDL_Rect posReelle;

    //Position de test pour les collisions
    SDL_Rect posTest;

    //Variables utiles pour animation
    int _frameNumber, _frameTimer;
    //Variables utiles au déplacement
    int _etat, _direction;
    //Variables nécessaires au fonctionnement de la gestion des collisions
    int _onGround, _timerMort;
    //Variables liées au joueur
    int _nbVies, _nbPoints;

public:
    Hero();
    ~Hero();
    Hero(char * name, int x, int y);
    void drawAnimatedPlayer(SDL_Surface * screen, Monde * m);
    void updatePlayer(Evenement * evt, Monde * m, SDL_Surface * screen);
    void centerScrollingOnPlayer(Monde * m);

    SDL_Rect getPosReelleHero();
    SDL_Rect getPosTestHero();

    int getTimerMort();
    void setTimerMort(int val);

    void setNbVies(int nbVies);
    int getNbVies();

    void incNbPoints();
    int getNbPoints();
};

#endif // HERO_H
