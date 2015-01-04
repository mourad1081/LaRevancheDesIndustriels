#ifndef HISTORIQUESCORE_H
#define HISTORIQUESCORE_H

#include <QDialog>
#include <QListWidget>
namespace Ui {
class HistoriqueScore;
}

class HistoriqueScore : public QDialog
{
    Q_OBJECT

public:
    explicit HistoriqueScore(QWidget *parent = 0);
    ~HistoriqueScore();

    QListWidget *getListeScore();
private slots:
    void on_fermer_clicked();

private:
    Ui::HistoriqueScore *ui;
};

#endif // HISTORIQUESCORE_H
