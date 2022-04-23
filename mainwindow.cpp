#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"service.h"
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


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpservice.afficherService());
    ui->tableView_affirechercher->setModel(tmpservice.afficherService());
    ui->tableView_tri->setModel(tmpservice.afficherService());
tmpservice.PromotionPrix();
  //  QRegExp rxnom("\\b[a-zA-Z]{4,10}\\b");
       //     QRegExpValidator *valinom =new QRegExpValidator(rxnom,this);
       //     ui->LineEdit_Nom->setValidator(valinom);
            //ui->LineEdit_Prenom->setValidator(valinom);
          //  ui->LineEdit_Id->setValidator(new QIntValidator(100,99999999,this));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_service_clicked()
{

    QString nom=ui->LineEdit_Nom->text();
    int prix =ui->LineEdit_Prix->text().toInt();
    int qte =ui->LineEdit_Qte->text().toInt();

    service S(nom,prix,qte);

  if( prix >0 && qte >0)
  {

    bool test=S.ajouterService();
    if(test)
    {

        ui->tableView->setModel(tmpservice.afficherService());
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

   int id =ui->lineEdit_IDS->text().toInt();
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
    ui->tableView->setModel(tmpservice.afficherService());
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
    ui->tableView->setModel(tmpservice.afficherService());
    ui->tableView_affirechercher->setModel(tmpservice.afficherService());
    ui->tableView_tri->setModel(tmpservice.afficherService());

}



void MainWindow::on_modifier_service_clicked()
{
    QSqlQuery query;
 int id =ui->lineEdit_id_modif->text().toInt();
 int prix =ui->lineEdit_prix_modif->text().toInt();
 int qte =ui->lineEdit_qte_modif->text().toInt();
 QString nom=ui->lineEdit_nom_modif->text();
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

 ui->tableView->setModel(tmpservice.afficherService());



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
    ui->tableView_tri->setModel(tmpservice.triParNom_service());
}


void MainWindow::on_radioButton_TRInProdPrix_service_clicked() //tri prix
{
    ui->tableView_tri->setModel(tmpservice.triParQte_service());

}


void MainWindow::on_rechercher_service_clicked()
{
    qDebug()<< "chercher !!" ;
    QString id=ui->ProduitNom_rechecher->text();

 if(id!="")  { ui->tableView_affirechercher->setModel(tmpservice.recherche_service(id)); }
 else{ QMessageBox::information(this,"Pour chercher dans vehicule  il Faut","tapez le Nom");
     ui->tableView_affirechercher->setModel(tmpservice.afficherService());

 }
}


void MainWindow::on_ProduitNom_rechecher_service_textChanged(const QString &arg1)
{
    if(arg1==""){    ui->tableView_affirechercher->setModel(tmpservice.afficherService());    }

}


void MainWindow::on_tabWidget_service_currentChanged(int index)
{
    ui->tableView->setModel(tmpservice.afficherService());
    ui->tableView_affirechercher->setModel(tmpservice.afficherService());
    ui->tableView_tri->setModel(tmpservice.afficherService());
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

