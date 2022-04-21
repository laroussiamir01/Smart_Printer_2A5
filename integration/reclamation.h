#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
#include "client.h"
class reclamation
{
private:
    QString reclamationn;
    int cin;
public:
      //constructeurs
    reclamation(){}
    reclamation(int,QString);
     //destructeur
    ~reclamation(){}
    //getters
    QString getReclamation(){return reclamationn;}

    //setters
    void setReclamation(QString n){reclamationn=n;}

    //fonctionnalittés de base relatives a l'entité client
       bool ajouterReclamation();
       QSqlQueryModel * afficherReclamation();
       bool supprimerReclamation(int);
       bool modifierReclamation(QString,int);

};

#endif // RECLAMATION_H

