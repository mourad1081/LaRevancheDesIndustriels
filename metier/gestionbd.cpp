#include "gestionbd.h"
#include <iostream>
using namespace std;
GestionBD::GestionBD()
{
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("aaaa");
    db.setDatabaseName("gamedb");
    connexionOk = db.open();
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

QString GestionBD::selectAll(QString table)
{
    QString resultat;
    QString requete="Select * From "+table;
    if(query->exec(requete)){
        while(query->next()){
            for(int i=0;i<query->record().count();++i){
              resultat+=" "+query->value(i).toString();
            }
            resultat+="\n";
        }
    }
    return resultat;
}
