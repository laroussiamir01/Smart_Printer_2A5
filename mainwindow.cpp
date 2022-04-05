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



}

MainWindow::~MainWindow()
{
    delete ui;
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
