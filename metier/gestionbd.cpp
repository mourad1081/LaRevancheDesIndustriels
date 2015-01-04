#include "gestionbd.h"
#include <iostream>
#include <QMessageBox>
using namespace std;
GestionBD::GestionBD()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("aaaa"); // Indiquez mdp que vous avez mis sur
    connexionOk = db.open();
    db.setDatabaseName("GAMEDB"); //le nom de la db mdr
    query = new QSqlQuery(db);
}

GestionBD::~GestionBD()
{
    closeBD();
    delete query;
}

bool GestionBD::requete(QString requete)
{

    return (query->exec(requete));
}

bool GestionBD::estConnecte() const
{
    return connexionOk;
}

void GestionBD::closeBD()
{
    if(!connexionOk)
        db.close();
}

QVector<QString> GestionBD::selectAll(QString table)
{
    QString s;
    QVector<QString> resultat;
    QString requete="Select * From "+table+" where 1 order by score.valscore desc";
    if(query->exec(requete))
        while(query->next())
        {
            s = "";
            for(int i = 0; i < query->record().count(); ++i)
            {
                s += query->record().fieldName(i)
                         + "  " + query->value(i).toString() + " ";
            }
            resultat.append(s);
        }


    return resultat;
}
