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
   ~Personnel(){}

    Personnel();
public:
    QString  prenom,nom;
    int cin;

};

#endif // PERSONNEL_H
