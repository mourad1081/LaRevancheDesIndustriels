#ifndef HERO_H
#define HERO_H
#include <SDL.h>
#include <SDL_image.h>
#include "vue/monde.h"
#include "metier/evenement.h"
#include "gestionbd.h"

//Valeurs attribuées aux états/directions
#define WALK 1
#define STOPPED 2
#define JUMP 3
#define RIGHT 1
#define LEFT 2

class Monde;
/**
 * @brief Représente le héro du jeu.
 */
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
    int _onGround, _timerMort ;
    //Variables liées au joueur
    int _nbVies, _nbPoints;

    // Constantes pour l'animation
    const int TIME_BETWEEN_2_FRAMES = 3;

    const int VITESSE_JOUEUR = 5;
    const int JUMP_HEIGHT = 20;
    const int GRAVITY_SPEED = 0.8;
    const int MAX_FALL_SPEED = 9;

    int _nb = 0;
    float _gravity = 0.8;

public:
    /*!
     * \brief Constructeur du Hero
     * \param name le nom du sprite
     * \param x la position x
     * \param y la position y
     * \param w la longueur
     * \param h la largeur
     */
    Hero(char * name, int x, int y, int w, int h);
    /*!
     * \brief Destructeur
     */
    ~Hero();
    /*!
     * \brief Methode permettant de dessiner le héro sur l'écran
     * \param screen l'écran
     * \param m le monde
     */
    void drawAnimatedPlayer(SDL_Surface * screen, Monde * m);
    /*!
     * \brief Methode permettant de faire évoluer le héro à l'écran
     * \param evt une événement
     * \param m le monde
     * \param screen l'écran
     */
    void updatePlayer(Evenement * evt, Monde * m, SDL_Surface * screen);
    /*!
     * \brief Methode permettant de faire évoluer le scrolling par rapport
     * à la position du héro à l'écran
     * \param m le monde
     */
    void centerScrollingOnPlayer(Monde * m);

    /*!
     * \brief Methode permettant de retourner la position réelle du héro
     * \return la postion réelle
     */
    SDL_Rect getPosReelleHero();

    /*!
     * \brief Methode permettant de retourner la position test du héro
     * \return la postion test
     */
    SDL_Rect getPosTestHero();
    /*!
     * \brief Methode permettant de modifier la position réelle du héro
     * \param pos la postion réelle
     */
    void setPosReelHero(SDL_Rect *pos);

    /*!
     * \brief Methode permettant de connaitre le timer de la mort du héro
     * Le timer permet de définir un temps d'attente avant la mort
     * \return le temps à attendre (en Msec)
     */
    int getTimerMort();
    /*!
     * \brief Methode permettant de modifier le timer de la mort du héro
     * Le timer permet de définir un temps d'attente avant la mort
     * \param val le temps à attendre (en Msec)
     */
    void setTimerMort(int val);

    /*!
     * \brief Methode permettant de modifier le nb de vie du héro
     * \param nbVies Le nombre de vies
     */
    void setNbVies(int nbVies);
    /*!
     * \brief Methode permettant de connaitre le nb de vie du héro
     * \return Le nombre de vies
     */
    int getNbVies();
    /*!
     * \brief Methode permettant d'augmenter de 1 le nb de points du héro
     */
    void incNbPoints();
    /*!
     * \brief Methode permettant de connaitre le nb de points du héro
     * \return Le nombre de points
     */
    int getNbPoints();
};

#endif // HERO_H
