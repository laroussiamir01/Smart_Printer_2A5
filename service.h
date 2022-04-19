#ifndef SERVICE_H
#define SERVICE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>


class service
{
private:
    QString nom;
    int id,prix,qte;
public:
    //constructeurs
     service();
    service (QString,int,int);
    service(int,QString,int,int);

    //destructeur
    ~service(){}

    //getters
 //   QString getNom(){return nom;}
 //   int getPrix(){return prix;}
   // int getId(){return id;}
   //  int getQte(){return qte;}
    int get_Id();
    QString get_Nom();
    int get_Prix();
    int get_Qte();



    //setters
    void setNom(QString n){nom=n;}
    void setPrix(int p){prix=p;}
    void setId(int id){this->id = id;}
     void setQte(int qte){this->qte = qte;}


    //fonctionnalittés de base relatives a l'entité client
    bool ajouterService();
    QSqlQueryModel * afficherService();
    bool supprimerService(int);
    bool modifierService(int,QString,int,int);



//
    QSqlQueryModel *recherche(const QString &);
    QSqlQueryModel * triParNom();
    QSqlQueryModel * triParQte();
    bool PromotionPrix();


};

#endif // SERVICE_H

