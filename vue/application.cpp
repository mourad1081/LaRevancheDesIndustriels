#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    _musique.demarrerMusique();
    _volume = 1;
    _clicQuit = false;
    _sonActif = true;
    _nbVies = 3;
    _difficulteJeu = NORMAL;
    _jouerAMusiqueALinfini = true;

    _film = new QMovie("://img/YAY.gif");
    ui->gif->setMovie (_film);
    _film->start ();
}

Application::~Application()
{
    delete ui;
}

void Application::on_btnQuitter_clicked()
{
    this->_clicQuit = true;
    QApplication::quit();
}
bool Application::getClicQuit() const
{
    return _clicQuit;
}

void Application::setClicQuit(bool value)
{
    _clicQuit = value;
}


void Application::on_btnNouvellePartie_clicked()
{
    close();
}

void Application::on_btnHackNASA_clicked()
{
    QMessageBox::information(this,
                             "Voilà c'est fait !",
                             "Félicitations, vous avez hacké la NASA !",
                             "Ouahhh j'suis trop D4RK",
                             "SISI");
}

void Application::on_btnOptions_clicked()
{
    ParametresSon *param = new ParametresSon(0);
    if (param->exec() == QDialog::Accepted)
    {
        if( (_sonActif = param->isSonActif()) )
        {
            _musique.reprendre();
            _jouerAMusiqueALinfini = param->isMusiqueInfinie();
        } else
            _musique.pause();

        _difficulteJeu = param->getDifficulte();
        _nbVies = param->getNbVies();
        _volume = param->getVolume();
        _musique.volume(param->getVolume());

    }
}

void Application::on_btnMusique_clicked()
{
    ChoixMusique *param = new ChoixMusique(0);
    if (param->exec() == QDialog::Accepted)
    {
        _musique.stop();
        _musique.changerMusique(param->cheminMusique().toStdString());
    }
}
