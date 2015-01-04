#ifndef HISTORIQUESCORE_H
#define HISTORIQUESCORE_H

#include <QDialog>
#include <QListWidget>
#include "metier/gestionbd.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class HistoriqueScore;
}

/**
 * @brief Petite interface affichant l'historique des scores stockés dans une
 * base dee donnée mysql
 */
class HistoriqueScore : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Constructeur de l'interface affichant l'historique des scores
     * @param parent Parent de l'interface
     */
    explicit HistoriqueScore(QWidget *parent = 0);

    /**
     * @brief Destructeur de l'interface graphique
     */
    ~HistoriqueScore();

    class ScoreVue : public QWidget
    {
    public:
        explicit ScoreVue(QVector<QString> score, QWidget * parent = 0);
        ~ScoreVue();
    private:
        QScrollArea *_scroll;
        QVBoxLayout *_layoutVertical;
        QVector<QHBoxLayout *>_layoutHorizontaux;
        QVector<QLabel *> _scores;
        QVector<QLabel *> _dates;
        QVector<QLabel *> _id;
    };
private slots:

    /**
     * @brief Ferme la fenêtre
     */
    void on_fermer_clicked();

private:
    ScoreVue *_scoreVue;
    Ui::HistoriqueScore *ui;
};

#endif // HISTORIQUESCORE_H
