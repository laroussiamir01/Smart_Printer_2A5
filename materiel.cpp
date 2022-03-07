#include "materiel.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QTableView>



MATERIEL::MATERIEL(int id,QString nom,QString categorie,float prix)
{
    this->id=id;
    this->nom=nom;
    this->categorie=categorie;
    this->prix=prix;
}

int MATERIEL::getID(){
   return id;

}
QString MATERIEL::getNom(){
  return nom;

}
QString MATERIEL::getcategorie(){

  return categorie;
}

float MATERIEL::getPrix(){
 return prix;
}

void MATERIEL::setId(int id){
    this->id=id;
}
void MATERIEL:: setNom(QString nom){
    this->nom=nom;
}
void MATERIEL::setPrix(float prix){
 this->prix=prix;

}
void MATERIEL::setCategorie(QString categorie){
    this->categorie=categorie;
}

bool MATERIEL::ajouter()
{
 QSqlQuery query;
query.prepare("INSERT INTO materiel(id,nom,categorie,prix)"
              "VALUES (:id,:nom,:categorie,:prix)");
QString id_string= QString::number(id);
query.bindValue(":id",id_string);
query.bindValue(":nom",nom);
query.bindValue(":categorie",categorie);
QString e = QString::number(prix);
query.bindValue(":prix",e);
return query.exec();
}

bool MATERIEL::supprimer(int id)
{
     QSqlQuery query;
    query.prepare("DELETE FROM MATERIEL where id=:id");

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel * MATERIEL::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

 model->setQuery("SELECT * FROM MATERIEL");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr(" id"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("categorie"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
return model;
}

bool MATERIEL::modifier(int id,QString nom,QString categorie,float prix)
{
    QString prix_string=QString::number(prix);
    QString id_string=QString::number(id);
    QSqlQuery query;
       query.prepare("update MATERIEL set id=:id,nom=:nom,categorie=:categorie where id=:id");
       query.bindValue(":id",id_string);
       query.bindValue(":nom",nom);
       query.bindValue(":categorie",categorie);
       query.bindValue(":prix",prix_string);


return query.exec();
}
