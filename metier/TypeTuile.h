#ifndef TYPETUILE_H
#define TYPETUILE_H


/*!
 * \brief Représente le type d'une tuile
 */
enum class TypeTuile : unsigned short{
    VIDE,/*On peut traverser*/
    PLEIN,/*On peut pas traverser, c'est un obstacle*/
    PIECE,/*C'est une piece on peut traverser*/
    FIN_NIVEAU,/*On peut traverser et indique la fin du niveau en cour*/
    VIDE_AVEC_DEGATS /*On peut traverser mais on meurt, ou on reçoit des dégats*/
};


#endif // TYPETUILE_H
