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
        ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
        nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_pren->text();
        Personnel c(cin,nom,prenom);
        c.addPersonnel();
        /*if(test) //si requete excutee -->QMessageBox::infprmation
            {
                //refresh
                //ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
                QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
            }
            else //si requete non execute --> QMessageBox::critical
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);
        */ Personnel();

}

void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

void MainWindow::on_supprimer_clicked()
{
    int cin=ui->lineEditCin_supp->text().toInt();
        tmpPersonnel.removePersonnel(cin);
        ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

void MainWindow::on_modifier_clicked()
{
    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();

       tmpPersonnel.modifierPersonnel(nom,prenom,cin);
       ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}


