#include "Personnel.h"
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDebug>
#include <QSqlRecord>
#include"stat_combo.h"
#include"ui_stat_combo.h"
using namespace std;

Personnel::Personnel()
{
             cin=0;
             nom="";
             prenom="";

}
Personnel::Personnel(int cin, QString nom,  QString prenom)
{
            this->cin=cin;
            this->nom=nom;
            this->prenom=prenom;

}

void Personnel::setcin(int n){
       cin=n;

}
void Personnel::setprenom(QString n){
       prenom=n;
}
    void Personnel::setnom(QString n){
        nom=n;
}

    int Personnel::getcin(){
        return cin;
    }
    QString Personnel::getprenom(){
        return prenom;
    }
    QString Personnel::getnom(){
        return nom;
    }

    bool Personnel::addPersonnel(){
        QSqlQuery query;
        QString res =QString::number(cin);
        query.prepare("INSERT INTO PERSONNEL (CIN, NOM, PRENOM)"
                      "VALUES(:CIN, :NOM, :PRENOM)");
        query.bindValue(":CIN",res);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);


        return query.exec();
    }



    bool Personnel::removePersonnel(int cin){
    QSqlQuery query;

    query.prepare("DELETE FROM PERSONNEL WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);

    return    query.exec();
    }

    bool Personnel::modifierPersonnel(QString nom,QString prenom,int cin)
{ QSqlQuery query;
            query.prepare("update PERSONNEL set nom=:nom,prenom=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();

    }

  QSqlQueryModel * Personnel::afficherPersonnel()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PERSONNEL");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin_perso"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_perso"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_perso"));

            return model;
        }

  QSqlQueryModel * Personnel::rechercher_perso(int cin)
   {
      QString res=QString::number(cin);

          QSqlQuery qry;


           qry.prepare("SELECT* FROM PERSONNEL where cin=:cin");
           qry.bindValue(":cin",res);
           qry.exec();
           QSqlQueryModel *model= new QSqlQueryModel;
      model->setQuery(qry);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));



   return model ;
   }
  QSqlQueryModel * Personnel::trierAc()
  {
      QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM PERSONNEL order by cin ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));

               return model;

  }

  QSqlQueryModel * Personnel::trierDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM PERSONNEL order by cin DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin"));

                   return model;
  }

  bool Personnel::Prime(int prime,int cin)
  {
      QSqlQuery query;
            query.prepare("update PERSONNEL set prime=:prime where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":prime", prime);

            return    query.exec();

    }
  stat_combo::stat_combo(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::stat_combo)
  {
      ui->setupUi(this);
  }

  stat_combo::~stat_combo()
  {
      delete ui;
  }


  //bar chart
  void stat_combo::choix_bar()
  {
  QSqlQuery q1,q2,q3;
  qreal tot=0,c1=0,c2=0;

  q1.prepare("SELECT * FROM Personnel");
  q1.exec();

  q2.prepare("SELECT * FROM Personnel where(prime=0)");
  q2.exec();

  q3.prepare("SELECT * FROM Personnel WHERE (prime>0)");
  q3.exec();




  while (q1.next()){tot++;}
  while (q2.next()){c1++;}
  while (q3.next()){c2++;}


  c1=c1/tot;
  c2=c2/tot;


  // Assign names to the set of bars used
          QBarSet *set0 = new QBarSet("prime=0");
          QBarSet *set1 = new QBarSet("prime>0");

          // Assign values for each bar
          *set0 << c1;
          *set1 << c2;


          // Add all sets of data to the chart as a whole
          // 1. Bar Chart
          QBarSeries *series = new QBarSeries();

          // 2. Stacked bar chart
          series->append(set0);
          series->append(set1);


          // Used to define the bar chart to display, title
          // legend,
          QChart *chart = new QChart();

          // Add the chart
          chart->addSeries(series);


          // Adds categories to the axes
         // QBarCategoryAxis *axis = new QBarCategoryAxis();



          // 1. Bar chart
         // chart->setAxisX(axis, series);

          // Used to change the palette
          QPalette pal = qApp->palette();

          // Change the color around the chart widget and text
          pal.setColor(QPalette::Window, QRgb(0xffffff));
          pal.setColor(QPalette::WindowText, QRgb(0x404044));

          // Apply palette changes to the application
          qApp->setPalette(pal);


  // Used to display the chart

  chartView = new QChartView(chart,ui->label_stat);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setMinimumSize(400,400);

  chartView->show();
  }

  //pie chart
      void stat_combo::choix_pie()
      {
      QSqlQuery q1,q2,q3;
      qreal tot=0,c1=0,c2=0;

      q1.prepare("SELECT * FROM Personnel");
      q1.exec();

      q2.prepare("SELECT * FROM Personnel WHERE (prime=0 )");
      q2.exec();

      q3.prepare("SELECT * FROM Personnel where(prime>0 )");
      q3.exec();


      while (q1.next()){tot++;}
      while (q2.next()){c1++;}
      while (q3.next()){c2++;}

      c1=c1/tot;
      c2=c2/tot;

      // Define slices and percentage of whole they take up
      QPieSeries *series = new QPieSeries();
      series->append("prime=0",c1);
      series->append("prime=1",c2);





      // Create the chart widget
      QChart *chart = new QChart();

      // Add data to chart with title and show legend
      chart->addSeries(series);
      chart->legend()->show();


      // Used to display the chart
      chartView = new QChartView(chart,ui->label_stat);
      chartView->setRenderHint(QPainter::Antialiasing);
      chartView->setMinimumSize(400,400);

      chartView->show();
      }

      bool Personnel::congee(int cin,int conge)
  {

      }





