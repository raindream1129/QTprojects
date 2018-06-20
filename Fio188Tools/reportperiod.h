#ifndef REPORTPERIOD_H
#define REPORTPERIOD_H

#include <QWidget>
#include "cjt188_general.h"
namespace Ui {
class ReportPeriod;
}

class ReportPeriod : public QWidget
{
    Q_OBJECT

public:
    explicit ReportPeriod(QWidget *parent = 0);
    ~ReportPeriod();

private:
    Ui::ReportPeriod *ui;

    QTimer     *Timer;

    int i;

signals:
    void RepPd(QString);

    void RepTimeSet(CJT188Obj);

private slots:

    void ReadRPPd(quint32,QString);

    void on_ACC_SAMP_BTN_clicked();
    void on_PushByNetBTN_clicked();
    //void on_TMP_SAMP_BTN_clicked();
};

#endif // REPORTPERIOD_H
