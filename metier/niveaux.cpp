#include "niveaux.h"

Niveaux::Niveaux()
{
    for(int i = 0; i < NB_NIVEAUX; i++)
        _cheminNiveaux.append(QString() + "lvls/lvl_" + QString::number(i) + ".txt");
}

Niveaux::Niveaux(QVector<QString> listeNiveaux)
{
    cheminNiveaux() = listeNiveaux;
}

QVector<QString> Niveaux::cheminNiveaux() const
{
    return _cheminNiveaux;
}

void Niveaux::setCheminNiveaux(const QVector<QString> &cheminNiveaux)
{
    _cheminNiveaux = cheminNiveaux;
}
