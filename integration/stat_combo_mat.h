#ifndef STAT_COMBO_MAT_H
#define STAT_COMBO_MAT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_combo_mat;
}

class stat_combo_mat : public QDialog
{
    Q_OBJECT

public:
    explicit stat_combo_mat(QWidget *parent = nullptr);
    ~stat_combo_mat();
    QChartView *chartView_mat ;
    void choix_bar_mat();
    void choix_pie_mat();

private:
    Ui::stat_combo_mat *ui;
};

#endif // STAT_COMBO_MAT_H

