#include "client.h"
#include"stat_combo.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"ui_stat_combo.h"
using namespace std;

client::client()
{
    id=0;
    nom="";
    prenom="";
    //fidele=0;
}


client::client(int cin,QString nom,QString prenom)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}

client::client(int id,QString nom,QString prenom,int cin,QString reclamation,int fidele )
{
    this->id=id;
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
     // this->fidele=fidele;
     this->reclamation=reclamation;

}


bool client::ajouterClient()
{
    QSqlQuery query;
    QString res = QString::number(cin);
    int fidele=0;
    //prepare() prend la requete en parametre pour la preparer a l'exécution.
    query.prepare("insert into client (cin, nom, prenom,fidele)" "values (:cin, :nom, :prenom,:fidele)");
    //creation des variable liées
    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":fidele",fidele);
    return query.exec(); //evoie la reqete pour l'execution

}

QSqlQueryModel * client::afficherClient()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("RECLAMATION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("FIDELE"));

      return model;

}

bool client::supprimerClient(int cin)
{
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("Delete from client where cin= :cin");
    query.bindValue(":cin",res);
    return query.exec();
}

bool client::modifierClient(QString nom, QString prenom , int cin)
{
    QSqlQuery query;
            query.prepare("update client set nom=:nom,prenom=:prenom where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
            return    query.exec();

}

QSqlQueryModel * client::recherche(const QString &nom)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client where (nom LIKE '"+nom+"%') ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QTE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("OFFRE"));
return model;
}

QSqlQueryModel * client::triParNom()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client order by nom asc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("RECLAMATION"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("FIDELE"));

return model;
}

QSqlQueryModel * client::triParQte()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,cin,reclamationn,fidele from client order by fidele desc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("RECLAMATION"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("FIDELE"));


return model;
}



bool client::modifierFidele(int cin, int fidele)
{
    QSqlQuery query;

            query.prepare("update client set fidele=:fidele where cin=:cin");
            query.bindValue(":cin",cin);
             query.bindValue(":fidele",fidele);

            return    query.exec();

}


bool client::PromotionPrix()
{
    QSqlQuery query;
            query.prepare("update client set classement=1,fidele=fidele+200  where classement=1");
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
QSqlQuery q1,q2,q3,q4;
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM client");
q1.exec();

q2.prepare("SELECT * FROM client where(fidele=-1)");
q2.exec();

q3.prepare("SELECT * FROM client WHERE (fidele>=500)");
q3.exec();

q4.prepare("SELECT * FROM client WHERE (fidele<500) ");
q4.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}

c1=c1/tot;
c2=c2/tot;
c3=c3/tot;


// Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("fidele=-1");
        QBarSet *set1 = new QBarSet("fidele>=500");
        QBarSet *set2 = new QBarSet("fidele<500");

        // Assign values for each bar
        *set0 << c1;
        *set1 << c2;
        *set2 << c3;


        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        series->append(set0);
        series->append(set1);
        series->append(set2);


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
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM client");
    q1.exec();

    q2.prepare("SELECT * FROM client where(fidele=-1)");
    q2.exec();

    q3.prepare("SELECT * FROM client WHERE (fidele>=500)");
    q3.exec();

    q4.prepare("SELECT * FROM client WHERE (fidele<500) ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("fidele=-1",c1);
    series->append("fidele>=500",c2);
    series->append("fidele<500",c3);




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
