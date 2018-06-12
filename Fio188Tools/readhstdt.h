#ifndef READHSTDT_H
#define READHSTDT_H

#include <QWidget>
#include "cjt188_fio.h"
#include "cjt188_general.h"

namespace Ui {
class ReadHstDt;
}

class ReadHstDt : public QWidget
{
    Q_OBJECT

public:
    explicit ReadHstDt(QWidget *parent = 0);
    ~ReadHstDt();
private:


private slots:

    //void on_ReadHst_clicked();

    void on_MonthBtn_clicked();

    void on_DateBtn_clicked();

    void on_TimeBtn_clicked();

    void ReadHstDtResponse(CJT188Obj);

signals:

    void ReadHistDt(CJT188Obj);

private:
    Ui::ReadHstDt *ui;
    QTimer     *Timer;
    int i;
public:

    void ReadHistoryDataMonth(QString);

    void ReadHistoryDataDate(QString);

    void ReadHistoryDataTime(QString);

};

#endif // READHSTDT_H
