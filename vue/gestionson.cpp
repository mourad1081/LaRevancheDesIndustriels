#include "gestionson.h"

GestionSon::GestionSon()
    : GestionSon("son/Game Of Thrones.mp3",
                 44100,
                 MIX_DEFAULT_FORMAT,
                 MIX_DEFAULT_CHANNELS,
                 1024)
{
}

GestionSon::GestionSon(string cheminSon)
    : GestionSon(cheminSon, 44100, MIX_DEFAULT_FORMAT,
                 MIX_DEFAULT_CHANNELS, 1024)
{
}

GestionSon::GestionSon(string cheminSon, int frequence, Uint16 format,
                       int nbCanaux, int tailleChunck)
{
    //Initialisation de l'API Mixer
    if(Mix_OpenAudio(frequence, format, nbCanaux, tailleChunck) == -1)
       throw ExceptionGame(Mix_GetError());

    this->_musique = Mix_LoadMUS(cheminSon.c_str());
    this->_cheminMusique = cheminSon;
    this->_frequence = frequence;
    this->_format = format;
    this->_nombreCanaux = nbCanaux;
    this->_tailleChunk = tailleChunck;
}

GestionSon::~GestionSon()
{
    Mix_FreeMusic(_musique);
    Mix_CloseAudio();
}

void GestionSon::chargerMusiqueEnRAM()
{
    if(_cheminMusique.c_str() != nullptr)
        _musique = Mix_LoadMUS(_cheminMusique.c_str());
    else
        throw ExceptionGame("Erreur : Chemin vers le son introuvable");
}

void GestionSon::demarrerMusique()
{
    chargerMusiqueEnRAM();
    //Paramètre 1 : La musique à jouer
    //Paramètre 2 : Le nombre de fois que la musique doit se répêter
    //(-1 = infini)
    Mix_PlayMusic(_musique, -1);
}

void GestionSon::pause()
{
    if(!Mix_PausedMusic())
        Mix_PauseMusic();
}

void GestionSon::reprendre()
{
    if(Mix_PausedMusic())
        Mix_ResumeMusic();
}

void GestionSon::relancer()
{
    Mix_RewindMusic();
}

void GestionSon::stop()
{
    Mix_HaltMusic();
}

void GestionSon::volume(Uint8 volume)
{
    Mix_VolumeMusic(abs(volume));
}

void GestionSon::changerMusique(std::string chemin)
{
    setCheminMusique(chemin);
    demarrerMusique();
}

Uint16 GestionSon::getFormat() const
{
    return _format;
}

void GestionSon::setFormat(const Uint16 &value)
{
    _format = value;
}

int GestionSon::getNombreCanaux() const
{
    return _nombreCanaux;
}

void GestionSon::setNombreCanaux(int value)
{
    _nombreCanaux = value;
}

int GestionSon::getFrequence() const
{
    return _frequence;
}

void GestionSon::setFrequence(int value)
{
    _frequence = value;
}

int GestionSon::getTailleChunk() const
{
    return _tailleChunk;
}

void GestionSon::setTailleChunk(int value)
{
    _tailleChunk = value;
}

std::string GestionSon::getCheminMusique() const
{
    return _cheminMusique;
}

void GestionSon::setCheminMusique(string value)
{
    _cheminMusique = value;
}
