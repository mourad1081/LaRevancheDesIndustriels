#ifndef GESTIONBD_H
#define GESTIONBD_H
#include <QtSql>

/**
 * @brief The GestionBD classe permettant de gérer une base de donnée.
 */
class GestionBD
{
private:
QSqlDatabase db;
QSqlQuery *query;
bool connexionOk;
public:
/**
     * @brief GestionBD Démarre une connexion avec la base de donnée GameBD.
     */
    GestionBD();
    /**
      * @brief Destructeur de la classe GestionBD
      * Déconnecte également de la base de donnée.
      */
    ~GestionBD();
    /**
     * @brief requete Permet d'envoyer une requête à la base de donnée.
     * @param requete La requête SQL.
     * @return true si la requête est correcte, false sinon.
     */
    bool requete(QString requete);
    /**
     * @brief estConnecte Indique si la connexion a bien eu lieu.
     * @return true si la connexion s'est fait, false sinon.
     */
    bool estConnecte() const;
    /**
     * @brief closeBD Permet de se déconnecter de la base de donnée.
     */
    void closeBD();
    /**
     * @brief selectAll Envoie une requête qui permet de voir tout le contenu d'une table.
     * @param table la table dont on veut le contenu.
     * @return le contenu de la table.
     */
    QVector<QString> selectAll(QString table);
};

#endif // GESTIONBD_H
