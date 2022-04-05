#include "materiel.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QTableView>
#include "stat_combo.h"
#include "ui_stat_combo.h"
using namespace std;

MATERIEL::MATERIEL(int id,QString nom,QString categorie,float prix,int panne)
{
    this->id=id;
    this->nom=nom;
    this->categorie=categorie;
    this->prix=prix;
    this->panne=panne;

}

int MATERIEL::getID(){
   return id;

}



QString MATERIEL::getNom(){
  return nom;

}
QString MATERIEL::getcategorie(){

  return categorie;
}

float MATERIEL::getPrix(){
 return prix;
}
int MATERIEL::getpanne(){
   return panne;
}
void MATERIEL::setId(int id){
    this->id=id;
}

void MATERIEL:: setNom(QString nom){
    this->nom=nom;
}
void MATERIEL::setPrix(float prix){
 this->prix=prix;

}
void MATERIEL::setCategorie(QString categorie){
    this->categorie=categorie;
}
void MATERIEL::setpanne(int panne){
    this->panne=panne;
}
bool MATERIEL::ajouter()
{
 QSqlQuery query;
 QString res5=QString::number(prix);

 QString prix_string=res5;




query.prepare("INSERT INTO materiel(id,nom,categorie,prix,panne)"
              "VALUES (:id,:nom,:categorie,:prix,:panne)");
QString id_string= QString::number(id);
query.bindValue(":id",id_string);
query.bindValue(":nom",nom);
query.bindValue(":categorie",categorie);
QString e = QString::number(prix);
query.bindValue(":prix",e);
QString panne_string= QString::number(panne);
query.bindValue(":panne",panne_string);
return query.exec();
}

bool MATERIEL::supprimer(int id)
{
     QSqlQuery query;
    query.prepare("DELETE FROM MATERIEL where id=:id");

    query.bindValue(":id",id);

    return query.exec();
}

QSqlQueryModel * MATERIEL::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

 model->setQuery("SELECT * FROM MATERIEL");
  model->setHeaderData (0,Qt::Horizontal,QObject::tr(" id"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("categorie"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("panne"));

return model;
}

bool MATERIEL::modifier(int id,QString nom,QString categorie,float prix)
{
    QString prix_string=QString::number(prix);
    QString id_string=QString::number(id);
    QSqlQuery query;
       query.prepare("update MATERIEL set id=:id,nom=:nom,categorie=:categorie where id=:id");
       query.bindValue(":id",id_string);
       query.bindValue(":nom",nom);
       query.bindValue(":categorie",categorie);
       query.bindValue(":prix",prix_string);
return query.exec();

}
QSqlQueryModel *MATERIEL::tri_id()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  MATERIEL ORDER BY id ");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("panne"));

return model;
}

QSqlQueryModel *MATERIEL::tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  MATERIEL ORDER BY nom ");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("panne"));

return model;
}
QSqlQueryModel *MATERIEL::tri_cat()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  MATERIEL ORDER BY categorie ");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("panne"));


return model;
}
QSqlQueryModel *MATERIEL::tri_prix()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  MATERIEL ORDER BY prix ");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("panne"));

return model;
}

QSqlQueryModel *MATERIEL::trierdesc(){
    QSqlQuery * M = new QSqlQuery();
    QSqlQueryModel * model = new QSqlQueryModel();
    M->prepare("SELECT * FROM MATERIEL order by prix DESC");
    M->exec();
    model->setQuery(*M);
    return model;
}

QSqlQueryModel * MATERIEL::rechercher(const QString &rech)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from MATERIEL where (id LIKE '"+rech+"%' OR nom LIKE '"+rech+"%' OR categorie LIKE '"+rech+"%' OR prix LIKE '"+rech+"%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("panne"));

return model;
}









QSqlQueryModel * MATERIEL::etatenpanne()
{
    QSqlQueryModel * model= new QSqlQueryModel();
 //cout <<"le produit est en panne"<<endl;
    model->setQuery("SELECT * FROM MATERIEL where (panne=0)" );

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));


    return model ;

    }
QSqlQueryModel * MATERIEL::etatdetraitement()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    //std::cout << "le produit est en cours de traitement" << std::endl;
    model->setQuery("SELECT * FROM MATERIEL where (panne=1)" );

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));




    return model ;

    }


QSqlQueryModel * MATERIEL::etatregler()
{
    QSqlQueryModel * model= new QSqlQueryModel();
//cout <<"le produit est regler"<<endl;
    model->setQuery("SELECT * FROM MATERIEL where (panne=2)" );

model->setHeaderData(0, Qt::Horizontal,QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("categorie"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("prix"));

return model ;

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

q1.prepare("SELECT * FROM MATERIEL");
q1.exec();

q2.prepare("SELECT * FROM MATERIEL where(prix<100)");
q2.exec();

q3.prepare("SELECT * FROM MATERIEL WHERE (prix>100)");
q3.exec();



while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}

c1=c1/tot;
c2=c2/tot;


// Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("prix inf 100");
        QBarSet *set1 = new QBarSet("prix sup 100");


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
chartView->setMinimumSize(500,500);

chartView->show();
}

//pie chart
    void stat_combo::choix_pie()
    {
    QSqlQuery q1,q2,q3;
    qreal tot=0,c1=0,c2=0;

    q1.prepare("SELECT * FROM MATERIEL");
    q1.exec();

    q2.prepare("SELECT * FROM MATERIEL where(prix<100)");
    q2.exec();

    q3.prepare("SELECT * FROM MATERIEL WHERE (prix>100)");
    q3.exec();
    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}

    c1=c1/tot;
    c2=c2/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("prix inf 100",c1);
    series->append("prix sup 100",c2);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(500,500);

    chartView->show();
    }











