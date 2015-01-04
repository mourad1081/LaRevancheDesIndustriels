#include "application.h"
#include "ui_application.h"
#include <QMediaPlaylist>

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    _clicQuit = false;

    _chetiflorQuiDance = new QMovie("://img/YAY.gif");
    ui->gif->setMovie (_chetiflorQuiDance);
    _chetiflorQuiDance->start ();

    _theme = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist(this);
    _playlist->addMedia(QUrl::fromLocalFile("son\\Phoenix Wright.mp3"));
    _playlist->setPlaybackMode(QMediaPlaylist::Loop);
    _playlist->setCurrentIndex(0);
    _theme->setPlaylist(_playlist);
    _theme->setVolume(100);
    _theme->play();
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
        if(param->isSonActif())
        {
            _theme->play();
        } else
            _theme->pause();

        _theme->setVolume(param->getVolume());
    }
}

void Application::on_btnMusique_clicked()
{
    ChoixMusique *param = new ChoixMusique(0);
    if (param->exec() == QDialog::Accepted)
    {
        _playlist = new QMediaPlaylist(this);
        _playlist->addMedia(QUrl::fromLocalFile(param->cheminMusique()));
        _playlist->setPlaybackMode(QMediaPlaylist::Loop);
        _playlist->setCurrentIndex(0);
        _theme->setPlaylist(_playlist);
        _theme->setVolume(100);
        _theme->play();
    }
}

void Application::on_historiqueScores_clicked()
{
    (new HistoriqueScore())->exec();
}
