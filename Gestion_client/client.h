#ifndef CLIENT_H
#define CLIENT_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>


class client
{
private:
    QString nom, prenom;
    int id,cin;
public:
    //constructeurs
    client(){}
    client(int,QString,QString);
    //destructeur
    ~client(){}

    //getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getCin(){return cin;}

    //setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setCin(int cin){this->cin = cin;}

    //fonctionnalittés de base relatives a l'entité client
    bool ajouterClient();
    QSqlQueryModel * afficherClient();
    bool supprimerClient(int);
    bool modifierClient(QString,QString,int);





};

#endif // CLIENT_H

