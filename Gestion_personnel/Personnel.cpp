#include "Personnel.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>
#include <QSqlRecord>
using namespace std;

Personnel::Personnel()
{
    cin=0;

             nom="";
             prenom="";

}
Personnel::Personnel(int cin, QString nom,  QString prenom)
{
    this->cin=cin;
            this->nom=nom;
            this->prenom=prenom;

}

void Personnel::setcin(int n){
    cin=n;

}
void Personnel::setprenom(QString n){
    prenom=n;
}
    void Personnel::setnom(QString n){
        nom=n;
}

    int Personnel::getcin(){
        return cin;
    }
    QString Personnel::getprenom(){
        return prenom;
    }
    QString Personnel::getnom(){
        return nom;
    }

    bool Personnel::addPersonnel(){
        QSqlQuery query;
        query.prepare("INSERT INTO PERSONNEL (CIN, NOM, PRENOM)"
                      "VALUES(:CIN, :NOM, :PRENOM)");
        query.bindValue(":CIN",cin);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);


        return query.exec();
    }



    bool Personnel::removePersonnel(int cin){
    QSqlQuery query;
    query.prepare("DELETE FROM PERSONNEL WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);
    return    query.exec();
    }

    bool Personnel::modifierPersonnel(QString nom,QString prenom,int cin)
{ QSqlQuery query;
            query.prepare("update PERSONNEL set nom=:nom,prenom=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();

    }

  QSqlQueryModel * Personnel::afficherPersonnel()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select cin, nom, prenom,conge,prime from PERSONNEL");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CONGE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIME"));

            return model;
        }












