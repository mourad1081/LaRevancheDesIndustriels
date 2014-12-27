#ifndef EXCEPTIONGAME_H
#define EXCEPTIONGAME_H

#include <exception>
#include <iostream>
#include <sstream>

using namespace std;

/*!
 * \brief Exception lier au  jeu.
 */
class ExceptionGame  : public std::exception {

private :
    string msgErreur;

public:
    /*!
     * \brief Constructeur par défaut.
     */
    ExceptionGame();
    /*!
     * \brief Constructeur.
     * \param msgErreur le message d'erreur.
     */
    ExceptionGame(string msgErreur);
    /*!
     * \brief Méthode indiquant quel est le message d'erreur.
     * \return le messsage d'erreur.
     */
    virtual const char * what() const throw();
};

#endif // EXCEPTIONGAME_H
