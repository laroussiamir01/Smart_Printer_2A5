#ifndef ACHAT_H
#define ACHAT_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>




class ACHAT
{
    QString nom_materiel;
    int nb_materiel;
    int prix_materiel;
    QDate date_materiel;
public:
    //constructeurs

    ACHAT(){}
    ~ACHAT(){}

    ACHAT(QString,int,int);

    //getters


    QString getNom();
    int getnb();
    int getPrix();
   QDate getdate();
// setters
    void setNom(QString );
    void setdate(QDate);
    void setnb(int);
    void setPrix(int);

// fonctionnalites de base relatives a lentite achat
    bool ajoutermat();
QSqlQueryModel* affichermat();
QSqlQueryModel * recherchermat(const QString &rech);

};
#endif // ACHAT_H
