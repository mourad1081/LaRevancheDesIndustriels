#include "historiquescore.h"
#include "ui_historiquescore.h"

HistoriqueScore::HistoriqueScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoriqueScore)
{
    ui->setupUi(this);
    setWindowTitle("Historique des scores");
}

HistoriqueScore::~HistoriqueScore()
{
    delete ui;
}

QListWidget *HistoriqueScore::getListeScore()
{
    return ui->listeScores;
}

void HistoriqueScore::on_fermer_clicked()
{
    this->close();
}
