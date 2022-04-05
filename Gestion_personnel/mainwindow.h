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
    void on_ajouter_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

void on_rechercher_clicked();

void on_pushButton_TriASC_clicked();

void on_pushButton_TriDESC_clicked();
void on_ajouter_prime_clicked();

void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    Personnel tmpPersonnel;
};
#endif // MAINWINDOW_H
