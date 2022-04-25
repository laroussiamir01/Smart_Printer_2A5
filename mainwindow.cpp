#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiel.h"
#include "connexion.h"
#include"achat.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <qstring.h>
#include<QMessageBox>
#include<QTableView>
#include<QSqlQueryModel>
#include<QIntValidator>
#include <QApplication>
#include <QSqlTableModel>
#include <QString>
#include <QDebug>
#include <QSqlRecord>
#include "stat_combo.h"
#include <ui_stat_combo.h>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include <QDate>
#include <QTextToSpeech>



// Manages the applications main settings like
// widget initialization
#include <QApplication>

// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->tablemateriel->setModel(M.afficher());
    ui->tabachat->setModel(A.affichermat());

    ui->le_id_supp->setValidator(new QIntValidator (0,9999,this));
    ui->le_id->setValidator(new QIntValidator (0,9999,this));
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
    ui->le_cat->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
    ui->le_prix->setValidator(new QIntValidator (0,999999999,this));

    ui->le_etat->setValidator(new QIntValidator (0,9,this));


    ui->le_id_3->setValidator(new QIntValidator (0,9999,this));
    ui->le_nom_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
    ui->le_cat_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z_]{0,20}"),this));
    ui->le_prix_3->setValidator(new QIntValidator (0,999999999,this));
  int ret=a.connect_arduino(); // lancer la connexion à arduino
           switch(ret){
           case(0):qDebug()<< "arduino is available and connected to : "<< a.getarduino_port_name();
               break;
           case(1):qDebug() << "arduino is available but not connected to :" <<a.getarduino_port_name();
              break;
           case(-1):qDebug() << "arduino is not available";
           }
            QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(notif()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::notif(){
    data=a.read_from_arduino();
       qDebug() << "data :"<<data;
       if (data=="1")
       {

           QMessageBox msgBox;
           QTextToSpeech * m_speech =new QTextToSpeech();
           m_speech->say("very high temperature");
           msgBox.setText("very high temperature");
           msgBox.setStandardButtons(QMessageBox::Ok);
           msgBox.exec();

       }

}

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

    stat_combo *s= new stat_combo();

             s->setWindowTitle("statistique ComboBox");
             s->choix_pie();
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

            ACHAT A(nom_materiel,prix_materiel,nb_materiel);
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
                    bool test= A.ajouter();
                    if (test)
                    {
                        ui->tabachat->setModel(A.affichermat());
                        ui->tabachat->setModel(A.recherchermat(""));
                        ui->tabachat->clearSelection();
                    }
                }

            }

}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db;
                    QTableView tablemateriel;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM MATERIEL ");
                     qry.exec();
                     Modal->setQuery(qry);
                     tablemateriel.setModel(Modal);


                     db.close();

                     QString strStream;
                     QTextStream out(&strStream);


                     const int rowCount = tablemateriel.model()->rowCount();
                     const int columnCount =  tablemateriel.model()->columnCount();

                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                             "<img src='C:/Users/LENOVO/Documents/login/images/bg.png' height='120' width='120'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des materiels")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!tablemateriel.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(tablemateriel.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!tablemateriel.isColumnHidden(column)) {
                                 QString data = tablemateriel.model()->data(tablemateriel.model()->index(row, column)).toString().simplified();
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

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/produit.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                     delete document;

    }
