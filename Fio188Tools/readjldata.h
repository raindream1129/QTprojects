#ifndef READDJDATA_H
#define READDJDATA_H
#include <QWidget>

namespace Ui {
class ReadJLdata;
}

class ReadJLdata : public QWidget
{
    Q_OBJECT

public:
    explicit ReadJLdata(QWidget *parent = 0);
    ~ReadJLdata();

private slots:

    void PrintData(QString);

private:
    Ui::ReadJLdata *ui;
};
#endif // READDJDATA_H
