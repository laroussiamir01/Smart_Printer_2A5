#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include "reclamation.h"
#include "arduino.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//-------------menu-------------------------------------------
    void on_pushButton_client_clicked();

    void on_pushButton_personel_clicked();

//----------client----------------------------------------------------
    void on_ajouter_client_clicked();
    void on_ajouter_r_clicked();

    void on_afficher_client_clicked();
    void on_afficher_r_clicked();

    void on_supprimer_client_clicked();
    void on_supprimer_r_clicked();

    void on_modifier_client_clicked();
    void on_modifier_r_clicked();

    void on_generer_clicked();
     void on_generer_1_clicked();

    void on_radioButton_TRInProd_client_clicked();

    void on_radioButton_TRInProdPrix_client_clicked();

    void on_rechercher_client_clicked();

    void on_ProduitNom_rechecher_client_textChanged(const QString &arg1);

    void on_pushButton_stat_client_clicked();

    void on_enregister_fidele_clicked();


    void on_pushButton_arduino_on_clicked();

    void on_pushButton_arduino_off_clicked();
    void update_label();











     //-----------------------------------------------------------------





private:
    Ui::MainWindow *ui;
    client tmpclient;
    client tmpfidele;
    reclamation tmpreclamation;
    Arduino A;
    QByteArray data; //variable contenant les donnes


};
#endif // MAINWINDOW_H
