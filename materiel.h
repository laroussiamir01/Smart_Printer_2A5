#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class MATERIEL
{
    QString nom,categorie;
    int id;
    float prix;
public:
    //constructeurs

    MATERIEL(){}
    ~MATERIEL(){}

    MATERIEL(int,QString,QString,float);

    //getters


    QString getNom();
    QString getcategorie();
    int getID();
    float getPrix();

// setters
    void setNom(QString );
    void setCategorie(QString);
    void setId(int);
    void setPrix(float);
// fonctionnalites de base relatives a lentite materiel
    bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int);
bool modifier(int id,QString nom,QString categorie ,float prix);
};

#endif // MATERIEL_H
