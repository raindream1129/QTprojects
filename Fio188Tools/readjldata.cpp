#include "readjldata.h"
#include "ui_readjldata.h"
#include <QDateTime>
#include "common.h"

ReadJLdata::ReadJLdata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadJLdata)
{
    ui->setupUi(this);
}

ReadJLdata::~ReadJLdata()
{
    delete ui;
}


void ReadJLdata::PrintData(QString value)
{
    QString Time_T = value.mid(0,8);
    QString Tot = value.mid(8,8);
    QString ST = value.mid(16,8);
    QString Tmp = value.mid(24,4);

    QDateTime time = QDateTime::fromTime_t(Time_T.toInt());
    QString Time_Now = time.toString("yyyy-MM-dd HH:mm:ss");
    QString Totol_flow = QString::number(Tot.toDouble()/10);
    QString ST_Meter = SystemState(ST.toInt());
    QString Tmpr = QString::number(Tmp.toDouble()/10);

    ui->TimeLineE->setText(Time_Now);
    ui->CurrentTotalFlowLineE->setText(Totol_flow);
    ui->SYSState->setText(ST_Meter);
    ui->TMP_LE->setText(Tmpr);

}
