#ifndef GESTIONSON_H
#define GESTIONSON_H
#include "SDL_mixer.h"
#include "metier/exceptiongame.h"
class GestionSon
{
private:
    Mix_Music *_musique;
    char *_cheminMusique;
    int _frequence;
    Uint16 _format;
    int _nombreCanaux;
    int _tailleChunk;
public:
    //-------- CONSTRUCTEURS --------//
    GestionSon();
    GestionSon(char *cheminSon);
    GestionSon(char * cheminSon, int _frequence,
               Uint16 format, int nbCanaux, int tailleChunck);
    virtual ~GestionSon();

    //----------- GESTION -----------//
    void chargerMusique();
    void demarrerMusique();
    void pause();
    void reprendre();
    void relancer();
    void stop();

    //-----ACCESSEUR ET MUTATEURS----//
    int getFrequence() const;
    void setFrequence(int value);
    Uint16 getFormat() const;
    void setFormat(const Uint16 &value);
    int getNombreCanaux() const;
    void setNombreCanaux(int value);
    int getTailleChunk() const;
    void setTailleChunk(int value);
    char *getCheminMusique() const;
    void setCheminMusique(char *value);
};

#endif // GESTIONSON_H
