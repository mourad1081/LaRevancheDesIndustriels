#include "vue/application.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "vue/gestionmonde.h"
#include "vue/gestionson.h"
#undef main
using namespace std;
void lancerApplication();

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    Application app;
    app.show();
    a.exec();
    if(!app.getClicQuit())
    {
        lancerApplication();
    }
}

void lancerApplication()
{
    // initialise SDL
    if ( SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        cerr << "Erreur d'initialisation de SDL" << endl;
        exit(EXIT_FAILURE);
    }
    // notre fenetre ,param (taille,taille,couleur,option)
   SDL_Surface * fenetre = SDL_SetVideoMode(0, 0, 32,
                                             SDL_HWSURFACE
                                             | SDL_FULLSCREEN
                                             | SDL_DOUBLEBUF);


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
        gestionMonde = new GestionMonde(fenetre, fenetre->w, fenetre->h);
        while(true){
            gestionMonde->miseAjourDeLaMap();
            gestionMonde->miseAjourJoueurs();
        }
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
