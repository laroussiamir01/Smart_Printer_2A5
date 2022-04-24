#ifndef STAT_COMBO_COM_H
#define STAT_COMBO_COM_H

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
class stat_combo_com;
}

class stat_combo_com : public QDialog
{
    Q_OBJECT

public:
    explicit stat_combo_com(QWidget *parent = nullptr);
    ~stat_combo_com();
    QChartView *chartView_com ;
    void choix_bar_com();
    void choix_pie_com();

private:
    Ui::stat_combo_com *ui;
};

#endif // STAT_COMBO_COM_H
