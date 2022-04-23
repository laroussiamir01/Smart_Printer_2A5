#ifndef MATERIEL_H
#define MATERIEL_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class MATERIEL
{
    QString nom,categorie;
    int id,panne;
    float prix;
public:
    //constructeurs

    MATERIEL(){}
    ~MATERIEL(){}

    MATERIEL(int,QString,QString,float,int);

    //getters


    QString getNom();
    QString getcategorie();
    int getID();
    int getpanne();

    float getPrix();

// setters
    void setNom(QString );
    void setCategorie(QString);
    void setId(int);
    void setpanne(int);
    void setPrix(float);

// fonctionnalites de base relatives a lentite materiel
    bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
bool modifier(int id,QString nom,QString categorie ,float prixq);
QSqlQueryModel * tri_id() ;
QSqlQueryModel * tri_nom() ;
QSqlQueryModel * tri_cat() ;
QSqlQueryModel * tri_prix() ;
QSqlQueryModel * trierdesc() ;
QSqlQueryModel * rechercher(const QString &rech);
QSqlQueryModel *  stats();
QSqlQueryModel * etatenpanne();
QSqlQueryModel * etatdetraitement();
QSqlQueryModel * etatregler();
int calculer(QString );
};
#endif // MATERIEL_H
