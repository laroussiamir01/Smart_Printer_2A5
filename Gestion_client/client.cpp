#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;



client::client(int cin,QString nom,QString prenom)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}


bool client::ajouterClient()
{
    QSqlQuery query;
    QString res = QString::number(cin);
    //prepare() prend la requete en parametre pour la preparer a l'exécution.
    query.prepare("insert into client (cin, nom, prenom)" "values (:cin, :nom, :prenom)");
    //creation des variable liées
    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    return query.exec(); //evoie la reqete pour l'execution

}

QSqlQueryModel * client::afficherClient()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));

      return model;

}

bool client::supprimerClient(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("Delete from client where cin= :cin");
    query.bindValue(":cin",res);
    return query.exec();
}

bool client::modifierClient(QString nom, QString prenom , int cin)
{
    QSqlQuery query;
            query.prepare("update client set nom=:nom,prenom=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();
}




