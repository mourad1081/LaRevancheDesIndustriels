#include "hud.h"

Hud::Hud(){}

TTF_Font * Hud::loadFont(char *name, int size) throw(ExceptionGame)
{
    /* Utilise SDL_TTF pour charger la police à la taille désirée */

    TTF_Font *font = TTF_OpenFont(name, size);

    if (font == NULL)
    {
        throw new ExceptionGame("Failed to open Font\n");
    }

    return font;
}


void Hud::closeFont(TTF_Font *font)
{
    /* Ferme la police quand on n'en a plus besoin (avant de quitter) */

    if (font != NULL)
    {
        TTF_CloseFont(font);
    }
}


void Hud::drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface * _fenetre)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor;

    /* On choisit d'écrire le texte en doré */
    foregroundColor.r = 255;
    foregroundColor.g = 204;
    foregroundColor.b = 2;


    /* On utilise SDL_TTF pour générer une SDL_Surface à partir
     *  d'une chaîne de caractères (string)
     */

    surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);


    if (surface == NULL)
    {
        printf("Couldn't create String %s: %s\n", text, SDL_GetError());
        return;
    }

    /* On blitte cette SDL_Surface à l'écran */

    dest.x = x;
    dest.y = y;
    dest.w = surface->w;
    dest.h = surface->h;

    SDL_BlitSurface(surface, NULL, _fenetre, &dest);

    /* On libère la SDL_Surface temporaire
     *  (pour éviter les fuites de mémoire - cf. chapitre dédié)
     */
    SDL_FreeSurface(surface);
}
void Hud::drawImage(SDL_Surface *image, int x, int y, SDL_Surface * _fenetre)
{
    SDL_Rect dest;

    /* Règle le rectangle à blitter selon la taille de l'image source */

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    /* Blitte l'image entière sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(image, NULL, _fenetre, &dest);
}
