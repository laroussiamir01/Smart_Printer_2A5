#include "reclamation.h"
#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
using namespace std;
reclamation::reclamation(int cin,QString reclamationn)
{
    this->cin=cin;
    this->reclamationn=reclamationn;
}

bool reclamation::ajouterReclamation()
{
    QSqlQuery query;
    //prepare() prend la requete en parametre pour la preparer a l'exécution.
    query.prepare("update client set reclamationn=:reclamationn where cin=:cin" );
    //creation des variable liées
    query.bindValue(":cin",cin);
     query.bindValue(":reclamationn", reclamationn);

    return query.exec(); //evoie la reqete pour l'execution

}

QSqlQueryModel * reclamation::afficherReclamation()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select cin,nom,prenom,reclamationn from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("RECLAMATION"));

      return model;

}

bool reclamation::supprimerReclamation(int cin)
{
    QSqlQuery query;
    reclamationn="";
    query.prepare("update client set reclamationn=:reclamationn where cin=:cin");
    query.bindValue(":cin",cin);
    return query.exec();
}

bool reclamation::modifierReclamation(QString reclamationn, int cin)
{
    QSqlQuery query;
            query.prepare("update client set reclamationn=:reclamationn where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":reclamationn", reclamationn);
            return    query.exec();
}


