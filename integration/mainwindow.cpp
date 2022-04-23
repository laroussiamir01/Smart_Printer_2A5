#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"reclamation.h"
#include"stat_combo.h"
#include"ui_stat_combo.h"
#include"stat_combo_perso.h"
#include"ui_stat_combo_perso.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QPainter>
#include <QtCharts>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include "arduino.h"

#include "personnel.h"
#include <QSqlRecord>
#include <iostream>




using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //----------------client--------------------------------------------------------
    ui->tableView_client->setModel(tmpclient.afficherClient());
      ui->tableViewperso->setModel(tmpPersonnel.afficherPersonnel());


        int ret=A.connect_arduino(); // lancer la connexion à arduino
                switch(ret){
                case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();

//---------------------------------------------------------------------------------------------
}

MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------client------------------------------------------
void MainWindow::on_ajouter_client_clicked()
{
    //recuperation des information saisies dans les 3 champs
    int cin= ui->LineEdit_Id_client->text().toInt();
    QString nom=ui->LineEdit_Nom_client->text();
    QString prenom=ui->LineEdit_Prenom_client->text();
    client C(cin,nom,prenom); //instancier un objet de la classe client en utilisant les info saisie

    QSqlQuery query2;

    query2.prepare("select cin from client where cin=:cin");
            query2.bindValue(":cin",cin);
    query2.exec();
    query2.next();
    int cin1=query2.value(0).toInt();


    if(cin1==cin && cin !=0 )
    {
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Cin existe\n" "Click cancel to exit."),QMessageBox::Cancel);
     A.write_to_arduino("0");
}
    else if( cin >0 && nom!= NULL && prenom != NULL )
    {

    bool test=C.ajouterClient(); //inserer l'objet client instancie dans la table client et recuperer la valeur de retour de query.exec()


            if(test)
            {


            QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                              QObject::tr("client ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
A.write_to_arduino("1");


            }
              else{
                  QMessageBox::critical(nullptr, QObject::tr("ajouter un client"),
                              QObject::tr("Erreur ! ID existant\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


            }
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

void MainWindow::on_supprimer_client_clicked()
{
    QSqlQuery query2;
    int cin=ui->comboBox_supp_client->currentText().toInt();
    query2.prepare("select cin from client where cin=:cin");
            query2.bindValue(":cin",cin);
    query2.exec();
    query2.next();
    int cin1=query2.value(0).toInt();


    if(cin1==cin && cin !=0 )
    {
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Cin existe\n" "Click cancel to exit."),QMessageBox::Cancel);
         bool test=tmpclient.supprimerClient(cin);
    if(test)
     {
        //refresh
        ui->tableView_client->setModel(tmpclient.afficherClient());
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {

        QMessageBox::critical(nullptr,QObject::tr("supprimer client"),
                            QObject::tr("id n'existe pas:.\n"
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

void MainWindow::on_afficher_client_clicked()
{
    ui->tableView_client->setModel(tmpclient.afficherClient());
    ui->tableView_affirechercher_client->setModel(tmpclient.afficherClient());
    ui->tableView_tri_client->setModel(tmpclient.afficherClient());

}

void MainWindow::on_afficher_r_clicked()
{
    ui->tableView_r->setModel(tmpreclamation.afficherReclamation());

}

void MainWindow::on_modifier_client_clicked()
{
    int cin;
        QString nom,prenom;

        cin=ui->comboBox_modif_client->currentText().toInt();
        nom=ui->lineEdit_nom_modif_client->text();
        prenom=ui->lineEdit_pren_modif_client->text();
        if( cin >0 && nom!= NULL && prenom != NULL )
        {

       bool test=tmpclient.modifierClient(nom,prenom,cin);

       if(test)
       {
           //refresh
           ui->tableView_client->setModel(tmpclient.afficherClient());
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
            ui->comboBox_modif_client->setModel(model);

}

void MainWindow::on_generer_1_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QString sql;
        sql="select cin from client";
        QSqlDatabase db = QSqlDatabase::database("QODBC");
            QSqlQuery* query=new QSqlQuery(db);
            query->exec(sql);
            model->setQuery(*query);
            ui->comboBox_supp_client->setModel(model);

}


void MainWindow::on_radioButton_TRInProd_client_clicked() //tri nom
{
    ui->tableView_tri_client->setModel(tmpclient.triParNom());
}


void MainWindow::on_radioButton_TRInProdPrix_client_clicked() //tri fidele
{
    ui->tableView_tri_client->setModel(tmpclient.triParQte());

}


void MainWindow::on_rechercher_client_clicked()
{
    qDebug()<< "chercher !!" ;
    QString id=ui->ProduitNom_rechecher_client->text();

 if(id!="")  { ui->tableView_affirechercher_client->setModel(tmpclient.recherche(id)); }
 else{ QMessageBox::information(this,"Pour chercher dans vehicule  il Faut","tapez le Nom");
     ui->tableView_affirechercher_client->setModel(tmpclient.afficherClient());


     client d ;

         int cin;
         data=A.read_from_arduino();


         cin=data.toInt();

                     bool test=d.chercher(cin);

                     if(test)
                     {
                         QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                                 QObject::tr("client existe\n"
                                                             "Cliquez sur cancel Pour Quitter."), QMessageBox::Cancel);
                     ui->statusbar->showMessage("recherche terminée");
                    }
                     else
                     {  QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                             QObject::tr("Echec.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);}

 }
}


void MainWindow::on_ProduitNom_rechecher_client_textChanged(const QString &arg1)
{
    if(arg1==""){    ui->tableView_affirechercher_client->setModel(tmpclient.afficherClient());    }

}



void MainWindow::on_enregister_fidele_clicked()
{
     QSqlQuery query2,query1;
    int fidele=ui->comboBox_fidele->currentText().toInt();
    qDebug() << fidele;
    int cin= ui->cin_fidele->text().toInt();
    query1.prepare("select cin from client where cin=:cin");
          query1.bindValue(":cin",cin);
     query1.exec();
     query1.next();
     int cin1=query1.value(0).toInt();
     if(cin1==cin && cin !=0)
     {
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Cin existe\n" "Click cancel to exit."),QMessageBox::Cancel);
        int fidelee;
        query2.prepare("select fidele from client where cin=:cin");
              query2.bindValue(":cin",cin);
         query2.exec();

         if (query2.next()){
          fidelee=query2.value(0).toInt();
         }


        fidelee += fidele;
        qDebug()<< fidelee ;
         // fidele << fidelee ;


        bool test=tmpclient.modifierFidele(cin,fidelee);

        if(test)
        {
            //refresh
            ui->tableView_client->setModel(tmpclient.afficherClient());
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectué\n" "Click cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

        QMessageBox::critical(nullptr,QObject::tr("supprimer client"),
                            QObject::tr("id n'existe pas:.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);



     }




void MainWindow::on_pushButton_stat_client_clicked()
{
    stat_combo *s= new stat_combo();

             s->setWindowTitle("statistique ComboBox");
             s->choix_pie();
             s->show();


}

void MainWindow::on_pushButton_arduino_on_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 a arduino
}

void MainWindow::on_pushButton_arduino_off_clicked()
{
    A.write_to_arduino("0"); //envoyer 0 a arduino
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
        ui->label_arduino->setText("Nombre Attein"); //si les donnes recue de arduino via la liaison series sont egual a 1
    else if (data=="0")
        ui->label_arduino->setText("NOMBRE non Attein");

}

//-----------------------------------------------------------------------------

//------------------------personnel---------------------------------------------
void MainWindow::on_ajouterperso_clicked()
{
    int cin;
        QString nom,prenom;
        cin=ui->lineEditCinperso->text().toInt();

        nom=ui->lineEdit_nomperso->text();
        prenom=ui->lineEdit_prenperso->text();
        ui->tableViewperso->setModel(tmpPersonnel.afficherPersonnel());

        Personnel P(cin,nom,prenom);


         bool test=P.addPersonnel();
         if(test)
         {
             ui->tableViewperso->setModel(tmpPersonnel.afficherPersonnel());
             QMessageBox::critical(nullptr, QObject::tr("ADD"),
                         QObject::tr(" successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else
             QMessageBox::critical(nullptr, QObject::tr("ADD"),
                         QObject::tr("Remplissez tous les champs.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_afficherperso_clicked()
{
    ui->tableViewperso->setModel(tmpPersonnel.afficherPersonnel());

}

void MainWindow::on_supprimerperso_clicked()
{
    QSqlQuery query2;
    int cin=ui->lineEditCin_suppperso->text().toInt();



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




void MainWindow::on_modifierperso_clicked()
{
    QSqlQuery query2;
    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modifperso->text().toInt();
        nom=ui->lineEdit_nom_modifperso->text();
        prenom=ui->lineEdit_pren_modifperso->text();

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
void MainWindow::on_rechercherperso_clicked()
{
      int  cin=ui->lineEdit_rechercherperso->text().toInt(); ;
        ui->tableView_rechercherperso->setModel(tmpPersonnel.rechercher_perso(cin)) ;

}
void MainWindow::on_pushButton_TriASCperso_clicked()
{
    ui->tableView_triperso->setModel(tmpPersonnel.trierAc());
}

void MainWindow::on_pushButton_TriDESCperso_clicked()
{
    ui->tableView_triperso->setModel(tmpPersonnel.trierDec());
}
void MainWindow::on_ajouter_primeperso_clicked()
{

    QSqlQuery query2;
    int cin,prime;

        cin=ui->lineEditperso->text().toInt();
        prime=ui->lineEdit_2perso->text().toUInt();


       tmpPersonnel.Prime(prime,cin);

       query2.prepare("SELECT CIN FROM personnel WHERE cin = :cin");
               query2.bindValue(":cin",cin);
               query2.exec();
               query2.next();
}



void MainWindow::on_pushButtonperso_clicked()
{
    stat_combo_perso *s= new stat_combo_perso();

             s->setWindowTitle("statistique ComboBox");
             s->choix_pie_perso();
             s->show();

}



void MainWindow::on_pushButton_2perso_clicked()
{

    int conge= ui->comboBoxperso->currentText().toInt();
    int cin=ui->lineEdit_3perso->text().toInt();

        QSqlQuery query;



        query.prepare("update personnel set conge=:conge  where cin=:cin");
        query.bindValue(":cin",cin);
        query.bindValue(":conge",conge);

         query.exec();

         if(conge==1)
         QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("encour de traitement\n"
                                            "click cancel to exit."),QMessageBox::Cancel);
         else if(conge==2)
             QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("conge a ete accepter avec succe\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
         else
             QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("demande a ete refuser\n"
                                                "click cancel to exit."),QMessageBox::Cancel);



}

//--------------------------------------------------------------------------------


void MainWindow::on_pushButton_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_personel_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}






