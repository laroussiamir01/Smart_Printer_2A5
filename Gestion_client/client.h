#ifndef CLIENT_H
#define CLIENT_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>


class client
{
private:
    QString nom, prenom,reclamation;
    int id,cin,fidele;
public:
    //constructeurs
     client();
    client(int,QString,QString);
    client(int,QString,QString,int,QString,int);
    //destructeur
    ~client(){}

    //getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getCin(){return cin;}
     int get_Fidele();
     QString get_Reclamation();
      int get_Id();

    //setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setCin(int cin){this->cin = cin;}
    void set_Fidele(int fidele){this->fidele = fidele;}
     void set_Reclamation(int reclamation){this->reclamation = reclamation;}



    //fonctionnalittés de base relatives a l'entité client
    bool ajouterClient();
    QSqlQueryModel * afficherClient();
    bool supprimerClient(int);
    bool modifierClient(QString,QString,int);
    bool modifierFidele(int,int);

    QSqlQueryModel *recherche(const QString &);
    bool chercher(int IDD);
    QSqlQueryModel * triParNom();
    QSqlQueryModel * triParQte();

     bool PromotionPrix();





};

#endif // CLIENT_H

