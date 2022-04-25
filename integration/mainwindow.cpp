#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QTextStream>
#include "stat_combo_com.h"
#include <ui_stat_combo_com.h>
#include "arduino.h"
#include"client.h"
#include"reclamation.h"
#include "personnel.h"
#include "service.h"
#include "materiel.h"
#include"achat.h"
#include "commande.h"
#include<QObject>
#include <qstring.h>
#include<QTableView>
#include<QSqlQueryModel>
#include<QIntValidator>
#include <QApplication>   // Manages the applications main settings like                         // widget initialization
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>
#include "stat_combo_mat.h"
#include "ui_stat_combo_mat.h"
#include <QDate>
#include <QSqlRecord>
#include <iostream>

// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>
// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


#include <QSerialPort>
#include <QSerialPortInfo>




using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





 //   QSqlQueryModel* model=new QSqlQueryModel();
 //   model->setQuery("select NOM from PRODUIT");
 //   ui->comboBox_com->setModel(model);
 //   ui->comboBox_2_com->setModel(model);

 //   QSqlQueryModel* model2=new QSqlQueryModel();
 //   model2->setQuery("select ID_COMMAND from COMMANDE");
 //   ui->comboBox_id_com->setModel(model2);
  //  ui->comboBox_id2_com->setModel(model2);
  //  ui->comboBox_id3_com->setModel(model2);
  //  ui->comboBox_id4_com->setModel(model2);

    //----------------client--------------------------------------------------------
    ui->tableView_client->setModel(tmpclient.afficherClient());
      ui->tableViewperso->setModel(tmpPersonnel.afficherPersonnel());
      ui->tableView_ser->setModel(tmpservice.afficherService());
      ui->tableView_affirechercher_ser->setModel(tmpservice.afficherService());
      ui->tableView_tri_ser->setModel(tmpservice.afficherService());
  tmpservice.PromotionPrix();

  ui->tablemateriel->setModel(M.afficher());
  ui->tabachat->setModel(a.affichermat());



 // ui->le_id_supp->setValidator(new QIntValidator (0,9999,this));
//  ui->le_id->setValidator(new QIntValidator (0,9999,this));
//  ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
//  ui->le_cat->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
//  ui->le_prix->setValidator(new QIntValidator (0,999999999,this));

//  ui->le_etat->setValidator(new QIntValidator (0,9,this));


  ui->le_id_3->setValidator(new QIntValidator (0,9999,this));
  ui->le_nom_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
  ui->le_cat_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
  ui->le_prix_3->setValidator(new QIntValidator (0,999999999,this));




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
              //   A.read_from_arduino();
              /*   QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();   */
 // QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(readSerial()));
//---------------------------------------------------------------------------------------------
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------menu---------------------------------------------
void MainWindow::on_pushButton_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_personel_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_service_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_materiel_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_commande_clicked()
{
      ui->stackedWidget->setCurrentIndex(5);
}



//-----------------------------------------------------------------------

