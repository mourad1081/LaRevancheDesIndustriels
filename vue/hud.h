#ifndef HUD_H
#define HUD_H
#include "SDL_ttf.h"
#include "metier/exceptiongame.h"

class Hud
{
public:
    /*!
     * \brief Constructeur par défaut de la classe Hud
     * Pas utilisé (méthodes statiques)
     */
    Hud();
    /*!
     * \brief Méthode permettant de charger une typographie
     * \param name le nom
     * \param size la taille
     */
    static TTF_Font *loadFont(char *name, int size) throw(ExceptionGame);
    /*!
     * \brief Méthode permettant de fermet une typographie
     * \param font la typo
     */
    static void closeFont(TTF_Font *font);
    /*!
     * \brief Méthode permettant de dessiner une string à l'écran
     * \param text le text
     * \param x la position x
     * \param y la position y
     * \param font la typo
     * \param _fenetre la fenetre
     */
    static void drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface * _fenetre);
    /*!
     * \brief Méthode permettant de dessiner une image à l'écran
     * \param image le sprite
     * \param x la position x
     * \param y la position y
     * \param _fenetre la fenetre
     */
    static void drawImage(SDL_Surface *image, int x, int y, SDL_Surface * _fenetre);
};

#endif // HUD_H
