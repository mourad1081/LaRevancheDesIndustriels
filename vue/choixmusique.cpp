#include "choixmusique.h"
#include "ui_choixmusique.h"


ChoixMusique::ChoixMusique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixMusique)
{
    ui->setupUi(this);
    QDir dossierDeMusique("son");
    dossierDeMusique.setFilter(QDir::NoDotAndDotDot
                               | QDir::Files
                               | QDir::Readable);
    QFileInfoList musiques = dossierDeMusique.entryInfoList();
    for(int i = 0; i < musiques.size(); i++)
    {
        _listeMusiques.append(new QPushButton(QIcon("://img/music.png"),
                                              musiques.at(i).baseName()));
        ui->listMusiques->addWidget(_listeMusiques.last());
        connect(_listeMusiques.last(), SIGNAL(clicked()),
                this, SLOT(changerMusique()));
    }
}

ChoixMusique::~ChoixMusique()
{
    delete ui;
}
QString ChoixMusique::cheminMusique() const
{
    return _cheminMusique;
}

void ChoixMusique::setCheminMusique(const QString &cheminMusique)
{
    _cheminMusique = cheminMusique;
}



void ChoixMusique::changerMusique()
{
    _cheminMusique = "son/" + ((QPushButton *)sender())->text() + ".mp3";
    ui->musiqueChoisie->setText("Sélectionné : "
                                + ((QPushButton *)sender())->text());
}
