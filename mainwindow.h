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
    void on_ajouter_clicked();



    void on_afficher_clicked();


    void on_supprimer_clicked();


    void on_modifier_clicked();




    void on_radioButton_TRInProd_clicked();

    void on_radioButton_TRInProdPrix_clicked();

    void on_rechercher_clicked();

    void on_ProduitNom_rechecher_textChanged(const QString &arg1);

    void on_tabWidget_2_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    service tmpservice;

};
#endif // MAINWINDOW_H





