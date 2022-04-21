#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
}

interface::~interface()
{
    delete ui;
}
