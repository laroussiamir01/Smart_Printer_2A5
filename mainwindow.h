#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<achat.h>
#include <QMainWindow>
#include <materiel.h>
#include <arduino.h>
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

    void on_pushButton_clicked();
    void notif();

private:
    Ui::MainWindow *ui;
    MATERIEL M;
    ACHAT A;
    QByteArray data;
    Arduino a;

};
#endif // MAINWINDOW_H
