#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "Personnel.h"

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

private:
    Ui::MainWindow *ui;
    Personnel tmpPersonnel;
};
#endif // MAINWINDOW_H
