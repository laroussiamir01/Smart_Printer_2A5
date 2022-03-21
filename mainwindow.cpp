#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiel.h"
#include "connexion.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <qstring.h>
#include<QMessageBox>
#include<QTableView>
#include<QSqlQueryModel>
#include<QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablemateriel->setModel(M.afficher());

    ui->le_id_supp->setValidator(new QIntValidator (0,9999,this));
    ui->le_id_3->setValidator(new QIntValidator (0,9999,this));

    ui->le_id->setValidator(new QIntValidator (0,9999,this));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_supprimer_clicked()
{

    MATERIEL M ; M.setId(ui->le_id_supp->text().toInt());
        bool test=M.supprimer(M.getID());
        QMessageBox msgBox;
        if (test)
            msgBox.setText("suppression avec succés");
            else
         msgBox.setText("echec d'ajout");
         msgBox.exec();

}

void MainWindow::on_pb_ajout_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString categorie=ui->le_cat->text();
    qreal prix=ui->le_prix->text().toInt();
    QString idtest=ui->le_id->text();
    QString prixtest=ui->le_prix->text();
            MATERIEL M(id,nom,categorie,prix);

if(idtest.isEmpty()||nom.isEmpty()||categorie.isEmpty()||prixtest.isEmpty())
{
    QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("il ya un champ vide"),QMessageBox::Cancel);

}


bool test=M.ajouter();
 QMessageBox msgBox;
if (test) {
    ui->tablemateriel->setModel(M.afficher());
    msgBox.setText("ajout avec succes");
}
else
    msgBox.setText("echec ");
msgBox.exec();
ui->tablemateriel->setModel(M.afficher());

}


void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id_3->text().toInt();
    float prix=ui->le_prix_3->text().toInt();
    QString nom=ui->le_nom_3->text();
    QString categorie=ui->le_cat_3->text();

    MATERIEL M;
           bool test;
           test=M.modifier(id,nom,categorie,prix);
           if(test)
           {
              ui->tablemateriel->setModel(M.afficher());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr(" modifier avec succes") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}
