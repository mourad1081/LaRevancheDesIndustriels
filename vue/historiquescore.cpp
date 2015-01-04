#include "historiquescore.h"
#include "ui_historiquescore.h"
#include <QMessageBox>
HistoriqueScore::HistoriqueScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoriqueScore)
{
    ui->setupUi(this);
    setWindowTitle("Historique des scores");

    GestionBD bdd;
    QVector<QString> scores = bdd.selectAll("gamedb.score");
    setVisible(true);
    _scoreVue = new ScoreVue(scores, this);
    ui->lay->addWidget(_scoreVue);
}

HistoriqueScore::~HistoriqueScore()
{
    delete ui;
}

void HistoriqueScore::on_fermer_clicked()
{
    this->close();
}

//---------- SOUS-CLASSE-------------//
HistoriqueScore::ScoreVue::ScoreVue(QVector<QString> score, QWidget *parent)
    : QWidget(parent)
{
    QStringList unScore;
    _layoutVertical = new QVBoxLayout(0);
    _scroll = new QScrollArea(0);

    _layoutHorizontaux.append(new QHBoxLayout(0));
    _layoutHorizontaux.last()->addWidget(new QLabel("Tentative N°"));
    _layoutHorizontaux.last()->addWidget(new QLabel("Score"));
    _layoutHorizontaux.last()->addWidget(new QLabel("Date et heure"));
    _layoutVertical->addLayout(_layoutHorizontaux.last());

    for(int i = 0; i < score.size(); i++)
    {
        unScore = score.at(i).split(" ");

        _id.append(new QLabel(unScore.at(2)));
        _id.at(i)->setStyleSheet("color: white; font-size:16pt");
        _scores.append(new QLabel(unScore.at(5)));
        _scores.at(i)->setStyleSheet("color: gold; font-size:18pt");
        _dates.append(new QLabel(unScore.at(7) + " " + unScore.at(8)
                                 + " " + unScore.at(9) + " " + unScore.at(10)
                                 + " " + unScore.at(11) + " " +  unScore.at(12)
                                 + " " +  unScore.at(13)+ " " +  unScore.at(14)));

        _layoutHorizontaux.append(new QHBoxLayout(0));
        _layoutHorizontaux.last()->addWidget(_id.at(i));
        _layoutHorizontaux.last()->addWidget(_scores.at(i));
        _layoutHorizontaux.last()->addWidget(_dates.at(i));

        _layoutVertical->addLayout(_layoutHorizontaux.last());
    }
    setLayout(_layoutVertical);
    _scroll->setWidget(this);
}

HistoriqueScore::ScoreVue::~ScoreVue()
{
    delete _scroll;
    delete [] _scores.data();
    delete [] _dates.data();
    delete [] _id.data();
    delete [] _layoutHorizontaux.data();
}
