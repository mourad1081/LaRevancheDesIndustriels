#ifndef APPLICATION_H
#define APPLICATION_H
#include <QMessageBox>
#include <QMainWindow>
#include <QMovie>
#include "parametresson.h"
#include "gestionson.h"
class ParametresSon;
namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT
public:
    explicit Application(QWidget *parent = 0);
    ~Application();

    bool getClicQuit() const;
    void setClicQuit(bool value);

private slots:
    void on_btnQuitter_clicked();
    void on_btnNouvellePartie_clicked();
    void on_btnHackNASA_clicked();
    void on_btnOptions_clicked();

private:
    Ui::Application *ui;
    bool _clicQuit;

    //---Paramètres---//
    GestionSon _musique;
    bool _sonActif;
    bool _jouerAMusiqueALinfini;
    int _nbVies;
    Difficulte _difficulteJeu;
    int _volume;

    //--- GIF---//
    QMovie *_film;
};

#endif // APPLICATION_H
