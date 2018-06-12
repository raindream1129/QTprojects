#ifndef TOTALIZER_H
#define TOTALIZER_H

#include <QDialog>

namespace Ui {
class totalizer;
}

class totalizer : public QDialog
{
    Q_OBJECT

public:
    explicit totalizer(QWidget *parent = 0);
    ~totalizer();

private:
    Ui::totalizer *ui;
};

#endif // TOTALIZER_H
