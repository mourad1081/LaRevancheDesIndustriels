#include "vue/application.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include "SDL.h"
#include "vue/gestionmonde.h"
#undef main

using namespace std;

int main(int argc, char **argv) {

    /*
    QApplication a(argc, argv);
    Application w;
    w.show();*/

    // initialise SDL
    if ( SDL_Init(SDL_INIT_VIDEO) == -1) {
        cerr << "Erreur d'initialisation de SDL" << endl;
        exit(EXIT_FAILURE);
    }
    // notre fenetre ,param (taille,taille,couleur,option)
    SDL_Surface * fenetre = SDL_SetVideoMode(600,600,
                                             32,SDL_HWSURFACE);

    // renomer la fenetre
    SDL_WM_SetCaption("Jeu de plateforme", NULL);

    // demander une couleur en UINT32
    // SDL_MAPRGB(format de couleur de la surface,R,V,B)
    // Uint32 couleurFond = SDL_MapRGB(fenetre->format,164,0,0); //bleu ciel
    // remplir une surface d'une couleur
    // param -> la Surface a remplir, la partie de la surface, la couleur UINT32
    //SDL_FillRect(fenetre,NULL,couleurFond);


    GestionMonde * gestionMonde;

    try{

        gestionMonde = new GestionMonde(fenetre,600, 600);

    }catch(ExceptionGame eg){
        cerr << eg.what() << endl;
        SDL_FreeSurface(fenetre);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // libere la memoire
    SDL_FreeSurface(fenetre);
    SDL_Quit();
    exit(EXIT_SUCCESS);

}
