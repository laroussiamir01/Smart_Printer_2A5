#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpclient.afficherClient());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    //recuperation des information saisies dans les 3 champs
    int cin= ui->LineEdit_Id->text().toInt();
    QString nom=ui->LineEdit_Nom->text();
    QString prenom=ui->LineEdit_Prenom->text();
    client C(cin,nom,prenom); //instancier un objet de la classe client en utilisant les info saisie

    bool test=C.ajouterClient(); //inserer l'objet client instancie dans la table client et recuperer la valeur de retour de query.exec()

    if(test) //si requete excutee -->QMessageBox::infprmation
    {
        //refresh
        ui->tableView->setModel(tmpclient.afficherClient());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else //si requete non execute --> QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);

    }

void MainWindow::on_supprimer_clicked()
{
    int cin=ui->lineEdit_IDS->text().toInt();
    bool test=tmpclient.supprimerClient(cin);
    if(test)
    {
        //refresh
        ui->tableView->setModel(tmpclient.afficherClient());
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpclient.afficherClient());

}

void MainWindow::on_modifier_clicked()
{
    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();

       tmpclient.modifierClient(nom,prenom,cin);
       ui->tableView->setModel(tmpclient.afficherClient());

}
