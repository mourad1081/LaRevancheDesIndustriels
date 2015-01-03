#include "gestionbd.h"
#include <iostream>
using namespace std;
GestionBD::GestionBD()
{
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("aaaa"); // Indiquez mdp que vous avez mis sur
    db.setDatabaseName("gamedb"); //le nom de la db mdr
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
    if(query->exec(requete)){
        return true;
    }else {
        cout<<endl<<query->lastError().text().toStdString()<<endl;
    }
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
