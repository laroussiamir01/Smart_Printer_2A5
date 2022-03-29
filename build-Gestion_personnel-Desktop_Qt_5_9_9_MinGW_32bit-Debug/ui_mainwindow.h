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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QTabWidget *tabAjouter;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditCin;
    QLineEdit *lineEdit_pren;
    QLineEdit *lineEdit_nom;
    QPushButton *ajouter;
    QPushButton *quitter_ajout;
    QLabel *label_12;
    QLabel *label_8;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QPushButton *afficher;
    QTableView *tableView;
    QLabel *label_9;
    QLabel *label_13;
    QWidget *tab_5;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditCin_modif;
    QLineEdit *lineEdit_pren_modif;
    QLineEdit *lineEdit_nom_modif;
    QPushButton *modifier;
    QLabel *label_11;
    QLabel *label_14;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLineEdit *lineEditCin_supp;
    QPushButton *supprimer;
    QLabel *label_10;
    QLabel *label_15;
    QWidget *tab_7;
    QPushButton *rechercher;
    QTableView *tableView_rechercher;
    QLineEdit *lineEdit_rechercher;
    QWidget *tab_4;
    QGroupBox *groupBox_5;
    QTableView *tableView_tri;
    QPushButton *pushButton_TriASC;
    QPushButton *pushButton_TriDESC;
    QPushButton *pushButton_3;
    QWidget *tab_6;
    QWidget *tab_8;
    QWidget *tab_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabAjouter = new QTabWidget(centralwidget);
        tabAjouter->setObjectName(QStringLiteral("tabAjouter"));
        tabAjouter->setGeometry(QRect(60, 60, 661, 421));
        tabAjouter->setStyleSheet(QLatin1String("font: 75 8pt \"Segoe Print\";\n"
"gridline-color: rgb(0, 255, 127);\n"
"color: rgb(68, 202, 255);"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 631, 301));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 110, 56, 16));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Print"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 150, 56, 16));
        label_2->setFont(font);
        label_2->setWordWrap(false);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 190, 56, 16));
        lineEditCin = new QLineEdit(groupBox);
        lineEditCin->setObjectName(QStringLiteral("lineEditCin"));
        lineEditCin->setGeometry(QRect(170, 110, 113, 22));
        lineEditCin->setMaxLength(8);
        lineEdit_pren = new QLineEdit(groupBox);
        lineEdit_pren->setObjectName(QStringLiteral("lineEdit_pren"));
        lineEdit_pren->setGeometry(QRect(170, 150, 113, 22));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(170, 190, 113, 22));
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(290, 240, 93, 28));
        ajouter->setStyleSheet(QLatin1String("selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255));"));
        ajouter->setFlat(false);
        quitter_ajout = new QPushButton(groupBox);
        quitter_ajout->setObjectName(QStringLiteral("quitter_ajout"));
        quitter_ajout->setGeometry(QRect(400, 240, 93, 28));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(-14, -6, 741, 411));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/minimalism-colorful-beehive-patterns-texture-wallpaper-preview.jpg")));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(true);
        label_8->setGeometry(QRect(-210, 320, 931, 451));
        label_8->setAutoFillBackground(false);
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/272913746_990774311522570_960516843833593149_n.jpg")));
        tabAjouter->addTab(tab_2, QString());
        label_12->raise();
        groupBox->raise();
        label_8->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 40, 591, 301));
        afficher = new QPushButton(groupBox_4);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(400, 250, 93, 28));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 40, 501, 192));
        tableView->setStyleSheet(QStringLiteral("color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 0, 0, 255), stop:0.339795 rgba(255, 0, 0, 255), stop:0.339799 rgba(255, 255, 255, 255), stop:0.662444 rgba(255, 255, 255, 255), stop:0.662469 rgba(0, 0, 255, 255), stop:1 rgba(0, 0, 255, 255));"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(true);
        label_9->setGeometry(QRect(-120, -130, 1371, 611));
        label_9->setAutoFillBackground(false);
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/272913746_990774311522570_960516843833593149_n.jpg")));
        label_9->raise();
        afficher->raise();
        tableView->raise();
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(-70, -100, 831, 571));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/minimalism-colorful-beehive-patterns-texture-wallpaper-preview.jpg")));
        tabAjouter->addTab(tab, QString());
        label_13->raise();
        groupBox_4->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 30, 591, 301));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 110, 56, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 150, 56, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 190, 56, 16));
        lineEditCin_modif = new QLineEdit(groupBox_2);
        lineEditCin_modif->setObjectName(QStringLiteral("lineEditCin_modif"));
        lineEditCin_modif->setGeometry(QRect(170, 110, 113, 22));
        lineEditCin_modif->setMaxLength(8);
        lineEdit_pren_modif = new QLineEdit(groupBox_2);
        lineEdit_pren_modif->setObjectName(QStringLiteral("lineEdit_pren_modif"));
        lineEdit_pren_modif->setGeometry(QRect(170, 150, 113, 22));
        lineEdit_nom_modif = new QLineEdit(groupBox_2);
        lineEdit_nom_modif->setObjectName(QStringLiteral("lineEdit_nom_modif"));
        lineEdit_nom_modif->setGeometry(QRect(170, 190, 113, 22));
        modifier = new QPushButton(groupBox_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(470, 260, 93, 28));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setEnabled(true);
        label_11->setGeometry(QRect(170, -420, 1171, 551));
        label_11->setAutoFillBackground(false);
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/272913746_990774311522570_960516843833593149_n.jpg")));
        label_11->setTextInteractionFlags(Qt::NoTextInteraction);
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(-40, -160, 1171, 711));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/minimalism-colorful-beehive-patterns-texture-wallpaper-preview.jpg")));
        tabAjouter->addTab(tab_5, QString());
        label_14->raise();
        groupBox_2->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 40, 591, 301));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 160, 56, 16));
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEditCin_supp = new QLineEdit(groupBox_3);
        lineEditCin_supp->setObjectName(QStringLiteral("lineEditCin_supp"));
        lineEditCin_supp->setGeometry(QRect(210, 160, 113, 22));
        lineEditCin_supp->setMaxLength(8);
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(450, 260, 93, 28));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe Print"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        font1.setStrikeOut(false);
        supprimer->setFont(font1);
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);
        label_10->setGeometry(QRect(-80, 20, 1221, 471));
        label_10->setAutoFillBackground(false);
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/272913746_990774311522570_960516843833593149_n.jpg")));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(-10, -20, 741, 411));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/minimalism-colorful-beehive-patterns-texture-wallpaper-preview.jpg")));
        tabAjouter->addTab(tab_3, QString());
        label_15->raise();
        label_10->raise();
        groupBox_3->raise();
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        rechercher = new QPushButton(tab_7);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(310, 60, 93, 31));
        tableView_rechercher = new QTableView(tab_7);
        tableView_rechercher->setObjectName(QStringLiteral("tableView_rechercher"));
        tableView_rechercher->setGeometry(QRect(110, 120, 451, 192));
        lineEdit_rechercher = new QLineEdit(tab_7);
        lineEdit_rechercher->setObjectName(QStringLiteral("lineEdit_rechercher"));
        lineEdit_rechercher->setGeometry(QRect(130, 60, 141, 31));
        tabAjouter->addTab(tab_7, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 30, 601, 331));
        tableView_tri = new QTableView(groupBox_5);
        tableView_tri->setObjectName(QStringLiteral("tableView_tri"));
        tableView_tri->setGeometry(QRect(20, 30, 461, 241));
        pushButton_TriASC = new QPushButton(groupBox_5);
        pushButton_TriASC->setObjectName(QStringLiteral("pushButton_TriASC"));
        pushButton_TriASC->setGeometry(QRect(490, 50, 93, 28));
        pushButton_TriDESC = new QPushButton(groupBox_5);
        pushButton_TriDESC->setObjectName(QStringLiteral("pushButton_TriDESC"));
        pushButton_TriDESC->setGeometry(QRect(490, 130, 93, 28));
        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 220, 93, 28));
        tabAjouter->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabAjouter->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabAjouter->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        tabAjouter->addTab(tab_9, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabAjouter->setCurrentIndex(5);
        ajouter->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        quitter_ajout->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        label_12->setText(QString());
        label_8->setText(QString());
        tabAjouter->setTabText(tabAjouter->indexOf(tab_2), QApplication::translate("MainWindow", "ADD", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        afficher->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        label_9->setText(QString());
        label_13->setText(QString());
        tabAjouter->setTabText(tabAjouter->indexOf(tab), QApplication::translate("MainWindow", "DISPLAY", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_11->setText(QString());
        label_14->setText(QString());
        tabAjouter->setTabText(tabAjouter->indexOf(tab_5), QApplication::translate("MainWindow", "UPDATE", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        lineEditCin_supp->setText(QString());
        supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_10->setText(QString());
        label_15->setText(QString());
        tabAjouter->setTabText(tabAjouter->indexOf(tab_3), QApplication::translate("MainWindow", "DELETE", Q_NULLPTR));
        rechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_7), QApplication::translate("MainWindow", "RECHERCHE", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        pushButton_TriASC->setText(QApplication::translate("MainWindow", "Tri ASC", Q_NULLPTR));
        pushButton_TriDESC->setText(QApplication::translate("MainWindow", "Tri DESC", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_4), QApplication::translate("MainWindow", "TRIE", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_6), QApplication::translate("MainWindow", "STAT", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_8), QApplication::translate("MainWindow", "CONGE", Q_NULLPTR));
        tabAjouter->setTabText(tabAjouter->indexOf(tab_9), QApplication::translate("MainWindow", "PRIME DE RENDEMENT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
