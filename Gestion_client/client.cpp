#include "client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;

client::client()
{
    id=0;
    nom="";
    prenom="";
    fidele=-1;
}


client::client(int cin,QString nom,QString prenom)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}

client::client(int id,QString nom,QString prenom,int cin,QString reclamation,int fidele )
{
    this->id=id;
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
      this->fidele=fidele;
     this->reclamation=reclamation;

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

    model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("RECLAMATION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("FIDELE"));

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

QSqlQueryModel * client::recherche(const QString &nom)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client where (nom LIKE '"+nom+"%') ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("OFFRE"));
return model;
}

QSqlQueryModel * client::triParNom()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client order by nom asc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("RECLAMATION"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("FIDELE"));

return model;
}

QSqlQueryModel * client::triParQte()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client order by fidele desc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("RECLAMATION"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("FIDELE"));


return model;
}


bool client::PromotionPrix()
{
    QSqlQuery query;
            query.prepare("update client set classement=1,fidele=fidele+200  where classement=1");
            return    query.exec();

}
