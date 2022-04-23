#ifndef STAT_COMBO_PERSO_H
#define STAT_COMBO_PERSO_H

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
class stat_combo_perso;
}

class stat_combo_perso : public QDialog
{
    Q_OBJECT

public:
    explicit stat_combo_perso(QWidget *parent = nullptr);
    ~stat_combo_perso();
  QChartView *chartView_perso ;
    void choix_bar_perso();
    void choix_pie_perso();

private:
    Ui::stat_combo_perso *ui;
};

#endif // STAT_COMBO_PERSO_H
