#ifndef TUILE_H
#define TUILE_H

#include <metier/TypeTuile.h>
#include <SDL.h>


/*!
 * \brief Représente une Tuile qui est caractérisé
 * par un type et un rectangle
 */

class Tuile
{
public:
    Tuile();
    SDL_Rect& getRectangle();
    TypeTuile getType()const;
    /*!
     * \brief Configure le rectangle, une tuile occupe une
     * place dans la fenetre (un rectangle)
     * \param l largeur du rectangle
     * \param h hauteur du rectangle
     * \param x coordonnée x du rectangle
     * \param y coordonnée y du rectangle
     */
    void setRectangle(int l,int h,int x,int y);
    /*!
     * \brief Donne un type a la tuile (voir TypeTuile)
     * \param type le type de la tuile
     */
    void setType(TypeTuile type);
private:
    SDL_Rect _rectangle;
    TypeTuile _type;
};

#endif // TUILE_H
