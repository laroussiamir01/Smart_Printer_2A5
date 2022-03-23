#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"reclamation.h"
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
 //   QRegExp rxnom("\\b[a-zA-Z]{4,10}\\b");
   //         QRegExpValidator *valinom =new QRegExpValidator(rxnom,this);
     //       ui->LineEdit_Nom->setValidator(valinom);
       //     ui->LineEdit_Prenom->setValidator(valinom);
         //   ui->LineEdit_Id->setValidator(new QIntValidator(100,99999999,this));
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

    if( cin >0 && nom!= NULL && prenom != NULL )
    {

    bool test=C.ajouterClient(); //inserer l'objet client instancie dans la table client et recuperer la valeur de retour de query.exec()

    if(test) //si requete excutee -->QMessageBox::infprmation
    {
        //refresh
        ui->tableView->setModel(tmpclient.afficherClient());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else //si requete non execute --> QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);

    }else {

        QMessageBox::critical(nullptr,QObject::tr("ajouter client"),
                            QObject::tr("Controle de saisie:.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);


  }
   }







void MainWindow::on_ajouter_r_clicked()
{
    //recuperation des information saisies dans les 3 champs
    int cin= ui->LineEdit_cin_r->text().toInt();
    QString reclamationn=ui->LineEdit_r->text();
    reclamation R(cin,reclamationn); //instancier un objet de la classe reclamation en utilisant les info saisie

    if( cin >0 && reclamationn!= NULL )
    {
    bool test=R.ajouterReclamation(); //inserer l'objet client instancie dans la table client et recuperer la valeur de retour de query.exec()

    if(test) //si requete excutee -->QMessageBox::infprmation
    {
        //refresh
        ui->tableView_r->setModel(tmpreclamation.afficherReclamation());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
    }
    else //si requete non execute --> QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);

    }else {

    QMessageBox::critical(nullptr,QObject::tr("ajouter reclamation"),
                        QObject::tr("Controle de saisie:.\n"
                                    "Click Cancel to exit."),QMessageBox::Cancel);


}
}

void MainWindow::on_supprimer_clicked()
{
    int cin=ui->comboBox->currentText().toInt();

    if( cin >0 )
    {
         bool test=tmpclient.supprimerClient(cin);
    if(test)
     {
        //refresh
        ui->tableView->setModel(tmpclient.afficherClient());
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    }else {

        QMessageBox::critical(nullptr,QObject::tr("supprimer client"),
                            QObject::tr("Controle de saisie:.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);


          }
}

void MainWindow::on_supprimer_r_clicked()
{
    int cin=ui->lineEdit_cin_s->text().toInt();

    if( cin >0 )
    {
         bool test=tmpreclamation.supprimerReclamation(cin);
    if(test)
     {
        //refresh
        ui->tableView_r->setModel(tmpreclamation.afficherReclamation());
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    }else {

        QMessageBox::critical(nullptr,QObject::tr("supprimer reclamation"),
                            QObject::tr("Controle de saisie:.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);


          }
}

void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpclient.afficherClient());

}

void MainWindow::on_afficher_r_clicked()
{
    ui->tableView_r->setModel(tmpreclamation.afficherReclamation());

}

void MainWindow::on_modifier_clicked()
{
    int cin;
        QString nom,prenom;

        cin=ui->comboBox_1->currentText().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();
        if( cin >0 && nom!= NULL && prenom != NULL )
        {

       bool test=tmpclient.modifierClient(nom,prenom,cin);

       if(test)
       {
           //refresh
           ui->tableView->setModel(tmpclient.afficherClient());
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);



       }else {

            QMessageBox::critical(nullptr,QObject::tr("modifier client"),
                                QObject::tr("Controle de saisie:.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);


              }
}




void MainWindow::on_modifier_r_clicked()
{
    int cin;
        QString reclamationn;

        cin=ui->lineEditCin_r_modif->text().toInt();
        reclamationn=ui->lineEdit_r_modif->text();
        if( cin >0 && reclamationn!= NULL )
        {
             bool test= tmpreclamation.modifierReclamation(reclamationn,cin);
             if(test)
              {
                 //refresh
                 ui->tableView_r->setModel(tmpreclamation.afficherReclamation());
                  QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
              }
             else
                 QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);


          }else {

                 QMessageBox::critical(nullptr,QObject::tr("modifier reclamation"),
                                     QObject::tr("Controle de saisie:.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);


                 }

        }

void MainWindow::on_generer_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QString sql;
        sql="select cin from client";
        QSqlDatabase db = QSqlDatabase::database("QODBC");
            QSqlQuery* query=new QSqlQuery(db);
            query->exec(sql);
            model->setQuery(*query);
            ui->comboBox->setModel(model);

}

void MainWindow::on_generer1_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QString sql;
        sql="select cin from client";
        QSqlDatabase db = QSqlDatabase::database("QODBC");
            QSqlQuery* query=new QSqlQuery(db);
            query->exec(sql);
            model->setQuery(*query);
            ui->comboBox_1->setModel(model);

}
