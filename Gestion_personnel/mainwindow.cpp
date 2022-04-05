#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Personnel.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include "stat_combo.h"
#include <ui_stat_combo.h>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>



using std::uint8_t;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int cin;
        QString nom,prenom;
        cin=ui->lineEditCin->text().toInt();

        nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_pren->text();
        ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

        Personnel P(cin,nom,prenom);


         bool test=P.addPersonnel();
         if(test)
         {
             ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
             QMessageBox::critical(nullptr, QObject::tr("ADD"),
                         QObject::tr(" successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else
             QMessageBox::critical(nullptr, QObject::tr("ADD"),
                         QObject::tr("Remplissez tous les champs.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

void MainWindow::on_supprimer_clicked()
{
    QSqlQuery query2;
    int cin=ui->lineEditCin_supp->text().toInt();



         query2.prepare("select cin from personnel where cin=:cin");
         query2.bindValue(":cin",cin);

         query2.exec();
         query2.next();
         int name=query2.value(0).toInt();


         if(name==cin && cin!=0)
         {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("cin existe\n"
                                 "click cancel to exit."),QMessageBox::Cancel);

         bool test=tmpPersonnel.removePersonnel(cin);

         if(test )
         {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("supprimer effectué\n"
                                 "click cancel to exit."),QMessageBox::Cancel);

         }
         else
             QMessageBox::information(nullptr, QObject::tr("not ok"),
                     QObject::tr("supprimer non effectué\n"
                                 "click cancel to exit."),QMessageBox::Cancel);
     }
         else
             QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("cin n'existe pas\n"
                                 "click cancel to exit."),QMessageBox::Cancel);

     }




void MainWindow::on_modifier_clicked()
{
    QSqlQuery query2;
    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();

       tmpPersonnel.modifierPersonnel(nom,prenom,cin);
       Personnel P(cin,nom,prenom);
       query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
               query2.bindValue(":cin",cin);
               query2.exec();
               query2.next();
               int name=query2.value(0).toInt();

        bool test=tmpPersonnel.modifierPersonnel(nom,prenom,cin);

        if(name==cin && cin!=0)
          {
              QMessageBox::critical(nullptr, QObject::tr("cin existant"),
                                QObject::tr("client existant.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);



          if(test)
          {


          QMessageBox::information(nullptr, QObject::tr("modifier un personnel"),
                            QObject::tr("personnel modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

          }
            else{
                QMessageBox::critical(nullptr, QObject::tr("modifier une personnel"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

          }
          }
          else {
              QMessageBox::critical(nullptr, QObject::tr("cin non exist"),
                          QObject::tr("personnel n'existe pas.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

          }

}
void MainWindow::on_rechercher_clicked()
{
      int  cin=ui->lineEdit_rechercher->text().toInt(); ;
        ui->tableView_rechercher->setModel(tmpPersonnel.rechercher_perso(cin)) ;

}
void MainWindow::on_pushButton_TriASC_clicked()
{
    ui->tableView_tri->setModel(tmpPersonnel.trierAc());
}

void MainWindow::on_pushButton_TriDESC_clicked()
{
    ui->tableView_tri->setModel(tmpPersonnel.trierDec());
}
void MainWindow::on_ajouter_prime_clicked()
{

    QSqlQuery query2;
    int cin,prime;

        cin=ui->lineEdit->text().toInt();
        prime=ui->lineEdit_2->text().toUInt();


       tmpPersonnel.Prime(prime,cin);

       query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
               query2.bindValue(":cin",cin);
               query2.exec();
               query2.next();
}



void MainWindow::on_pushButton_clicked()
{
    stat_combo *s= new stat_combo();

             s->setWindowTitle("statistique ComboBox");
             s->choix_pie();
             s->show();

}


