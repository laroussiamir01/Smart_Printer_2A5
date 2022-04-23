#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include "reclamation.h"
#include "achat.h"
#include "materiel.h"
#include "arduino.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

#include "personnel.h"
#include "service.h"

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

    void on_pushButton_service_clicked();
    void on_pushButton_materiel_clicked();

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
//--------------------------------personnel----------------------------------------
    void on_ajouterperso_clicked();

    void on_afficherperso_clicked();

    void on_supprimerperso_clicked();

    void on_modifierperso_clicked();

void on_rechercherperso_clicked();

void on_pushButton_TriASCperso_clicked();

void on_pushButton_TriDESCperso_clicked();
void on_ajouter_primeperso_clicked();

void on_pushButtonperso_clicked();

void on_pushButton_2perso_clicked();
    //---------------------------------------------------------------------------

//---------------service-----------------------------------
void on_ajouter_service_clicked();



void on_afficher_service_clicked();


void on_supprimer_service_clicked();


void on_modifier_service_clicked();




void on_radioButton_TRInProd_service_clicked();

void on_radioButton_TRInProdPrix_service_clicked();

void on_rechercher_service_clicked();

void on_ProduitNom_rechecher_ser_textChanged(const QString &arg1);

void on_tabWidget_service_currentChanged(int index);
//----------------------------------------------------------------


//----------------------materiel----------------------------------------
void on_pb_supprimer_clicked();

void on_pb_ajout_clicked();

void on_pb_modifier_clicked();


void on_pb_trier_clicked();

void on_pb_tri_nom_clicked();

void on_pb_tri_cat_clicked();

void on_pb_tri_prix_clicked();

void on_pb_tri_prix_desc_clicked();

void on_pb_recherche_clicked();

void on_pb_recherche_2_clicked();


void on_pb_stat_clicked();



void on_pb_panne_clicked();

void on_pb_traitement_clicked();

void on_pb_regler_clicked();

void on_pb_achat_clicked();






private:
    Ui::MainWindow *ui;
    client tmpclient;
    Personnel tmpPersonnel;
    client tmpfidele;
    reclamation tmpreclamation;
     service tmpservice;
    Arduino A;
    QByteArray data; //variable contenant les donnes
    MATERIEL M;
    ACHAT a;


};
#endif // MAINWINDOW_H
