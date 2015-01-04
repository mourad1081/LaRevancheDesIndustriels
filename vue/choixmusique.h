#ifndef CHOIXMUSIQUE_H
#define CHOIXMUSIQUE_H

#include <QDialog>
#include <QFile>
#include <QDir>
#include <QPushButton>
#include <QIcon>
#include <QVector>
namespace Ui {
class ChoixMusique;
}

/**
 * @brief Interface graphique permettant de choisir la musique qui sera jouée
 * pendant la partie
 */
class ChoixMusique : public QDialog
{
    Q_OBJECT

    public slots:
        /**
         * @brief Permet de changer de musique. La nouvelle musique sera celle
         * qui a été sélectionnée en dernier.
         */
        void changerMusique();

    public:
        /**
         * @brief Constructeur de l'interface permettant de choisir un thème
         * @param parent Parent de l'interface
         */
        explicit ChoixMusique(QWidget *parent = 0);

        /**
         * @brief Destructeur de l'interface permettant de choisir un thème
         */
        ~ChoixMusique();

        /**
         * @brief Permet de recevoir le chemin relatif vers
         * la musique sélectionnée
         * @return Le chemin relatif vers la musique sélectionnée
         */
        QString cheminMusique() const;

        /**
         * @brief Permet de définir le chemin vers la musique sélectionnée
         * @param cheminMusique Le nouveau chemin
         */
        void setCheminMusique(const QString &cheminMusique);

    private:
        QString _cheminMusique; /** Chemin vers la musique */
        QVector<QPushButton *> _listeMusiques; /*! Liste de musiques dispo */
        Ui::ChoixMusique *ui;
};

#endif // CHOIXMUSIQUE_H
