#include "service.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;

service::service()
{
    id=0;
    nom="";
    prix=0;
    qte=0;
}

service::service(int id,QString nom,int prix,int qte)
{
this->id=id;
this->nom=nom;
this->prix=prix;
this->qte=qte;
}

service::service(QString nom,int prix,int qte)
{
this->nom=nom;
this->prix=prix;
this->qte=qte;

}

int service:: get_Id(){return id;}
QString service:: get_Nom(){return nom;}
int service::get_Prix(){return prix;}
int service::get_Qte(){return qte;}

bool service::ajouterService()
{
    QSqlQuery query;

    //QString i = QString::number(id);
    QString pr = QString::number(prix);
    QString qt = QString::number(qte);


   query.prepare("INSERT INTO service(nom,prix,qte)"
                 "VALUES(:nom,:prix,:qte)") ;



   // query.bindValue(":id",i);
    query.bindValue(":nom",nom);
    query.bindValue(":prix",pr);
    query.bindValue(":qte",qt);

    return query.exec();

}


QSqlQueryModel * service::afficherService()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select id,nom,prix,qte,offre,classement from SERVICE order by qte desc");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("OFFRE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSEMENT"));

    return model;


}


bool service::supprimerService(int id)
{
    QSqlQuery query;

    QString res =QString::number(id);
    query.prepare("delete from SERVICE where ID=:ID");
    query.bindValue(":ID",res);
    return query.exec();

}




bool service::modifierService(int id, QString nom, int prix , int qte)
{
    QSqlQuery query;
            query.prepare("update service set nom=:nom,prix=:prix,qte=:qte  where id=:id");
            query.bindValue(":id",id);
             query.bindValue(":nom", nom);
              query.bindValue(":prix", prix);
              query.bindValue(":qte", qte);
            return    query.exec();

}

QSqlQueryModel * service::recherche_service(const QString &nom)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prix,qte,offre,classement from service where (nom LIKE '"+nom+"%') ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("OFFRE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSEMENT"));

return model;
}


QSqlQueryModel * service::triParNom_service()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prix,qte,offre,classement from service order by nom asc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("OFFRE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSEMENT"));

return model;
}

QSqlQueryModel * service::triParQte_service()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prix,qte,offre,classement from service order by qte desc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("OFFRE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("CLASSEMENT"));

return model;
}


bool service::PromotionPrix()
{
    QSqlQuery query;
    query.prepare("update service SET classement=1 WHERE qte = (SELECT max(qte) FROM service)");

            return    query.exec();

}
