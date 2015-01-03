#ifndef GESTIONBD_H
#define GESTIONBD_H
#include <QtSql>

class GestionBD
{
private:
QSqlDatabase db;
QSqlQuery *query;
bool connexionOk;
public:
    GestionBD();
    ~GestionBD();
    bool requete(QString requete);
    bool estConnecte() const;
    void closeBD();
    QString selectAll(QString table);
};

#endif // GESTIONBD_H
