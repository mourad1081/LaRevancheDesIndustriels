#ifndef CHOIXMUSIQUE_H
#define CHOIXMUSIQUE_H

#include <QDialog>
#include <QFile>
#include <QDir>
#include <QScrollBar>
#include <QPushButton>
#include <QIcon>
#include <QVector>

namespace Ui {
class ChoixMusique;
}

class ChoixMusique : public QDialog
{
    Q_OBJECT
    public slots:
        void changerMusique();
    public:
        explicit ChoixMusique(QWidget *parent = 0);
        ~ChoixMusique();
        QString cheminMusique() const;
        void setCheminMusique(const QString &cheminMusique);

private:
        QString _cheminMusique;
        QScrollBar *_barrDeScroll;
        QVector<QPushButton *> _listeMusiques;
        Ui::ChoixMusique *ui;
};

#endif // CHOIXMUSIQUE_H
