/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidge;
    QWidget *tab;
    QLabel *label;
    QLineEdit *le_id;
    QPushButton *pb_ajout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *le_nom;
    QLineEdit *le_cat;
    QLabel *label_23;
    QLineEdit *le_prix;
    QWidget *tab_2;
    QLabel *label_4;
    QLineEdit *le_id_supp;
    QPushButton *pb_supprimer;
    QWidget *tab_9;
    QTableView *tablemateriel;
    QWidget *tab_3;
    QPushButton *pb_modifier;
    QLabel *label_6;
    QLineEdit *le_id_3;
    QLineEdit *le_nom_3;
    QLabel *label_7;
    QLabel *label_21;
    QLineEdit *le_cat_3;
    QLabel *label_45;
    QLineEdit *le_prix_3;
    QWidget *tab_4;
    QPushButton *pb_trier;
    QPushButton *pb_tri_nom;
    QPushButton *pb_tri_cat;
    QPushButton *pb_tri_prix;
    QPushButton *pb_tri_prix_desc;
    QTableView *tabletri;
    QWidget *tab_5;
    QPushButton *pb_recherche;
    QLabel *label_12;
    QLineEdit *id_rech;
    QLabel *label_18;
    QLineEdit *nom_rech;
    QTableView *tablerech;
    QPushButton *pb_recherche_2;
    QWidget *tab_6;
    QPushButton *pb_stat;
    QWidget *tab_7;
    QTableView *tabmain;
    QPushButton *pb_traitement;
    QPushButton *pb_regler;
    QPushButton *pb_panne;
    QWidget *tab_8;

    QLabel *nomachat;
    QLineEdit *nom_achat;
    QLabel *prixachat;
    QLineEdit *prix_achat;
    QLabel *date;
    QDateEdit *dateEdit;
    QPushButton *pb_achat;
    QLineEdit *nb_achat;
    QLabel *nbachat;
    QStatusBar *statusbar;

    QLineEdit *le_etat;
    QLabel *label_25;

    QTableView *tabachat;



    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(623, 432);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidge = new QTabWidget(centralwidget);
        tabWidge->setObjectName(QStringLiteral("tabWidge"));
        tabWidge->setGeometry(QRect(0, 0, 631, 441));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 70, 31, 16));
        le_id = new QLineEdit(tab);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(120, 70, 113, 20));
        label_25 = new QLabel(tab);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(70, 300, 31, 16));
        le_etat= new QLineEdit(tab);
        le_etat->setObjectName(QStringLiteral("le_etat"));
        le_etat->setGeometry(QRect(120, 300, 113, 20));

        pb_ajout = new QPushButton(tab);
        pb_ajout->setObjectName(QStringLiteral("pb_ajout"));
        pb_ajout->setGeometry(QRect(454, 302, 101, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 130, 31, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 184, 47, 20));
        le_nom = new QLineEdit(tab);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(120, 130, 113, 20));
        le_cat = new QLineEdit(tab);
        le_cat->setObjectName(QStringLiteral("le_cat"));
        le_cat->setGeometry(QRect(120, 190, 113, 20));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(70, 250, 47, 14));
        le_prix = new QLineEdit(tab);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(120, 250, 113, 20));
        tabWidge->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 60, 47, 14));
        le_id_supp = new QLineEdit(tab_2);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(130, 60, 113, 20));
        pb_supprimer = new QPushButton(tab_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(290, 200, 101, 41));
        tabWidge->addTab(tab_2, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        tablemateriel = new QTableView(tab_9);
        tablemateriel->setObjectName(QStringLiteral("tablemateriel"));
        tablemateriel->setGeometry(QRect(30, 30, 511, 291));
        tabWidge->addTab(tab_9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pb_modifier = new QPushButton(tab_3);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(464, 302, 101, 41));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 60, 47, 14));

        le_id_3 = new QLineEdit(tab_3);
        le_id_3->setObjectName(QStringLiteral("le_id_3"));
        le_id_3->setGeometry(QRect(150, 60, 113, 20));

        le_nom_3 = new QLineEdit(tab_3);
        le_nom_3->setObjectName(QStringLiteral("le_nom_3"));
        le_nom_3->setGeometry(QRect(150, 140, 113, 20));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 144, 51, 20));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 210, 51, 20));
        le_cat_3 = new QLineEdit(tab_3);
        le_cat_3->setObjectName(QStringLiteral("le_cat_3"));
        le_cat_3->setGeometry(QRect(150, 210, 113, 20));
        label_45 = new QLabel(tab_3);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(80, 270, 51, 20));
        le_prix_3 = new QLineEdit(tab_3);
        le_prix_3->setObjectName(QStringLiteral("le_prix_3"));
        le_prix_3->setGeometry(QRect(150, 270, 113, 20));
        tabWidge->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pb_trier = new QPushButton(tab_4);
        pb_trier->setObjectName(QStringLiteral("pb_trier"));
        pb_trier->setGeometry(QRect(40, 70, 91, 41));
        pb_tri_nom = new QPushButton(tab_4);
        pb_tri_nom->setObjectName(QStringLiteral("pb_tri_nom"));
        pb_tri_nom->setGeometry(QRect(210, 70, 75, 41));
        pb_tri_cat = new QPushButton(tab_4);
        pb_tri_cat->setObjectName(QStringLiteral("pb_tri_cat"));
        pb_tri_cat->setGeometry(QRect(350, 70, 75, 41));
        pb_tri_prix = new QPushButton(tab_4);
        pb_tri_prix->setObjectName(QStringLiteral("pb_tri_prix"));
        pb_tri_prix->setGeometry(QRect(490, 130, 75, 41));
        pb_tri_prix_desc = new QPushButton(tab_4);
        pb_tri_prix_desc->setObjectName(QStringLiteral("pb_tri_prix_desc"));
        pb_tri_prix_desc->setGeometry(QRect(490, 200, 75, 41));
        tabletri = new QTableView(tab_4);
        tabletri->setObjectName(QStringLiteral("tabletri"));
        tabletri->setGeometry(QRect(40, 130, 421, 241));
        tabWidge->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        pb_recherche = new QPushButton(tab_5);
        pb_recherche->setObjectName(QStringLiteral("pb_recherche"));
        pb_recherche->setGeometry(QRect(120, 100, 101, 41));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 70, 47, 14));
        id_rech = new QLineEdit(tab_5);
        id_rech->setObjectName(QStringLiteral("id_rech"));
        id_rech->setGeometry(QRect(110, 70, 113, 20));
        label_18 = new QLabel(tab_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(300, 70, 47, 14));
        nom_rech = new QLineEdit(tab_5);
        nom_rech->setObjectName(QStringLiteral("nom_rech"));
        nom_rech->setGeometry(QRect(360, 70, 113, 20));
        tablerech = new QTableView(tab_5);
        tablerech->setObjectName(QStringLiteral("tablerech"));
        tablerech->setGeometry(QRect(20, 160, 421, 211));
        pb_recherche_2 = new QPushButton(tab_5);
        pb_recherche_2->setObjectName(QStringLiteral("pb_recherche_2"));
        pb_recherche_2->setGeometry(QRect(370, 100, 101, 41));
        tabWidge->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        pb_stat = new QPushButton(tab_6);
        pb_stat->setObjectName(QStringLiteral("pb_stat"));
        pb_stat->setGeometry(QRect(500, 340, 101, 41));
        tabWidge->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabmain = new QTableView(tab_7);
        tabmain->setObjectName(QStringLiteral("tabmain"));
        tabmain->setGeometry(QRect(10, 40, 441, 291));
        pb_traitement = new QPushButton(tab_7);
        pb_traitement->setObjectName(QStringLiteral("pb_traitement"));
        pb_traitement->setGeometry(QRect(490, 150, 101, 41));
        pb_regler = new QPushButton(tab_7);
        pb_regler->setObjectName(QStringLiteral("pb_regler"));
        pb_regler->setGeometry(QRect(490, 230, 101, 41));
        pb_panne = new QPushButton(tab_7);
        pb_panne->setObjectName(QStringLiteral("pb_panne"));
        pb_panne->setGeometry(QRect(490, 80, 101, 41));
        tabWidge->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));

        nomachat = new QLabel(tab_8);
        nomachat->setObjectName(QStringLiteral("nomachat"));
        nomachat->setGeometry(QRect(10, 60, 47, 14));
        nom_achat = new QLineEdit(tab_8);
        nom_achat->setObjectName(QStringLiteral("nom_achat"));
        nom_achat->setGeometry(QRect(50, 60, 113, 20));
        prixachat = new QLabel(tab_8);
        prixachat->setObjectName(QStringLiteral("prixachat"));
        prixachat->setGeometry(QRect(10, 120, 47, 14));
        prix_achat = new QLineEdit(tab_8);
        prix_achat->setObjectName(QStringLiteral("prix_achat"));
        prix_achat->setGeometry(QRect(50, 120, 113, 20));
        date = new QLabel(tab_8);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(10, 220, 47, 14));
        dateEdit = new QDateEdit(tab_8);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(50, 220, 110, 22));
        pb_achat = new QPushButton(tab_8);
        pb_achat->setObjectName(QStringLiteral("pb_achat"));
        pb_achat->setGeometry(QRect(60, 320, 75, 23));
        tabachat = new QTableView(tab_8);
        tabachat->setObjectName(QStringLiteral("tabachat"));
        tabachat->setGeometry(QRect(170, 30, 441, 291));
        nb_achat = new QLineEdit(tab_8);
        nb_achat->setObjectName(QStringLiteral("nb_achat"));
        nb_achat->setGeometry(QRect(50, 170, 113, 20));
        nbachat = new QLabel(tab_8);
        nbachat->setObjectName(QStringLiteral("nbachat"));
        nbachat->setGeometry(QRect(10, 170, 47, 14));
        tabWidge->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidge->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        pb_ajout->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Categorie", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "panne", Q_NULLPTR));

        tabWidge->setTabText(tabWidge->indexOf(tab), QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_2), QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_9), QApplication::translate("MainWindow", "affichage", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Categortie", Q_NULLPTR));
        label_45->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));

        tabWidge->setTabText(tabWidge->indexOf(tab_3), QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        pb_trier->setText(QApplication::translate("MainWindow", "Tri id", Q_NULLPTR));
        pb_tri_nom->setText(QApplication::translate("MainWindow", "tri nom", Q_NULLPTR));
        pb_tri_cat->setText(QApplication::translate("MainWindow", "tri categorie", Q_NULLPTR));
        pb_tri_prix->setText(QApplication::translate("MainWindow", "tri prix", Q_NULLPTR));
        pb_tri_prix_desc->setText(QApplication::translate("MainWindow", "tri prix desc", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_4), QApplication::translate("MainWindow", "tri", Q_NULLPTR));
        pb_recherche->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        pb_recherche_2->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_5), QApplication::translate("MainWindow", "recherche", Q_NULLPTR));
        pb_stat->setText(QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_6), QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        pb_traitement->setText(QApplication::translate("MainWindow", "traitement", Q_NULLPTR));
        pb_regler->setText(QApplication::translate("MainWindow", "regler", Q_NULLPTR));
        pb_panne->setText(QApplication::translate("MainWindow", "panne", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_7), QApplication::translate("MainWindow", "maintenance", Q_NULLPTR));
        nomachat->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        prixachat->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        date->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        pb_achat->setText(QApplication::translate("MainWindow", "Confirmer", Q_NULLPTR));
        nbachat->setText(QApplication::translate("MainWindow", "nombre", Q_NULLPTR));
        tabWidge->setTabText(tabWidge->indexOf(tab_8), QApplication::translate("MainWindow", "Achat", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
