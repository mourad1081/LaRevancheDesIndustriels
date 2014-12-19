#ifndef NIVEAUX_H
#define NIVEAUX_H
#include <QVector>
#include <QString>

class Niveaux
{
private:
    QVector<QString> _cheminNiveaux;
public:
    Niveaux();
    Niveaux(QVector<QString> listeNiveaux);
    QVector<QString> cheminNiveaux() const;
    void setCheminNiveaux(const QVector<QString> &cheminNiveaux);

    const static int NB_NIVEAUX = 5;
};

#endif // NIVEAUX_H