//---------------------------------client------------------------------------------
void MainWindow::on_ajouter_client_clicked()
{

  //    A.getserial()->waitForBytesWritten(5000);

   //   A.getserial()->waitForReadyRead(1000);
    data = A.read_from_arduino();
   cout<<data.toStdString()<< "aaaa "<<endl;
  //  qDebug() data.toStdString() ;
    qDebug() << "clavier :" <<data;



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
 else{ QMessageBox::information(this,"Pour chercher dans client  il Faut","tapez le Nom");
     ui->tableView_affirechercher_client->setModel(tmpclient.afficherClient());
   //  data = A.read_from_arduino();

   //  qDebug() data.toStdString() ;
     QByteArray s = A.getserial()->readAll();
            A.getserial()->waitForReadyRead(1000);
              cout<<data.toStdString()<< "aaaa "<<endl;





     client d ;

         int cin;
           A.getserial()->waitForReadyRead(1000);
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
    qDebug() << "clavier : " << data <<endl;
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
  //  int a= 0;

 data=A.read_from_arduino();

       ui->LineEdit_Id_client->setText(data);



/*
   if(data=="1")
        ui->LineEdit_Id_client->setText("1"); //si les donnes recue de arduino via la liaison series sont egual a 1
    else if (data=="0")
        ui->LineEdit_Id_client->setText("0");
    else if (data=="2")
        ui->LineEdit_Id_client->setText("2");
    else if (data=="3")
        ui->label_arduino->setText("3");
    else if (data=="4")
        ui->label_arduino->setText("4");
    else if (data=="5")
        ui->label_arduino->setText("5");
    else if (data=="6")
        ui->label_arduino->setText("6");
    else if (data=="7")
        ui->label_arduino->setText("7");
    else if (data=="8")
        ui->label_arduino->setText("8");
    else if (data=="9")
        ui->label_arduino->setText("9");
    else if (data=="A")
        ui->label_arduino->setText("A");
    else if (data=="B")
        ui->label_arduino->setText("B");
    else if (data=="C")
        ui->label_arduino->setText("C");
    else if (data=="D")
        ui->label_arduino->setText("D");
    else if (data=="*")
        ui->label_arduino->setText("*");
    else if (data=="#")
        ui->label_arduino->setText("#");
*/
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

//---------------------service-----------------------------------------------------
void MainWindow::on_ajouter_service_clicked()
{

    QString nom=ui->LineEdit_Nom_ser->text();
    int prix =ui->LineEdit_Prix_ser->text().toInt();
    int qte =ui->LineEdit_Qte_ser->text().toInt();

    service S(nom,prix,qte);

  if( prix >0 && qte >0)
  {

    bool test=S.ajouterService();
    if(test)
    {

        ui->tableView_ser->setModel(tmpservice.afficherService());
        qDebug() <<"service ajoutée";
        QMessageBox::information(nullptr,QObject::tr("ajouter service "),
                                QObject::tr("service ajouté.\n"
                                   "click cancel to exit"),QMessageBox::Cancel);

    }
    else{
        qDebug() <<"Erreur d'ajout un service";
        QMessageBox::critical(nullptr,QObject::tr("ajouter service"),
                            QObject::tr("Erreur 2:.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);

    }

}else {

      QMessageBox::critical(nullptr,QObject::tr("ajouter service"),
                          QObject::tr("Controle de saisie:.\n"
                                      "Click Cancel to exit."),QMessageBox::Cancel);


}
}




void MainWindow::on_supprimer_service_clicked()
{
     QSqlQuery query;

   int id =ui->lineEdit_IDS_ser->text().toInt();
    query.prepare("select id from service where id=:id");
   query.bindValue(":id",id);
   query.exec();
   query.next();
   int id1=query.value(0).toInt();

   if(id1==id && id!=NULL){
       QMessageBox::information(nullptr,QObject::tr("modifier un service "),
       QObject::tr("Id existe \n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   bool test = tmpservice.supprimerService(id);



if(test)
{
    ui->tableView_ser->setModel(tmpservice.afficherService());
    QMessageBox::information(nullptr,QObject::tr("ok"),
    QObject::tr("suppression effectuée \n"
                "Click Cancel to exit."), QMessageBox::Cancel);


}
else {
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                          QObject::tr("suppression non effectuée.\n"
                                      "Click Cancel to exit."),QMessageBox::Cancel);

}

} else {

       QMessageBox::critical(nullptr,QObject::tr("suppression service"),
                           QObject::tr("Id n'existe pas:.\n"
                                       "Click Cancel to exit."),QMessageBox::Cancel);


}

}



void MainWindow::on_afficher_service_clicked()
{
    ui->tableView_ser->setModel(tmpservice.afficherService());
    ui->tableView_affirechercher_ser->setModel(tmpservice.afficherService());
    ui->tableView_tri_ser->setModel(tmpservice.afficherService());

}



void MainWindow::on_modifier_service_clicked()
{
    QSqlQuery query;
 int id =ui->lineEdit_id_modif_ser->text().toInt();
 int prix =ui->lineEdit_prix_modif_ser->text().toInt();
 int qte =ui->lineEdit_qte_modif_ser->text().toInt();
 QString nom=ui->lineEdit_nom_modif_ser->text();
 query.prepare("select id from service where id=:id");
 query.bindValue(":id",id);
 query.exec();
 query.next();
 int id1=query.value(0).toInt();


if(id1==id && qte !=NULL && prix!=NULL && id!=NULL)
{
    QMessageBox::information(nullptr,QObject::tr("modifier un service "),
    QObject::tr("Id existe \n"
                "Click Cancel to exit."), QMessageBox::Cancel);



if( prix >0 && qte>0 )
{
    QMessageBox::information(nullptr,QObject::tr("modifier un service "),
    QObject::tr("Controle de saisie \n"
                "Click Cancel to exit."), QMessageBox::Cancel);


bool test = tmpservice.modifierService(id,nom,prix,qte);
if(test){

 ui->tableView_ser->setModel(tmpservice.afficherService());



 QMessageBox::information(nullptr,QObject::tr("modifier un service "),
 QObject::tr("modification effectuée \n"
             "Click Cancel to exit."), QMessageBox::Cancel);


}
else {
 QMessageBox::critical(nullptr,QObject::tr("modifier un service"),
                       QObject::tr("modification non effectuée.\n"
                                   "Click Cancel to exit."),QMessageBox::Cancel);

}


}
}else {

    QMessageBox::critical(nullptr,QObject::tr("modification service"),
                        QObject::tr("Id n'existe pas :.\n"
                                    "Click Cancel to exit."),QMessageBox::Cancel);
}
}

void MainWindow::on_radioButton_TRInProd_service_clicked() //tri nom
{
    ui->tableView_tri_ser->setModel(tmpservice.triParNom_service());
}


void MainWindow::on_radioButton_TRInProdPrix_service_clicked() //tri prix
{
    ui->tableView_tri_ser->setModel(tmpservice.triParQte_service());

}


void MainWindow::on_rechercher_service_clicked()
{
    qDebug()<< "chercher !!" ;
    QString id=ui->ProduitNom_rechecher_ser->text();

 if(id!="")  { ui->tableView_affirechercher_ser->setModel(tmpservice.recherche_service(id)); }
 else{ QMessageBox::information(this,"Pour chercher dans vehicule  il Faut","tapez le Nom");
     ui->tableView_affirechercher_ser->setModel(tmpservice.afficherService());

 }
}


void MainWindow::on_ProduitNom_rechecher_ser_textChanged(const QString &arg1)
{
    if(arg1==""){    ui->tableView_affirechercher_ser->setModel(tmpservice.afficherService());    }

}


void MainWindow::on_tabWidget_service_currentChanged(int index)
{
    ui->tableView_ser->setModel(tmpservice.afficherService());
    ui->tableView_affirechercher_ser->setModel(tmpservice.afficherService());
    ui->tableView_tri_ser->setModel(tmpservice.afficherService());
    tmpservice.PromotionPrix();

qDebug()<<index;
if(index==3)
{
    tmpservice.PromotionPrix();

}
            QPieSeries *series = new QPieSeries();
            series->setHoleSize(0.35);

                QSqlQuery q;
                q.prepare("select PRIX,QTE  from SERVICE  order by prix  DESC");
                if(q.exec())
              { //  int c=0;
                 //  qDebug()<<"azazazazazaz";
                  while (q.next())
                  {
                      //qDebug()<<"azazazazazaz";
                  QString a=q.value(0).toString() ;
                  float b= q.value(1).toFloat()  ;
                 // if(c==0)
                 // {
                     // QPieSlice *slice =  series->append(a, b );
                     // slice->setExploded();
                     // slice->setLabelVisible();
                  //}
                 // else
                 // {
                      series->append(a+" DT", b );
                  //}
              }}

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setTitle("donut chart repartition des service par prix :");
            chart->setTheme(QChart::ChartThemeLight );
            QChartView *chartview = new QChartView(chart);
            chartview->setRenderHint(QPainter::Antialiasing);
            chart->legend()->setAlignment(Qt::AlignRight);
            chartview->setParent(ui->aaaaa);


}



//---------------------------------------------------------------------------------
//---------------------materiel-----------------------------------------------------
void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->le_id_supp->text().toInt();
    QString idtest= ui->le_id_supp->text();
    if(idtest.isEmpty())
        {
            QMessageBox::critical(0,qApp->tr("erreur"),
                                  qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
        }
    else
    {
        QMessageBox::critical(0,qApp->tr("attention"),
                              qApp->tr("voulez vous supprimer cette depense?"),QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes)
        {
            bool test= M.supprimer(id);
            if (test)
            {
                ui->tablemateriel->setModel(M.afficher());
                ui->tablemateriel->setModel(M.rechercher(""));
                ui->tablemateriel->clearSelection();
            }
        }

    }




}

void MainWindow::on_pb_ajout_clicked()
{
    int id=ui->le_id->text().toInt();
    int panne=ui->le_etat->text().toInt();
    QString nom=ui->le_nom->text();
    QString categorie=ui->le_cat->text();
    qreal prix=ui->le_prix->text().toInt();
    QString idtest=ui->le_id->text();
    QString prixtest=ui->le_prix->text();
            MATERIEL M(id,nom,categorie,prix,panne);
            if(idtest.isEmpty())
                {
                    QMessageBox::critical(0,qApp->tr("erreur"),
                                          qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
                }
            else
            {
                QMessageBox::critical(0,qApp->tr("attention"),
                                      qApp->tr("voulez vous ajouter cette depense?"),QMessageBox::Yes,QMessageBox::No);
                if(QMessageBox::Yes)
                {
                    bool test= M.ajouter();
                    if (test)
                    {
                        ui->tablemateriel->setModel(M.afficher());
                        ui->tablemateriel->setModel(M.rechercher(""));
                        ui->tablemateriel->clearSelection();
                    }
                }

            }


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



void MainWindow::on_pb_trier_clicked()
{

   ui->tabletri->setModel(M.tri_id());
}


void MainWindow::on_pb_tri_nom_clicked()
{
    ui->tabletri->setModel(M.tri_nom());

}

void MainWindow::on_pb_tri_cat_clicked()
{
    ui->tabletri->setModel(M.tri_cat());

}

void MainWindow::on_pb_tri_prix_clicked()
{
    ui->tabletri->setModel(M.tri_prix());

}

void MainWindow::on_pb_tri_prix_desc_clicked()
{
    ui->tabletri->setModel(M.trierdesc());

}

void MainWindow::on_pb_recherche_clicked()
{
    QString rech=ui->id_rech->text();
 if(rech!="" )
 { ui->tablerech->setModel(M.rechercher(rech));
 }
 else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
 ui->tablerech->setModel(M.afficher());
 }
}

void MainWindow::on_pb_recherche_2_clicked()
{
    QString rech=ui->nom_rech->text();
 if(rech!="" )
 { ui->tablerech->setModel(M.rechercher(rech));
 }
 else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
 ui->tablerech->setModel(M.afficher());
 }
}



void MainWindow::on_pb_stat_clicked()
{

    stat_combo_mat *s= new stat_combo_mat();

             s->setWindowTitle("statistique ComboBox");
             s->choix_pie_mat();
             s->show();
}


void MainWindow::on_pb_panne_clicked()
{
     ui->tabmain->setModel(M.etatenpanne());
}

void MainWindow::on_pb_traitement_clicked()
{
    ui->tabmain->setModel(M.etatdetraitement());

}

void MainWindow::on_pb_regler_clicked()
{
    ui->tabmain->setModel(M.etatregler());

}

void MainWindow::on_pb_achat_clicked()
{
    int nb_materiel,prix_materiel;
    QString nom_materiel;

     nb_materiel=ui->nb_achat->text().toInt();
     nom_materiel=ui->nom_achat->text();
  prix_materiel=ui->prix_achat->text().toInt();

            ACHAT a(nom_materiel,prix_materiel,nb_materiel);
            if(nom_materiel.isEmpty())
                {
                    QMessageBox::critical(0,qApp->tr("erreur"),
                                          qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
                }
            else
            {
                QMessageBox::critical(0,qApp->tr("attention"),
                                      qApp->tr("voulez vous ajouter cette depense?"),QMessageBox::Yes,QMessageBox::No);
                if(QMessageBox::Yes)
                {
                    bool test= a.ajoutermat();
                    if (test)
                    {
                        ui->tabachat->setModel(a.affichermat());
                        ui->tabachat->setModel(a.recherchermat(""));
                        ui->tabachat->clearSelection();
                    }
                }

            }

}



//----------------------------------------------------------------------------------
//-----------------------------commande-----------------------------------------------
void MainWindow::on_pushButton_clicked()
{
    QString prod= ui->comboBox_com->currentText();
     QSqlQuery query,query2,query3,query4;
     query.prepare("select PRIX from SRVICE where NOM= :nom");
    query.bindValue(":nom",prod);
    query.exec();
    query.next();
    float prix=query.value(0).toFloat();


    int res=ui->lineEdit_quantite_com->text().toInt();
    QString nom=ui->lineEdit_nom_com->text();
    QString prenom=ui->lineEdit_prenom_com->text();
    QString adresse=ui->lineEdit_adresse_com->text();
    QString mail=ui->lineEdit_mail_com->text();
    query2.prepare("select nom from COMMANDE where NOM=:nom");
    query2.bindValue(":nom",nom);

    query2.exec();
    query2.next();
    QString name=query2.value(0).toString();

    if(name==nom)
    {


        query3.prepare("select PRIX_TOT from COMMANDE where NOM= :nom");
       query3.bindValue(":nom",nom);
       query3.exec();
       query3.next();
       float prix_tot=query.value(0).toFloat();






        float somme=prix_tot+prix*res;
        cout<<somme;
        QString res2 = QString::number(somme);



        query4.prepare("update COMMANDE set prix_tot=:prix where NOM=:nom");

        query4.bindValue(":prix",res2);

        query4.bindValue(":nom",nom);

        query4.exec();


    }
    else
    {
    Commande C(nom,prenom,adresse,mail,res,prix*res);
    bool test=C.ajouter_com();
    if(test )
    {
        ui->table_commande->setModel(cm.afficher_com());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajouter effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("ajouter non effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query2;
    int id= ui->comboBox_id3_com->currentText().toInt();

    query2.prepare("select id_command from COMMANDE where id_command=:id");
    query2.bindValue(":id",id);

    query2.exec();
    query2.next();
    int name=query2.value(0).toInt();
    cout<<name;


    if(name==id)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("id existe\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    bool test=cm.supprimer_com(id);







    if(test )
    {ui->table_commande->setModel(cm.afficher_com());
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
                QObject::tr("id n'existe pas\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{QString prod= ui->comboBox_2_com->currentText();

     QSqlQuery query,query2;
     query.prepare("select PRIX from SERVICE where NOM= :nom");
    query.bindValue(":nom",prod);
    query.exec();
    query.next();
    float prix=query.value(0).toFloat();




    int id= ui->comboBox_id4_com->currentText().toInt();
    int res=ui->lineEdit_55_com->text().toInt();
    QString nom=ui->lineEdit_1_com->text();
    QString prenom=ui->lineEdit_2_com->text();
    QString adresse=ui->lineEdit_3_com->text();
    QString mail=ui->lineEdit_4_com->text();
    int etat=ui->lineEdit_5_com->text().toInt();
    Commande C(nom,prenom,adresse,mail,res,prix*res);
    if(etat==0||etat==1)
{


    bool test=C.modifier_com(id);
    if(test )
    {query.prepare("update COMMANDE set etat=:etat where ID_COMMAND=:id");
        query.bindValue(":etat",etat);
        query.bindValue(":id",id);

        query.exec();
        ui->table_commande->setModel(cm.afficher_com());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("modifier effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("modifier non effectué\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("not ok"),
                QObject::tr("etat non valid\n"
                            "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    QString nom=ui->recherche_com->text();

    query.prepare("select* from COMMANDE where NOM= :nom");
    query.bindValue(":nom",nom);
    query.exec();

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));


     ui->tableView_recherche_com->setModel(model);


}

void MainWindow::on_tri_clicked()
{


    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from COMMANDE  order by PRIX_TOT desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));

     ui->table_view_tri_com->setModel(model);


}

void MainWindow::on_tri_2_clicked()
{

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from COMMANDE order by PRIX_TOT ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMAND"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix_totale"));


     ui->table_view_tri_2_com->setModel(model);

}



void MainWindow::on_pushButton_6_clicked()
{
   stat_combo_com *s= new stat_combo_com();

         s->setWindowTitle("statistique ComboBox");
         s->choix_pie_com();
         s->show();
}

void MainWindow::on_pushButton_7_clicked()
{

     int id= ui->comboBox_id_com->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT etat FROM Commande where ID_COMMAND=:id ");
    query.bindValue(":id",id);
    query.exec();
    query.next();
    int etat=query.value(0).toInt();
    if(etat==1)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("commande deja annuler\n"
                                           "click cancel to exit."),QMessageBox::Cancel);


    }
    else if(etat==2)
    {   QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("commande deja payee\n"
                                             "click cancel to exit."),QMessageBox::Cancel);}
    else
    {
        query.prepare("update COMMANDE set etat= 2 where ID_COMMAND=:id");
        query.bindValue(":id",id);

         query.exec();
ui->table_commande->setModel(cm.afficher_com());
    QSqlDatabase db;
                        QTableView table_commande;
                        QSqlQueryModel * Modal=new  QSqlQueryModel();

                        QSqlQuery qry;
                         qry.prepare("SELECT * FROM Commande where ID_COMMAND=:id ");
                         qry.bindValue(":id",id);
                         qry.exec();
                         Modal->setQuery(qry);
                         table_commande.setModel(Modal);



                         db.close();


                         QString strStream;
                         QTextStream out(&strStream);


                         const int rowCount = table_commande.model()->rowCount();
                         const int columnCount =  table_commande.model()->columnCount();


                         const QString strTitle ="Document";


                         out <<  "<html>\n"
                                 "<img src='C:/Users/Akram/Pictures/R.png' height='120' width='120'/>"
                             "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 "<img src='C:/Users/Akram/Pictures/R.png.png'>"
                             <<  QString("<title>%1</title>\n").arg(strTitle)
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                            << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #b80b32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("COMMANDE")
                            <<"<br>"

                            <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                         out << "<thead><tr bgcolor=#f0f0f0>";
                         for (int column = 0; column < columnCount; column++)
                             if (!table_commande.isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!table_commande.isColumnHidden(column)) {
                                     QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                                 "<br><br>"
                                 <<"<br>"
                                 <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                             out << "<thead><tr bgcolor=#f0f0f0>";

                                 out <<  "</table>\n"

                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;
                         QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                         if (dialog->exec() == QDialog::Accepted) {

                             QLabel lab;
                              QPixmap pixmap("C:/Users/Akram/Pictures/R.png");
                             lab.setPixmap(pixmap);
                             QPainter painter(&lab);
                             //QPrinter printer(QPrinter::PrinterResolution);

                             //pixmap.load("aze.png");
                            // painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                            // painter.drawPixmap(10,10,50,50, pixmap);

                             document->print(&printer);
                         }


                         printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                         printer.setOutputFileName("Document.pdf");
                         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                         delete document;
    }
}





//-----------------------------------------------------------------------------------



void MainWindow::on_pushButton_5_clicked()
{
      ui->table_commande->setModel(cm.afficher_com());
}

void MainWindow::on_generer2_clicked()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select NOM from SERVICE");
    ui->comboBox_com->setModel(model);
}

void MainWindow::on_generer3_clicked()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select NOM from SERVICE");
     ui->comboBox_2_com->setModel(model);
}

void MainWindow::on_generer4_clicked()
{
    QSqlQueryModel* model2=new QSqlQueryModel();
    model2->setQuery("select ID_COMMAND from COMMANDE");
    ui->comboBox_id3_com->setModel(model2);
}

void MainWindow::on_generer5_clicked()
{
    QSqlQueryModel* model2=new QSqlQueryModel();
    model2->setQuery("select ID_COMMAND from COMMANDE");
    ui->comboBox_id_com->setModel(model2);
}

void MainWindow::on_quitter_ajouter_perso_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_quitter_ajouter_client_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_quitter_ajouter_ser_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_quitter_ajouter_mat_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_quitter_ajouter_com_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_quitter_menu_clicked()
{
    exit(0);
}
