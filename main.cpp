#include "vue/application.h"
#include <QApplication>
#include <iostream>
#include "SDL.h"
#include "metier/hero.h"
#include "metier/monstre.h"
#include "vue/monde.h"
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
    SDL_Surface * fenetre = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,
                                             32,SDL_HWSURFACE);

    // renomer la fenetre
    SDL_WM_SetCaption("Jeu de plateforme", NULL);

    // demander une couleur en UINT32
    // SDL_MAPRGB(format de couleur de la surface,R,V,B)
    // Uint32 couleurFond = SDL_MapRGB(fenetre->format,164,0,0); //bleu ciel
    // remplir une surface d'une couleur
    // param -> la Surface a remplir, la partie de la surface, la couleur UINT32
    //SDL_FillRect(fenetre,NULL,couleurFond);


    Monde * m;
    Hero * hero;
    Monstre * monstres[NB_MONSTRES];

    try{

        m = new Monde();
        hero = new Hero("img/walkright.png", 0, 0);
        Evenement * evt = new Evenement();

        float randomX;
        for(int i=0; i < NB_MONSTRES ; i++)
        {
            randomX = rand()%m->getMaxX();
            //randomX = 400;
            monstres[i] = new Monstre ("img/walkright.png", randomX ,300);
        }

        while(!evt->key[SDLK_ESCAPE] && !evt->quit && hero->getNbVies() > 0){
            m->AfficherMonde(fenetre);
            evt->ActiveAttenteEvenement();
            hero->drawAnimatedPlayer(fenetre, m);
            hero->updatePlayer(evt, m, fenetre);

            for(int i=0; i < NB_MONSTRES ; i++)
            {
                if(!monstres[i]->estMort()){
                    monstres[i]->drawAnimatedMonster(fenetre, m);
                    monstres[i]->updateMonster(hero, m);
                }
            }

            //Affiche l'écran
            SDL_Flip(fenetre);
            //Delai
            SDL_Delay(5);
        }


    }catch(ExceptionGame eg){
        cerr << eg.what() << endl;
        SDL_FreeSurface(fenetre);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // libere la memoire
    //delete(hero);
    SDL_FreeSurface(fenetre);
    SDL_Quit();
    exit(EXIT_SUCCESS);

}
