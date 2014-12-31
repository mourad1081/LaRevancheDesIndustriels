#ifndef GESTIONSON_H
#define GESTIONSON_H
#include "SDL_mixer.h"
#include "metier/exceptiongame.h"
#include <QString>
class GestionSon
{
private:
    Mix_Music *_musique;
    std::string _cheminMusique;
    int _frequence;
    Uint16 _format;
    int _nombreCanaux;
    int _tailleChunk;

    void chargerMusiqueEnRAM();
public:
    //-------- CONSTRUCTEURS --------//
    GestionSon();
    GestionSon(std::string cheminSon);
    GestionSon(std::string cheminSon, int _frequence,
               Uint16 format, int nbCanaux, int tailleChunck);
    virtual ~GestionSon();

    //----------- GESTION -----------//
    void demarrerMusique();
    void pause();
    void reprendre();
    void relancer();
    void stop();
    void volume(Uint8 volume);
    void changerMusique(std::string chemin);
    //-----ACCESSEUR ET MUTATEURS----//
    int getFrequence() const;
    void setFrequence(int value);
    Uint16 getFormat() const;
    void setFormat(const Uint16 &value);
    int getNombreCanaux() const;
    void setNombreCanaux(int value);
    int getTailleChunk() const;
    void setTailleChunk(int value);
    string getCheminMusique() const;
    void setCheminMusique(std::string value);
};

#endif // GESTIONSON_H
