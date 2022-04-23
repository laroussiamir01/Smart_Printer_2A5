#include "achat.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QTableView>
#include <QDate>



using namespace std;

ACHAT::ACHAT(QString nom_materiel,int prix_materiel,int nb_materiel)
{

    this->nom_materiel=nom_materiel;
    this->nb_materiel=nb_materiel;
    this->prix_materiel=prix_materiel;


}


QString ACHAT::getNom(){
  return nom_materiel;

}
QDate ACHAT::getdate(){

  return date_materiel ;
}

int ACHAT::getPrix(){
 return prix_materiel;
}

int ACHAT::getnb(){
   return nb_materiel;
}



void ACHAT:: setNom(QString nom_materiel){
    this->nom_materiel=nom_materiel;
}
void ACHAT::setPrix(int prix_materiel){
 this->prix_materiel=prix_materiel;

}
void ACHAT::setdate(QDate date_materiel){
    this->date_materiel=date_materiel;
}
void ACHAT::setnb(int nb_materiel){
    this->nb_materiel=nb_materiel;
}




bool ACHAT::ajouter(){
  QSqlQuery query;



       query.prepare("INSERT INTO ACHAT (nom_materiel,prix_materiel,,nb_materiel)"
                     "VALUES (:nom_materiel,:prix_materiel,:nb_materiel)");
       query.bindValue(":nom_materiel",nom_materiel);
       query.bindValue(":prix_materiel",prix_materiel);
       query.bindValue(":nb_materiel",nb_materiel);

   return query.exec();

}


QSqlQueryModel * ACHAT::recherchermat(const QString &rech)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from ACHAT where (nom_materiel LIKE '"+rech+"%' OR prix_materiel LIKE '"+rech+"%' OR nb_materiel LIKE '"+rech+"%' OR date_materiel LIKE '"+rech+"%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_materiel "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("categorie_materiel"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_materiel"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("panne_materiel"));

return model;
}


QSqlQueryModel * ACHAT::affichermat()
{
    QSqlQueryModel* model=new QSqlQueryModel();

 model->setQuery("SELECT * FROM ACHAT");
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_materiel"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_materiel"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_materiel"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_materiel"));

return model;
}
