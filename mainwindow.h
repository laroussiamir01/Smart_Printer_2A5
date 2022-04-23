#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "service.h"

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
    //---------------service-----------------------------------
    void on_ajouter_service_clicked();



    void on_afficher_service_clicked();


    void on_supprimer_service_clicked();


    void on_modifier_service_clicked();




    void on_radioButton_TRInProd_service_clicked();

    void on_radioButton_TRInProdPrix_service_clicked();

    void on_rechercher_service_clicked();

    void on_ProduitNom_rechecher_service_textChanged(const QString &arg1);

    void on_tabWidget_service_currentChanged(int index);
    //----------------------------------------------------------------

private:
    Ui::MainWindow *ui;
    service tmpservice;

};
#endif // MAINWINDOW_H





