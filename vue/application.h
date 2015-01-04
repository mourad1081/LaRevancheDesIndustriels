#ifndef APPLICATION_H
#define APPLICATION_H
#include <QMessageBox>
#include <QMainWindow>
#include <QMovie>
#include "parametresson.h"
#include "gestionson.h"
#include "choixmusique.h"
#include <string>
#include <QMediaPlayer>
#include <metier/gestionbd.h>
#include "historiquescore.h"

class ParametresSon;
namespace Ui {
class Application;
}

/**
 * @brief Représente l'interface graphique avant le commencement du jeu
 */
class Application : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur de l'interface graphique
     * @param parent Parent de la fenêtre
     */
    explicit Application(QWidget *parent = 0);

    /**
     * @brief Destructeur de l'interface graphique
     */
    ~Application();

    /**
     * @brief Permet de savoir si l'utilisateur a cliqué sur "QUITTER"
     *  ou a fermé la fenêtre
     * @return true = oui, false = non
     */
    bool getClicQuit() const;

    /**
     * @brief Permet de définir si l'utilisateur a cliqué sur "QUITTER"
     * ou a fermé la fenêtre
     * @param value true = oui, false = non
     */
    void setClicQuit(bool value);

private slots:

    /**
     * @brief Quitte l'interface graphique
     */
    void on_btnQuitter_clicked();

    /**
     * @brief Démarre une nouvelle partie
     */
    void on_btnNouvellePartie_clicked();

    /**
     * @brief Permet de pénétrer les serveurs de la NASA proprement.
     * La méthode généralement utilisée est du brute-force. Mon algorithme
     * est basé sur du brute-force Mouradien. C'est-à-dire que par
     * supposition suppositoire, j'estime qu'envoyer des paquets cryptés
     * en SHA-4096 son quantitativements, qualitativements et
     * anticonstitutionnellements plus propres et rapides
     * que la méthode classique du brute-force.
     *
     * Ainsi, par décrèt nucléariste, si je fais un gros
     * QMessageBox des campagnes, des familles et des cousins,
     * la NASA sera subjuguée et pensera que je suis un des leurs. CQFD
     * Cet algorithme est protégé par loi martiale, droits d'auteurs et est
     * brevété depuis 1756 après Christophe Columbo.
     */
    void on_btnHackNASA_clicked();

    /**
     * @brief Permet de faire apparaître une fenêtre gérant différentes options
     */
    void on_btnOptions_clicked();

    /**
     * @brief Permet de changer le thème (la musique) du jeu.
     */
    void on_btnMusique_clicked();

    void on_historiqueScores_clicked();

private:
    Ui::Application *ui;
    bool _clicQuit;

    //---Paramètres---//
    QMediaPlayer *_theme;
    QMediaPlaylist *_playlist;

    //--- GIF du pokémon chetiflor qui dance pendant l'intro ---//
    QMovie *_chetiflorQuiDance;
};

#endif // APPLICATION_H
