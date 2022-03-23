#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "reclamation.h"
#include "recherche_client.h"
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
    void on_ajouter_clicked();
    void on_ajouter_r_clicked();


    void on_afficher_clicked();
    void on_afficher_r_clicked();

    void on_supprimer_clicked();
     void on_supprimer_r_clicked();

    void on_modifier_clicked();
    void on_modifier_r_clicked();

    void on_generer_clicked();
    void on_generer1_clicked();



private:
    Ui::MainWindow *ui;
    client tmpclient;
    reclamation tmpreclamation;
     RechercheClient *rechercheclient;
};
#endif // MAINWINDOW_H





