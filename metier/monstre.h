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
    /*!
     * \brief Constructeur du Monstre
     * \param name le nom du sprite
     * \param x la position x
     * \param y la position y
     * \param w la longueur
     * \param h la largeur
     */
    Monstre(char * name, int x, int y, int w, int h);
    /*!
     * \brief Destructeur
     */
    ~Monstre();
    /*!
     * \brief Methode permettant de dessiner le monstre sur l'écran
     * \param screen l'écran
     * \param m le monde
     */
    void drawAnimatedMonster(SDL_Surface * screen, Monde * m);
    /*!
     * \brief Methode permettant de faire évoluer le mosntre à l'écran
     * \param h le héro
     * \param m le monde
     */
    void updateMonster(Hero * h, Monde * m);
    /*!
     * \brief Methode permettant de retourner la position réelle du monstre
     * \return la postion réelle
     */
    SDL_Rect getPosReelleMonstre();
    /*!
     * \brief Methode permettant de retourner la position test du monstre
     * \return la postion test
     */
    SDL_Rect getPosTestMonstre();

    /*!
     * \brief Methode permettant de connaitre le timer de la mort du monstre
     * Le timer permet de définir un temps d'attente avant la mort
     * \return le temps à attendre (en Msec)
     */
    int getTimerMort();
    /*!
     * \brief Methode permettant de modifier le timer de la mort du monstre
     * Le timer permet de définir un temps d'attente avant la mort
     * \param val le temps à attendre (en Msec)
     */
    void setTimerMort(int val);
    /*!
     * \brief Methode permettant de savoir si le monstre est mort
     * On utilise cette méthode pour ne pas afficher le monstre lorsqu'il est mort
     * \return vrai ou faux
     */
    bool estMort();
};

#endif // MONSTRE_H
