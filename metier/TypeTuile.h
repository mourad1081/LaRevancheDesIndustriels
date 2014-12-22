#ifndef TYPETUILE_H
#define TYPETUILE_H


/*!
 * \brief Représente le type d'une tuile
 */
enum class TypeTuile : unsigned short{
    VIDE,/*On peut traverser*/
    PLEIN,/*On peut pas traverser, c'est un obstacle*/
    VIDE_AVEC_DEGATS /*On peut traverser mais on meurt, ou on reçoit des dégats*/
};


#endif // TYPETUILE_H
