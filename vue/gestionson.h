#ifndef GESTIONSON_H
#define GESTIONSON_H
#include "SDL_mixer.h"
#include "metier/exceptiongame.h"
#include <QString>

/**
 * @brief Classe permettant la gestion du son lors du lancement du jeu
 */
class GestionSon
{
private:
    Mix_Music *_musique; /** La musique à jouer */
    std::string _cheminMusique; /** La chemin vers la musique à jouer */
    int frequence; /** Lafréquence de la musique */
    Uint16 _format; /** Le format de la musique */
    int _nombreCanaux; /** Le nombre de canaux que doit utiliser SDL_Mixer */
    int _tailleChunk;  /** Le nombre de chunks */

    /**
     * @brief Permet de charger en RAM la musique dont le chemin se trouve dans
     * _cheminMusique
     */
    void chargerMusiqueEnRAM();
public:
    //-------- CONSTRUCTEURS --------//

    /**
     * @brief Construit un gestionnaire de son avec des paramètres par défauts
     */
    GestionSon();

    /**
     * @brief Construit un gestionnaire de son avec une musique directement
     * @param cheminSon Chemin vers la musique à jouer
     */
    GestionSon(std::string cheminSon);

    /**
     * @brief Construit un gestionnaire de son personnalisé
     * @param cheminSon Chemin vers la musique à jouer
     * @param frequence Fréquence de la musique (en Hz)
     * @param format Format de la musique (MIX_DEFAULT_FORMAT par défaut)
     * @param nbCanaux Nombre de canaux
     * (1 : mono, 2 ou MIX_DEFAULT_CHANNELS : stéréo)
     * @param tailleChunck Le nombre de bits pour les sons (1024 suffit)
     */
    GestionSon(std::string cheminSon, int frequence,
               Uint16 format, int nbCanaux, int tailleChunck);

    /**
     * @brief Destructeur du gestionnaire de son
     */
    virtual ~GestionSon();

    //----------- GESTION -----------//

    /**
     * @brief Permet de démarrer la lecture de la musique
     */
    void demarrerMusique();

    /**
     * @brief Permet de démarrer la lecture d'un son X fois
     * @param chemin Le chemin vers le son
     * @param nbRepetition Le nombre de répétitions
     */
    void demarrerBruitage(std::string chemin, int nbRepetition);

    /**
     * @brief Met la musique en pause
     */
    void pause();

    /**
     * @brief Reprend la lecture de la musique si elle était en pause
     */
    void reprendre();

    /**
     * @brief Relance la musique
     */
    void relancer();

    /**
     * @brief Arrête complètement la musique (différent de pause qui, elle,
     * permet de reprendre là où on s'est arrêté)
     */
    void stop();

    /**
     * @brief Permet de modifier le volume (0 à 127)
     * @param volume Le nouveau volume
     */
    void volume(Uint8 volume);

    /**
     * @brief Permet de changer de musique en
     * fournissant le chemin vers le nouveau son
     * @param chemin Chemin de la musique à jouer
     */
    void changerMusique(std::string chemin);

    /**
     * @brief Accesseur en lecture du chemin de la musique jouée
     * @return Le chemin vers la musique jouée
     */
    string getCheminMusique() const;
};

#endif // GESTIONSON_H
