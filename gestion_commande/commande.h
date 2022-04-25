#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Commande
{       QString nom,prenom,adresse,mail;
        int quantite;
            float prix_tot;
public:
            //constructeurs
        Commande(){};
        Commande(QString,QString,QString,QString,int,float);
            //getters
            QString getNom(){return nom;}
            QString getPrennom(){return prenom;}
            QString getadresse(){return adresse;}
            QString getMail(){return mail;}
            int getQantite(){return quantite;}
                float getprix_tot(){return prix_tot;}
             //setters
                void SetNom(QString n){nom=n;}
                void SetPreom(QString p){prenom=p;}
                void SetAdresse(QString a){adresse=a;}
                void SetMail(QString m){mail=m;}
                void SetQuantite(int q){quantite=q;}
                    void Setprix_tot(float pt){prix_tot=pt;}
             // fonctionalité

             bool ajouter_com();
             QSqlQueryModel * afficher_com();
             bool supprimer_com(int id);
             bool modifier_com(int id);


};

#endif // COMMANDE_H



