#include "exceptiongame.h"

ExceptionGame::ExceptionGame(){
    std::ostringstream oss;
    oss << "ERREUR NON DEFINNIE !\n";
    this->msgErreur = oss.str();
}

ExceptionGame::ExceptionGame(string msg){
    std::ostringstream oss;
    oss << "ERREUR : " << msg << "\n";
    this->msgErreur = oss.str();
}

const char *ExceptionGame::what()const throw(){
    return this->msgErreur.c_str();
}
