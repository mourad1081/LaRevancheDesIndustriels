#ifndef HUD_H
#define HUD_H
#include "SDL_ttf.h"
#include "metier/exceptiongame.h"

class Hud
{
public:
    Hud();
    static TTF_Font *loadFont(char *name, int size) throw(ExceptionGame);
    static void closeFont(TTF_Font *font);
    static void drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface * _fenetre);
    static void drawImage(SDL_Surface *image, int x, int y, SDL_Surface * _fenetre);
};

#endif // HUD_H
