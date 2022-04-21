#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"reclamation.h"
#include"stat_combo.h"
#include"ui_stat_combo.h"
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


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpclient.afficherClient());


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

void MainWindow::on_supprimer_clicked()
{
    QSqlQuery query2;
    int cin=ui->comboBox->currentText().toInt();
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
        ui->tableView->setModel(tmpclient.afficherClient());
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

void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpclient.afficherClient());
    ui->tableView_affirechercher->setModel(tmpclient.afficherClient());
    ui->tableView_tri->setModel(tmpclient.afficherClient());

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


void MainWindow::on_radioButton_TRInProd_clicked() //tri nom
{
    ui->tableView_tri->setModel(tmpclient.triParNom());
}


void MainWindow::on_radioButton_TRInProdPrix_clicked() //tri fidele
{
    ui->tableView_tri->setModel(tmpclient.triParQte());

}


void MainWindow::on_rechercher_clicked()
{
    qDebug()<< "chercher !!" ;
    QString id=ui->ProduitNom_rechecher->text();

 if(id!="")  { ui->tableView_affirechercher->setModel(tmpclient.recherche(id)); }
 else{ QMessageBox::information(this,"Pour chercher dans vehicule  il Faut","tapez le Nom");
     ui->tableView_affirechercher->setModel(tmpclient.afficherClient());


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


void MainWindow::on_ProduitNom_rechecher_textChanged(const QString &arg1)
{
    if(arg1==""){    ui->tableView_affirechercher->setModel(tmpclient.afficherClient());    }

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
            ui->tableView->setModel(tmpclient.afficherClient());
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




void MainWindow::on_pushButton_3_clicked()
{
    stat_combo *s= new stat_combo();

             s->setWindowTitle("statistique ComboBox");
             s->choix_pie();
             s->show();


}

void MainWindow::on_pushButton_4_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 a arduino
}

void MainWindow::on_pushButton_5_clicked()
{
    A.write_to_arduino("0"); //envoyer 0 a arduino
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
        ui->label->setText("Nombre Attein"); //si les donnes recue de arduino via la liaison series sont egual a 1
    else if (data=="0")
        ui->label->setText("NOMBRE non Attein");

}
