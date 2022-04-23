#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class Personnel
{
public:
    Personnel(int,QString,QString);
    void setcin(int n);
    void setprenom(QString n);
    void setnom(QString n);
    int getcin();
    QString getprenom();
    QString getnom();
    bool addPersonnel();
    QSqlQueryModel * afficherPersonnel();
    bool removePersonnel(int);
   bool modifierPersonnel(QString,QString,int);
   QSqlQueryModel * rechercher_perso(int cin);
   QSqlQueryModel *trierAc();
   QSqlQueryModel * trierDec();
   bool Prime(int,int);
 bool congee(int,int);
 ~Personnel(){}

    Personnel();
private:
    QString  prenom,nom;
    int cin,conge;
    int prime;

};
#endif // PERSONNEL_H
