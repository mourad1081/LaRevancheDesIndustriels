#include "vue/application.h"
#include <QApplication>
#include <iostream>
#include "vue/gestionmonde.h"
#include "SDL.h"
#undef main

using namespace std;
int main(int argc, char **argv)
{
    /*
    QApplication a(argc, argv);
    Application w;
    w.show();*/

    try {
        // initialise SDL
        if ( SDL_Init(SDL_INIT_VIDEO) == -1){
            cerr << "Erreur d'initialisation de SDL" << endl;
            exit(EXIT_FAILURE);
        }

        // notre fenetre ,param (taille,taille,couleur,option)
        SDL_Surface * fenetre = SDL_SetVideoMode(600,600,32,SDL_HWSURFACE);
        GestionMonde g(fenetre,600,600);
        while (1) {
            g.miseAjourDeLaMap();
            SDL_Delay(50);
        }

    }catch(ExceptionGame eg){
        cerr << eg.what();
    }
    /* return a.exec();*/
}
