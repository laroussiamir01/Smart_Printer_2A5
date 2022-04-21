#ifndef INTERFACE_H
#define INTERFACE_H

#include <QDialog>

namespace Ui {
class interface;
}

class interface : public QDialog
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = nullptr);
    ~interface();

private:
    Ui::interface *ui;
};

#endif // INTERFACE_H
